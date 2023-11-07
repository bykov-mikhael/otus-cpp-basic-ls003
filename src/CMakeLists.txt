cmake_minimum_required(VERSION 3.5)

project(ls004.src)

set(SOURCES  main.cpp)

set(GAME  game/game.cpp
          game/game.h)

set(USER_INPUT  user_input/user_input.cpp
                user_input/user_input.h)

add_executable(ls004.src    ${SOURCES}
                            ${GAME}
                            ${USER_INPUT})

set_target_properties(ls004.src PROPERTIES  CXX_STANDARD 17
                                            CXX_STANDARD_REQUIRED ON)

