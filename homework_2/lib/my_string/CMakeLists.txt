add_library(my_string STATIC src/my_string.c)

target_include_directories(my_string PUBLIC include)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()
