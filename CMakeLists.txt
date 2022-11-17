cmake_minimum_required(VERSION 3.17)

project("arcade" VERSION 0.0.1 LANGUAGES CXX)

option(SHARED_LIBGCC "Shared Libgcc" ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(./src/Core/)

add_subdirectory(./src/Libs/SFML/)

add_subdirectory(./src/Libs/SDL2/)

add_subdirectory(./src/Libs/NCurses/)

add_subdirectory(./src/Games/Nibbler/)

add_subdirectory(./src/Games/SolarFox/)
