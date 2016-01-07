cmake_minimum_required(VERSION 3.2)

project(alternas_s)

find_package(PkgConfig)

pkg_check_modules(ALLEGRO5 REQUIRED allegro-5)
pkg_check_modules(ALLEGRO_MAIN REQUIRED allegro_main-5)
pkg_check_modules(ALLEGRO_PRIMITIVES REQUIRED allegro_primitives-5)

include_directories(${ALLEGRO5_INCLUDE_DIRS})
include_directories(${ALLEGRO_MAIN_INCLUDE_DIRS})
include_directories(${ALLEGRO_PRIMITIVES_INCLUDE_DIRS})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

LINK_DIRECTORIES(/usr/local/lib)

file(GLOB_RECURSE ALTERNAS_S_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall -g")

add_custom_target(run ./${PROJECT_NAME})

add_executable(${PROJECT_NAME} main.c ${ALTERNAS_S_SRCS})

target_link_libraries(${PROJECT_NAME} ${ALLEGRO5_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${ALLEGRO_MAIN_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${ALLEGRO_PRIMITIVES_LIBRARIES})
target_link_libraries(${PROJECT_NAME} m)
