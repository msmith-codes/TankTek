cmake_minimum_required(VERSION 3.25)
project(
    glad
    VERSION 0.1.0
    LANGUAGES C
)

set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/glad.c)
add_library(${PROJECT_NAME} STATIC ${SOURCES})

## Including Headers ##
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)