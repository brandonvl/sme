cmake_minimum_required(VERSION 3.8) # C++17 requires at least CMake 3.8
project(sme VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17) # Set C++ standard to C++17
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add GLFW as a subdirectory so its CMake file gets executed
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
add_subdirectory(extern/glfw)

# Add GLM as a subdirectory so its CMake file gets executed
add_subdirectory(extern/glm)

# Add spdlog as a subdirectory so its CMake file gets executed
add_subdirectory(extern/spdlog)

# Add ImGui source files to your project
file(GLOB IMGUI_SOURCES ${PROJECT_SOURCE_DIR}/extern/imgui/*.cpp ${PROJECT_SOURCE_DIR}/extern/imgui/backends/imgui_impl_glfw.cpp ${PROJECT_SOURCE_DIR}/extern/imgui/backends/imgui_impl_opengl3.cpp)
add_library(imgui ${IMGUI_SOURCES})

# Include ImGui headers
target_include_directories(imgui PUBLIC ${PROJECT_SOURCE_DIR}/extern/imgui)

# Include GLFW headers
target_include_directories(imgui PUBLIC ${PROJECT_SOURCE_DIR}/extern/glfw/include)

# Add GLAD source file to your executable target
add_executable(sme src/main.cpp ${PROJECT_SOURCE_DIR}/extern/glad/src/glad.c src/spritereader.h)

# Include GLAD headers
target_include_directories(sme PRIVATE ${PROJECT_SOURCE_DIR}/extern/glad/include)

# Link ImGui, GLFW, GLM, and spdlog to your executable
target_link_libraries(sme imgui glfw glm spdlog::spdlog)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)