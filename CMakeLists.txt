cmake_minimum_required(VERSION 3.6)
project(FdF)
 
set(LIB_PATH ../../LIBFT)
set(GET_NEXT_LINE_PATH ../get_next_line)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-lmlx -framework OpenGL -framework AppKit" )

set(SOURCE_FILES main.c FdF.c array.c)
add_executable(FdF ${SOURCE_FILES} ${GET_NEXT_LINE_PATH}/get_next_line.c)

file(GLOB SOURCES_LIB ${LIB_PATH}/*.c)
add_library(ft STATIC ${SOURCES_LIB}/)

target_link_libraries(FdF ft)	