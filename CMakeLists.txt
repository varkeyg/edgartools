cmake_minimum_required(VERSION 3.17)
set(project_name edgartools)
project(${project_name})
set(CMAKE_CXX_STANDARD 17)
set(visibility hidden)

find_package(glog CONFIG REQUIRED)

add_subdirectory(main)
add_subdirectory(test)
add_subdirectory(insider)
add_subdirectory(common)

