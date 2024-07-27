file(GLOB_RECURSE SOURCE_FILES "*.h" "*.cpp")

# Define the library in utils
add_library(sceneman_module ${SOURCE_FILES})

# Include directories, if needed
target_include_directories(sceneman_module PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)