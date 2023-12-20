# Add your executable
add_executable(sme src/SMEApp.cpp)

# Get all files in the assets directory
file(GLOB_RECURSE ASSETS_FILES CONFIGURE_DEPENDS "SME/assets/*")

# Custom command to copy assets directory
add_custom_command(TARGET sme POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   "${CMAKE_SOURCE_DIR}/SME/assets" "$<TARGET_FILE_DIR:sme>/assets"
                   DEPENDS ${ASSETS_FILES})

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