##
## Copyright (c) 2024 Waldemar Schneider (w-schneider1987 at web dot de)
##
## Distributed under the Boost Software License, Version 1.0.
## (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


add_library(modern_durak_game_option userDefinedGameOption.cxx)


add_library(myproject::modern_durak_game_option ALIAS modern_durak_game_option)

find_package(durak)
find_package(Boost)
find_package(login_matchmaking_game_shared)


target_link_libraries(modern_durak_game_option PUBLIC
        durak::durak
        Boost::headers
        login_matchmaking_game_shared::login_matchmaking_game_shared
        )

target_include_directories(modern_durak_game_option PUBLIC 
PUBLIC
$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>
        )

target_compile_features(modern_durak_game_option PUBLIC cxx_std_20)

install(FILES
        userDefinedGameOption.hxx
        DESTINATION include/modern_durak_game_option
        )
install(TARGETS modern_durak_game_option DESTINATION lib)
