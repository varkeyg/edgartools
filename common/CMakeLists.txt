cmake_minimum_required(VERSION 3.17)
set(lib_name common)
project(${lib_name})
set(default_build_type "Debug")
set(CMAKE_CXX_STANDARD 17)
set(visibility hidden)



include_directories(${CMAKE_SOURCE_DIR}/common/include)
include_directories()
set(lib_name_sources cpp/common.cpp)

find_package(CURL CONFIG REQUIRED)
find_package(glog CONFIG REQUIRED)
find_path(BOOST_DATE_INCLUDE "boost/date_time/gregorian/gregorian.hpp")
find_path(BOOST_ALGORITHM_INCLUDE_DIRS "boost/algorithm/algorithm.hpp")
find_path(BOOST_FORMAT_INCLUDE_DIRS "boost/format.hpp")


add_library(${lib_name} STATIC ${lib_name_sources} )

target_link_libraries( ${lib_name} PUBLIC 
    CURL::libcurl 
    glog::glog
)

target_include_directories( ${lib_name} PUBLIC 
    CURL::libcurl 
    glog::glog
    ${BOOST_ALGORITHM_INCLUDE_DIRS} 
    ${BOOST_DATE_INCLUDE}     
    ${BOOST_FORMAT_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/include 
    

)

