add_executable(test_my_string src/test_my_string.cpp)

target_link_libraries(test_my_string my_string
                                     GTest::Main)
add_test(NAME test_my_string COMMAND test_my_string)
