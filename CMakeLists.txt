cmake_minimum_required(VERSION 3.20)
project(1889915 C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "-DDEBUG_LIST -DDEBUG_ADDING -DDEBUG_PRINTING_PROCESS -DDEBUG_SHOW_CYCLES -DDEBUG_SHOW_EXCEEDED")
add_executable(1889915 src/printer.c src/task.c src/debugger.c src/main.c)
