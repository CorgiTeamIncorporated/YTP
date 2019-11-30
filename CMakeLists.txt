cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(YDC)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-mwindows -Wreorder")
endif()

if(NOT DEFINED ENV{SFML_ROOT})
    message(FATAL_ERROR
        "Could not find the SFML root directory.\n"
        "Make sure that the SFML_ROOT environment variable points to it.\n"
        "Also ensure that it contains the lib/cmake/SFML directory.")
endif()

file(TO_CMAKE_PATH "$ENV{SFML_ROOT}" SFML_ROOT)
file(COPY ${CMAKE_SOURCE_DIR}/fonts DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/textures DESTINATION ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SFML_DIR ${SFML_ROOT}/lib/cmake/SFML)
set(SFML_STATIC_LIBRARIES TRUE)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

include_directories(${CMAKE_SOURCE_DIR}/include)

find_package(SFML 2.5 REQUIRED COMPONENTS
    audio
    graphics
    network)

add_executable(${PROJECT_NAME}
    ${SRC_DIR}/AnimatedSprite.cpp
    ${SRC_DIR}/Dungeon.cpp
    ${SRC_DIR}/GameFonts.cpp
    ${SRC_DIR}/GameManager.cpp
    ${SRC_DIR}/GameSprites.cpp
    ${SRC_DIR}/GameTextures.cpp
    ${SRC_DIR}/GameRoom.cpp
    ${SRC_DIR}/GUIBlock.cpp
    ${SRC_DIR}/GUIButton.cpp
    ${SRC_DIR}/GUIObject.cpp
    ${SRC_DIR}/GUISimpleSprite.cpp
    ${SRC_DIR}/../main.cpp
    ${SRC_DIR}/MainMenu.cpp
    ${SRC_DIR}/MapObject.cpp
    ${SRC_DIR}/Unit.cpp
    ${SRC_DIR}/Zombie.cpp)

target_link_libraries(${PROJECT_NAME}
    sfml-main
    sfml-audio
    sfml-graphics
    sfml-network)
