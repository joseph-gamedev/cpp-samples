cmake_minimum_required(VERSION 3.18.4)

project("CMakeSample")

add_subdirectory(src)

add_subdirectory(sandbox)

add_executable(${PROJECT_NAME} Main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC SandBoxApp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include )