# Add your executable
add_executable(sme src/SMEApp.cpp)

# Link Sarene library to your executable
target_link_libraries(sme Sarene)

# Include src directory of Sarene
include_directories(${CMAKE_SOURCE_DIR}/Sarene/src)

# Include imgui header files
include_directories(${CMAKE_SOURCE_DIR}/Sarene/vendor/imgui)

target_compile_definitions(sme PRIVATE 
    _CRT_SECURE_NO_WARNINGS
    _SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS
    $<$<CONFIG:Debug>:SAR_DEBUG>
)

if(WIN32)
    target_compile_definitions(sme PRIVATE SAR_PLATFORM_WINDOWS)
endif()