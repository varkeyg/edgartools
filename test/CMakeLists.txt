cmake_minimum_required(VERSION 3.17)
find_package(GTest CONFIG REQUIRED)
add_executable(insider_tests insider_test.cpp)
target_link_libraries(insider_tests PUBLIC GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main common insider)

