#include "gtest/gtest.h"
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include <iostream>
#include <sstream>

struct CircleDrawer {
    void operator()(Circle const& circle) const {
        std::cout << "Drawing circle with radius " << circle.radius() << std::endl;
    }
};

struct SquareDrawer {
    void operator()(Square const& square) const {
        std::cout << "Drawing square with side " << square.side() << std::endl;
    }
};

TEST(CircleTest, RadiusInitialization) {
    Circle circle(5.0);
    EXPECT_DOUBLE_EQ(circle.radius(), 5.0);
}

TEST(SquareTest, SideInitialization) {
    Square square(3.0);
    EXPECT_DOUBLE_EQ(square.side(), 3.0);
}

TEST(ShapeConstRefTest, DrawCircle) {
    Circle circle(5.0);
    CircleDrawer circleDrawer;
    ShapeConstRef shapeRef(circle, circleDrawer);

    std::ostringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    draw(shapeRef);
    std::cout.rdbuf(old);

    EXPECT_EQ(buffer.str(), "Drawing circle with radius 5\n");
}

TEST(ShapeConstRefTest, DrawSquare) {
    Square square(4.0);
    SquareDrawer squareDrawer;
    ShapeConstRef shapeRef(square, squareDrawer);

    std::ostringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    draw(shapeRef);
    std::cout.rdbuf(old);

    EXPECT_EQ(buffer.str(), "Drawing square with side 4\n");
}
