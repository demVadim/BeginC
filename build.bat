@echo off

mkdir build
clang++ -x c++ -g -Wall -O0 src/main.cpp src/glad.c -Iinclude -Llib -lglfw3dll -lgdi32 -lopengl32 -o build/game.exe