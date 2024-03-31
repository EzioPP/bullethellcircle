cmake_minimum_required(VERSION 3.27)
project(a C)

set(CMAKE_C_STANDARD 23)
set(SDL2_INCLUDE_DIR C:/libs/SDL/include)
set(SDL2_LIB_DIR C:/libs/SDL/lib)

set(SDL_TTF_INCLUDE_DIR C:/libs/SDL/include)
set(SDL_TTF_LIB_DIR C:/libs/SDL/lib)

set(SDL_IMAGE_INCLUDE_DIR C:/libs/SDL/include)
SET(SDL_IMAGE_LIB_DIR C:/libs/SDL/lib)

SET(SDL_MIXER_INCLUDE_DIR C:/libs/SDL/include)
SET(SDL_MIXER_LIB_DIR C:/libs/SDL/lib)

include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL_TTF_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})
link_directories(${SDL_TTF_LIB_DIR})

add_executable(a main.c
        utils.c
        utils.h
        geometry.c
        geometry.h
        init.c
        init.h
        define.h
        menu.c
        menu.h
        structs.h)


target_link_libraries(a SDL2main SDL2)
target_link_libraries(a SDL2_ttf)
target_link_libraries(a SDL2_image)
target_link_libraries(a SDL2_mixer)
