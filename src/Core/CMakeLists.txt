cmake_minimum_required(VERSION 3.17)

project("arcade_core" VERSION 0.0.1 LANGUAGES CXX)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../)

set(CMAKE_CXX_STANDARD 20)

add_executable(arcade
    ./Main.cpp
    ./Clock.cpp
    ./Loader.cpp
    ./Menu.cpp
    ./Jukebox.cpp
    ../Error/ArcadeError.cpp
    ../Error/GraphicError.cpp
    ../Error/GameError.cpp
    ./Player.cpp
)

target_include_directories(
    arcade
    PRIVATE
    ../../include/Core/
    ../../include/Error/
    ../../include/Libs/SFML/
    ../../include/Games/
    ../../include/Libs/
)

target_link_libraries(
    arcade
    PRIVATE
    "-Wl,--no-as-needed -ldl"
)