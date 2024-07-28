file(GLOB_RECURSE SOURCE_FILES "*.h" "*.cpp")

# Define the library in utils
add_library(sceneman_module ${SOURCE_FILES})

target_link_libraries(sceneman_module PRIVATE
    ecs_module
    utilities_module
)
# Include directories, if needed
target_include_directories(sceneman_module PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
