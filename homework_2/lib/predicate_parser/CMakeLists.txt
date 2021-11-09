add_library(predicate_parser STATIC src/parser.c src/operators.c)

target_include_directories(predicate_parser PUBLIC include)
target_link_libraries(predicate_parser PUBLIC my_string)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()
