add_executable(_test
        main.cxx
        )
target_link_libraries(_test
        myproject_options
        myproject_warnings
        modern_durak_game_option
        )
target_include_directories(_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR})

add_test(NAME _test
        COMMAND _test -r junit)