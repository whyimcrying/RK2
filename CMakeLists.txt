cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Figures)
file(GLOB SOURCES "G34_Non_Owning_Type_Erasure_1.cpp", "Main-2.cpp")
add_executable(Figures1 G34_Non_Owning_Type_Erasure_1.cpp)
add_executable(Figures2 Main-2.cpp)