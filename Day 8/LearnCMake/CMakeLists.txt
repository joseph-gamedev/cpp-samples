cmake_minimum_required(VERSION 3.18.4)

project("HelloWorld" VERSION 1.0.0)

add_subdirectory(src)

add_executable(${PROJECT_NAME} Main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC MathLib)

target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/include")
