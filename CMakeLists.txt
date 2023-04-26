cmake_minimum_required(VERSION 3.23)
project(SDL_Game)

set(CMAKE_CXX_STANDARD 20)

#set(SDL2_INCLUDE_DIR C:/CPP_Libs/SDL2-2.26.5/x86_64-w64-mingw32/include)
#set(SDL2_LIB_DIR C:/CPP_Libs/SDL2-2.26.5/x86_64-w64-mingw32/lib)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
set(SDL2_PATH C:/CPP_Libs/SDL2-2.26.5/x86_64-w64-mingw32)

find_package(SDL2 REQUIRED)

add_executable(SDL_Game main.cpp App.cpp App.h Math/Math.h Math/Vector2.h Graphics/Graphics.h Utils/TileMap/TileMap.cpp Utils/TileMap/TileMap.h Utils/IDGenerator.cpp Utils/IDGenerator.h Utils/TileMap/Tile.h Utils/TileMap/Tile.cpp)

include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(SDL_Game ${SDL2_LIBRARY})


