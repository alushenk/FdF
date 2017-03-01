cmake_minimum_required(VERSION 3.6)
project(FdF)
 
set(LIB_PATH externals/libft)
set(GET_NEXT_LINE_PATH externals/get_next_line)

set(CMAKE_C_STANDARD 99)
set(UBUNTU_FLAGS " -lmlx -lXext -lX11")
set(MACOS_FLAGS "-lmlx -framework OpenGL -framework AppKit")
set(CMAKE_C_FLAGS ${MACOS_FLAGS})

#file(GLOB SOURCE_FILES src/*.c)
set(SOURCE_FILES src/main.c src/array.c src/draw.c src/events.c src/matrix.c src/rotate.c src/centrate_matrix.c src/draw0.c src/events_get.c)
add_executable(FdF ${SOURCE_FILES} ${GET_NEXT_LINE_PATH}/get_next_line.c)

file(GLOB SOURCES_LIB ${LIB_PATH}/*.c)
add_library(ft STATIC ${SOURCES_LIB}/)

target_link_libraries(FdF ft)