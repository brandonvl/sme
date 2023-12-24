# Add GLFW as a subdirectory
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
add_subdirectory(extern/glfw)

# Add GLM as a subdirectory
add_subdirectory(extern/glm)

# Add spdlog as a subdirectory
add_subdirectory(extern/spdlog)

# Add ImGui source files to your project
set(IMGUI_SOURCES 
    extern/imgui/imgui.cpp 
    extern/imgui/imgui_demo.cpp
    extern/imgui/imgui_draw.cpp 
    extern/imgui/imgui_tables.cpp
    extern/imgui/imgui_widgets.cpp 
    extern/imgui/backends/imgui_impl_glfw.cpp 
    extern/imgui/backends/imgui_impl_opengl3.cpp)
add_library(imgui ${IMGUI_SOURCES})

# Include ImGui headers
target_include_directories(imgui PUBLIC extern/imgui)

# Include GLFW headers
target_include_directories(imgui PUBLIC extern/glfw/include)

# Add the GLAD source file to your project
add_library(glad extern/glad/src/glad.c)

# Include the GLAD headers
target_include_directories(glad PUBLIC extern/glad/include)

# Add the Sarene static library
set(SARENE_SOURCES
    # Precompiled header
    src/sarpch.cpp

    # Core files
    src/Sarene/Core/Application.cpp
    src/Sarene/Core/Layer.cpp
    src/Sarene/Core/LayerStack.cpp
    src/Sarene/Core/Log.cpp
    src/Sarene/OrthographicCameraController.cpp

    # Events files

    # ImGui files
    src/Sarene/ImGui/ImGuiBuild.cpp
    src/Sarene/ImGui/ImGuiLayer.cpp
    # Platform files

    # Platform->Window files
    src/Platform/Windows/WindowsInput.cpp
    src/Platform/Windows/WindowsWindow.cpp

    # Platform->OpenGL files
    src/Platform/OpenGL/OpenGLBuffer.cpp
    src/Platform/OpenGL/OpenGLContext.cpp
    src/Platform/OpenGL/OpenGLRendererAPI.cpp
    src/Platform/OpenGL/OpenGLShader.cpp
    src/Platform/OpenGL/OpenGLTexture.cpp
    src/Platform/OpenGL/OpenGLVertexArray.cpp

    # Renderer Files
    src/Sarene/Renderer/Buffer.cpp
    src/Sarene/Renderer/GraphicsContext.cpp
    src/Sarene/Renderer/OrthographicCamera.cpp
    src/Sarene/Renderer/RenderCommand.cpp
    src/Sarene/Renderer/Renderer.cpp
    src/Sarene/Renderer/Renderer2D.cpp
    src/Sarene/Renderer/RendererAPI.cpp
    src/Sarene/Renderer/Shader.cpp
    src/Sarene/Renderer/Texture.cpp
    src/Sarene/Renderer/VertexArray.cpp
    
    # stb_image files
    extern/stb_image/stb_image.cpp
)

add_library(Sarene STATIC ${SARENE_SOURCES}) # Replace with actual source files

# Set Precompiled header
target_precompile_headers(Sarene PRIVATE src/sarpch.h)

# Link the libraries to the Sarene static library
target_link_libraries(Sarene imgui glfw glm spdlog glad)

# Include directories for Sarene library
target_include_directories(Sarene PUBLIC extern/imgui)
target_include_directories(Sarene PUBLIC extern/stb_image)
target_include_directories(Sarene PUBLIC extern/spdlog/include)

# Include root directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

target_compile_definitions(Sarene PRIVATE 
    _CRT_SECURE_NO_WARNINGS
    _SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS
    $<$<CONFIG:Debug>:SAR_DEBUG>
)