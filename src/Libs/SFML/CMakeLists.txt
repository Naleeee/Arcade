cmake_minimum_required(VERSION 3.17)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../lib/graphic)

set(CMAKE_CXX_STANDARD 20)

project("arcade_sfml" VERSION 0.0.1 LANGUAGES CXX)

add_library(
    arcade_sfml
    SHARED
    ./SFMLFactory.cpp
	./SFMLImage.cpp
	./SFMLSound.cpp
	./SFMLText.cpp
	./SFMLWindow.cpp
	./../../Error/ArcadeError.cpp
	./../../Error/GraphicError.cpp
)

set(CXX_FLAGS "-fPIC")

set_target_properties(
    arcade_sfml PROPERTIES PREFIX "")

target_include_directories(
    arcade_sfml
    PRIVATE
    ../../../include/Libs/SFML/
    ../../../include/Libs/
    ../../../include/Core/
	../../../include/Error/
)

target_link_libraries(
    arcade_sfml
    PRIVATE
    -lsfml-graphics
    -lsfml-window
    -lsfml-system
    -lsfml-audio
)

target_compile_options(
    arcade_sfml
    PRIVATE
    ${CXX_FLAGS}
)