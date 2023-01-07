cmake_minimum_required(VERSION 3.25.1)

project(memoirs)

add_executable(${PROJECT_NAME} ./src/main.c)
target_sources(${PROJECT_NAME} PRIVATE ./src/printer.c ./src/validator.c)