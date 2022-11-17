cmake_minimum_required(VERSION 3.17)

project("arcade_nibbler" VERSION 0.0.1 LANGUAGES CXX)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../lib/game)

set(CMAKE_CXX_STANDARD 20)

add_library(arcade_nibbler SHARED
    ./NibblerFactory.cpp
	./NibblerGame.cpp
	./Map/NibblerMap.cpp
	./Map/NibblerMapCase.cpp
	./Snake/Snake.cpp
	./Snake/SnakeMember.cpp
	../AGame.cpp
    ../../Core/Clock.cpp
	../../Error/ArcadeError.cpp
	../../Error/GameError.cpp
)

set(CXX_FLAGS "-fPIC")

set_target_properties(arcade_nibbler PROPERTIES PREFIX "")

target_include_directories(
    arcade_nibbler
    PRIVATE
    ../../../include/Games/Nibbler/Map/
    ../../../include/Games/Nibbler/Snake/
    ../../../include/Games/Nibbler/
    ../../../include/Games/
    ../../../include/Libs/
    ../../../include/Core/
	../../../include/Error/
)

target_compile_options(
    arcade_nibbler
    PRIVATE
    ${CXX_FLAGS}
)