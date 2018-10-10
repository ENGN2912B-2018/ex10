cmake_minimum_required (VERSION 3.2)

# compiler settings
set(CMAKE_CXX_COMPILER "g++")

# create the project (must have a name)
project (ex10_templates)

# add compiler flags
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -p -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

include_directories(src)
add_executable(ex10p1 src/main1.cpp)
#add_executable(ex10p2 src/main2.cpp)

