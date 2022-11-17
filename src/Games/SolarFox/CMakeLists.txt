cmake_minimum_required(VERSION 3.17)

project("arcade_solarfox" VERSION 0.0.1 LANGUAGES CXX)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../lib/game)

set(CMAKE_CXX_STANDARD 20)

add_library(arcade_solarfox SHARED
    ./Map/SolarFoxMap.cpp
    ./Map/SolarFoxMapCase.cpp
	./Spaceship/Missile.cpp
	./Spaceship/Spaceship.cpp
    ./Bomb.cpp
    ./SolarFoxFactory.cpp
	./SolarFoxGame.cpp
	./../AGame.cpp
    ../../Core/Clock.cpp
	../../Error/ArcadeError.cpp
	../../Error/GameError.cpp
)

set(CXX_FLAGS "-fPIC")

set_target_properties(arcade_solarfox PROPERTIES PREFIX "")

target_include_directories(
    arcade_solarfox
    PRIVATE
    ../../../include/Games/SolarFox/Map/
    ../../../include/Games/SolarFox/Spaceship/
    ../../../include/Games/SolarFox/
    ../../../include/Games/
    ../../../include/Libs/
    ../../../include/Core/
	../../../include/Error/
)

target_compile_options(
    arcade_solarfox
    PRIVATE
    ${CXX_FLAGS}
)