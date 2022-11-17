cmake_minimum_required(VERSION 3.17)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../lib/graphic)

set(CMAKE_CXX_STANDARD 20)

project("arcade_ncurses" VERSION 0.0.1 LANGUAGES CXX)

add_library(
    arcade_ncurses
    SHARED
    ./NCursesFactory.cpp
	./NCursesImage.cpp
	./NCursesSound.cpp
	./NCursesText.cpp
	./NCursesWindow.cpp
	./../../Error/ArcadeError.cpp
	./../../Error/GraphicError.cpp
)

set(CXX_FLAGS "-fPIC")

set_target_properties(
    arcade_ncurses PROPERTIES PREFIX "")

target_include_directories(
    arcade_ncurses
    PRIVATE
    ../../../include/Libs/NCurses/
    ../../../include/Libs/
    ../../../include/Core/
	../../../include/Error/
)

target_link_libraries(
    arcade_ncurses
    PRIVATE
    -lncurses
)

target_compile_options(
    arcade_ncurses
    PRIVATE
    ${CXX_FLAGS}
)