add_executable(test_parallel src/test_parallel.cpp)

target_link_libraries(test_parallel parallel_algorithm
                                    GTest::Main
                                    predicate_parser
                                    dl)
add_test(NAME test_parallel COMMAND test_parallel)
