add_library(serial_algorithm STATIC src/serial.c)

target_include_directories(serial_algorithm PUBLIC include)
target_link_libraries(serial_algorithm PUBLIC predicate_parser)


if(BUILD_TESTS)
    add_subdirectory(tests)
endif()
