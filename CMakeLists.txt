cmake_minimum_required(VERSION 3.17)
project(shaddow_lang)
set(CMAKE_C_STANDARD 99)
add_executable(mycomp src/main.c src/parser.c src/util.c include/parser.h include/util.h include/token.h)
