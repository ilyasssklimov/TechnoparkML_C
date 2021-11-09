add_executable(test_serial src/test_serial.cpp)

target_link_libraries(test_serial serial_algorithm
                                  GTest::Main)
add_test(NAME test_serial COMMAND test_serial)
