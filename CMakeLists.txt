cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build tests" OFF)
option(PACK "pack" OFF)

project(Figures)
file(GLOB SOURCES "Main-2.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(third-party/gtest)
  file(GLOB TEST_SOURCES "tests.cpp")
  add_executable(check ${TEST_SOURCES})
  target_link_libraries(check gtest_main)
  add_test(NAME check COMMAND check)
endif()

include(CPack.cmake)