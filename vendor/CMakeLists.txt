cmake_minimum_required(VERSION 3.25)

include(FetchContent)
FetchContent_Declare(
    glfw
    GIT_REPOSITORY "https://github.com/glfw/glfw.git"
    GIT_TAG "3.4"
)

FetchContent_Declare(
    glm
    GIT_REPOSITORY "https://github.com/g-truc/glm.git"
    GIT_TAG "1.0.1"
)

FetchContent_MakeAvailable(glfw glm)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/glad)
