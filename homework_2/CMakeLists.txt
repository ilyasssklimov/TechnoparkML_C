cmake_minimum_required(VERSION 3.13)

project(homework_2)

add_compile_options(-Wall -Wextra -Wpedantic -ldl -fPIC)

option(WITH_TESTS "Build tests")
if (WITH_TESTS)
    enable_testing()
    find_package(GTest REQUIRED)
    set(BUILD_TESTS ON)
endif()

add_subdirectory(lib/my_string)
add_subdirectory(lib/predicate_parser)
add_subdirectory(lib/serial_algorithm)
add_subdirectory(lib/parallel_algorithm)

add_executable(main src/main.c)
target_link_libraries(main my_string)
target_link_libraries(main predicate_parser)
target_link_libraries(main serial_algorithm)
target_link_libraries(main dl)
target_link_libraries(main parallel_algorithm)
