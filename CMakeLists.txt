cmake_minimum_required(VERSION 3.23)
project(SDL_Game)

set(CMAKE_CXX_STANDARD 20)

#set(SDL2_INCLUDE_DIR C:/CPP_Libs/SDL2-2.26.5/x86_64-w64-mingw32/include)
#set(SDL2_LIB_DIR C:/CPP_Libs/SDL2-2.26.5/x86_64-w64-mingw32/lib)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
set(SDL2_PATH C:/CPP_Libs/SDL2-2.26.5/x86_64-w64-mingw32)

find_package(SDL2 REQUIRED)

add_executable(SDL_Game main.cpp Math/Math.h Math/Vector2.h Graphics/Graphics.h Entities/TileMap/TileMap.cpp Entities/TileMap/TileMap.h Entities/IDGenerator.cpp Entities/IDGenerator.h Entities/TileMap/Tile.h Entities/TileMap/Tile.cpp Entities/Camera.cpp Entities/Camera.h Entities/Player.cpp Entities/Player.h)

include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(SDL_Game ${SDL2_LIBRARY})


