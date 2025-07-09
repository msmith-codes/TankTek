cmake_minimum_required(VERSION 4.0)
project(imgui)

file(GLOB_RECURSE IMGUI_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

add_library(${PROJECT_NAME} STATIC
    ${IMGUI_SOURCES}
)

target_include_directories(${PROJECT_NAME} 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/include/
)

target_link_libraries(${PROJECT_NAME} 
    PUBLIC 
        raylib
)
