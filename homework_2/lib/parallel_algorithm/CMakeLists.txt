add_library(parallel_algorithm SHARED src/parallel.c)

target_include_directories(parallel_algorithm PUBLIC include)
target_link_libraries(parallel_algorithm PUBLIC predicate_parser)


if(BUILD_TESTS)
    add_subdirectory(tests)
endif()
