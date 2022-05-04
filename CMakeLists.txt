cmake_minimum_required(VERSION 3.23.1)
project(complex)
add_executable(${PROJECT_NAME} main.cpp complex.cpp )
install(TARGETS ${PROJECT_NAME} DESTINATION bin)