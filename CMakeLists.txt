cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(YOUNG_DUNGEON_CREATURES)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-mwindows -Wreorder")
endif()

if(NOT DEFINED ENV{SFML_ROOT})
    message(FATAL_ERROR
        "Could not find the SFML root directory.\n"
        "Make sure that the SFML_ROOT environment variable points to it.")
endif()

file(TO_CMAKE_PATH "$ENV{SFML_ROOT}" SFML_ROOT)
file(COPY "${CMAKE_SOURCE_DIR}/assets" DESTINATION "${CMAKE_BINARY_DIR}")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SFML_DIR ${SFML_ROOT}/lib/cmake/SFML)
set(SFML_STATIC_LIBRARIES TRUE)
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")

find_package(SFML 2.5 REQUIRED COMPONENTS
    audio
    graphics
    network)

add_executable(${PROJECT_NAME}
    ${SRC_DIR}/Animations/Fade.cpp
    ${SRC_DIR}/Exceptions/LoadException.cpp
    ${SRC_DIR}/Objects/Background.cpp
    ${SRC_DIR}/Objects/Button.cpp
    ${SRC_DIR}/Scenes/LoadScreen.cpp
    ${SRC_DIR}/Scenes/MainMenu.cpp
    ${SRC_DIR}/Animation.cpp
    ${SRC_DIR}/Config.cpp
    ${SRC_DIR}/Content.cpp
    ${SRC_DIR}/Events.cpp
    ${SRC_DIR}/Game.cpp
    ${SRC_DIR}/Main.cpp
    ${SRC_DIR}/Object.cpp
    ${SRC_DIR}/Scene.cpp
    ${SRC_DIR}/Window.cpp)

target_link_libraries(${PROJECT_NAME}
    sfml-main
    sfml-audio
    sfml-graphics
    sfml-network)
