cmake_minimum_required(VERSION 3.17)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../lib/graphic)

set(CMAKE_CXX_STANDARD 20)

project("arcade_sdl2" VERSION 0.0.1 LANGUAGES CXX)

add_library(
    arcade_sdl2
    SHARED
	./SDLDeleters.cpp
    ./SDLFactory.cpp
	./SDLImage.cpp
	./SDLSound.cpp
	./SDLText.cpp
	./SDLWindow.cpp
	./../../Error/ArcadeError.cpp
	./../../Error/GraphicError.cpp
)

set(CXX_FLAGS "-fPIC")

set_target_properties(
    arcade_sdl2 PROPERTIES PREFIX "")

target_include_directories(
    arcade_sdl2
    PRIVATE
    ../../../include/Libs/SDL2/
    ../../../include/Libs/
    ../../../include/Core/
	../../../include/Error/
)

target_link_libraries(
    arcade_sdl2
    PRIVATE
    -lSDL2
    -lSDL2_image
    -lSDL2_ttf
    -lSDL2_mixer
)

target_compile_options(
    arcade_sdl2
    PRIVATE
    ${CXX_FLAGS}
)