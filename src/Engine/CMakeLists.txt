file(GLOB_RECURSE SOURCE_FILES "*.h" "*.cpp")

# Define the library in utils
add_library(engine_module ${SOURCE_FILES})

target_link_libraries(engine_module PRIVATE
    sceneman_module
)
# Include directories, if needed
target_include_directories(engine_module PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
