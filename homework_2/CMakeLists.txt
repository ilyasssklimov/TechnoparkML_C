cmake_minimum_required(VERSION 3.13)

project(homework_2)

add_compile_options(-Wall -Wextra -Wpedantic -fPIC)

option(WITH_TESTS "Build tests")
if (WITH_TESTS)
    enable_testing()
    find_package(GTest REQUIRED)
    set(BUILD_TESTS ON)
endif()

option(WITH_PARALLEL "Use parallel algorithm")

add_subdirectory(lib/my_string)
add_subdirectory(lib/predicate_parser)

if (WITH_PARALLEL)
    add_subdirectory(lib/parallel_algorithm)
    add_compile_definitions(WITH_PARALLEL)
    add_compile_options(-ldl)
else()
    add_subdirectory(lib/serial_algorithm)
endif()


add_executable(main src/main.c)

target_link_libraries(main my_string)
target_link_libraries(main predicate_parser)

if (WITH_PARALLEL)
    target_link_libraries(main dl)
    target_link_libraries(main parallel_algorithm)
else()
    target_link_libraries(main serial_algorithm)
endif()