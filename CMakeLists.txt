cmake_minimum_required(VERSION 3.29)
project(Progetto_Software_security C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Progetto_Software_security
        src/lz4.c
        src/lz4.h
        src/lz4file.c
        src/lz4file.h
        src/lz4frame.c
        src/lz4frame.h
        src/lz4frame_static.h
        src/lz4hc.c
        src/lz4hc.h
        src/xxhash.c
        src/xxhash.h
        main.c
        menu/utility_functions.c
        menu/menu_logic.c)
