project(hw_1)

cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIB_SOURCE_FILES toys.c)
add_library(toys STATIC ${LIB_SOURCE_FILES})

set(LIB_SOURCE_FILES toy.c)
add_library(toy STATIC ${LIB_SOURCE_FILES})

set(LIB_SOURCE_FILES my_string.c)
add_library(my_string STATIC ${LIB_SOURCE_FILES})

add_executable(main main.c)
target_link_libraries(main toys)
target_link_libraries(toys toy)
target_link_libraries(toys my_string)

enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
add_executable(test_toys test_toys.cpp)
target_link_libraries(test_toys ${GTEST_LIBRARIES} toys)

