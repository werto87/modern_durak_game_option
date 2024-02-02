##
## Copyright (c) 2024 Waldemar Schneider (w-schneider1987 at web dot de)
##
## Distributed under the Boost Software License, Version 1.0.
## (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


add_library(modern_durak_game_option INTERFACE)


add_library(myproject::modern_durak_game_option ALIAS modern_durak_game_option)


find_package(durak)
find_package(Boost)

target_link_libraries(modern_durak_game_option INTERFACE
        durak::durak
        Boost::headers
        )

target_include_directories(modern_durak_game_option INTERFACE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>)

target_compile_features(modern_durak_game_option INTERFACE cxx_std_20)

set_target_properties(
        modern_durak_game_option
        PROPERTIES VERSION ${PROJECT_VERSION}
        CXX_VISIBILITY_PRESET hidden
        VISIBILITY_INLINES_HIDDEN YES)

install(FILES
        userDefinedGameOption.hxx
        DESTINATION include/modern_durak_game_option
        )
install(TARGETS modern_durak_game_option DESTINATION lib)
