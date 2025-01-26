cmake_minimum_required(VERSION 3.30)
project(OGLLight)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/include)
add_library(glad STATIC ${CMAKE_SOURCE_DIR}/src/glad.c)

set(GLFW_DIR "C:/libs/glfw-3.4/install/lib/cmake/glfw3")
set(CMAKE_PREFIX_PATH  ${GLFW_DIR})

find_package(glfw3 REQUIRED CONFIG)
find_package(OpenGL REQUIRED)

add_executable(OGLLight src/main.cpp)

target_link_libraries(OGLLight glad glfw OpenGL::GL)