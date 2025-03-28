cmake_minimum_required(VERSION 3.25)
project(
    Example
    VERSION 0.1.0
    LANGUAGES CXX
)

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} TankTekFramework)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${PROJECT_NAME} PRIVATE ASSET_PATH="${CMAKE_SOURCE_DIR}/assets/")
endif()
