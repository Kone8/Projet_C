cmake_minimum_required(VERSION 3.27)
project(ProjetCDataframe)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProjetCDataframe column.h
        cdataframe.h
        h.h
        main.c
        cdataframe.c
        column.c)
