add_executable(test_parser src/test_parser.cpp
                           src/test_operators.cpp)

target_link_libraries(test_parser predicate_parser
                                  GTest::Main)
add_test(NAME test_parser COMMAND test_parser)
