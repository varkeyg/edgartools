cmake_minimum_required(VERSION 3.17)
set(lib_name insider)
project(${lib_name})
set(CMAKE_CXX_STANDARD 17)
set(visibility hidden)

include_directories(${CMAKE_SOURCE_DIR}/insider/include)
set(lib_name_sources cpp/insider.cpp)

find_package(CURL CONFIG REQUIRED)
find_package(glog CONFIG REQUIRED)
find_package(tinyxml2 CONFIG REQUIRED)

add_library(${lib_name} STATIC ${lib_name_sources} )
target_link_libraries( ${lib_name} PUBLIC CURL::libcurl  glog::glog tinyxml2::tinyxml2  common)
target_include_directories( ${lib_name} PUBLIC  CURL::libcurl  glog::glog  ${CMAKE_CURRENT_SOURCE_DIR}/include )

