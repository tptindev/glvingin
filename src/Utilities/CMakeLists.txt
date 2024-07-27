file(GLOB_RECURSE SOURCE_FILES "*.h" "*.cpp")

# Define the library in utils
add_library(utilities_module ${SOURCE_FILES})
# Include directories, if needed
target_include_directories(utilities_module PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Math
)