cmake_minimum_required(VERSION 2.8)
project(G52CPP)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_definitions(-std=c++14)

# includes cmake/FindSDL2.cmake
set(CMAKE_MODULE_PATH ${G52CPP_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR})

set(SOURCE_FILES src/mainfunction.cpp 
src/BaseEngine.cpp
src/DisplayableObject.cpp
src/DrawingSurface.cpp
src/FontManager.cpp
src/RawImage.cpp
src/TileManager.cpp
src/SimpleImage.cpp
)

add_executable(PushDaBox ${SOURCE_FILES})
target_link_libraries(PushDaBox ${SDL2_LIBRARY} ${SDL2_TTF_LIBRARY} ${SDL2_IMAGE_LIBRARY})

add_custom_command(TARGET PushDaBox PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${G52CPP_SOURCE_DIR}/src/resources ${CMAKE_CURRENT_BINARY_DIR})

add_custom_command(TARGET PushDaBox PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${G52CPP_SOURCE_DIR}/JsonFileTemplates ${G52CPP_SOURCE_DIR}/src/PushDaBox)
