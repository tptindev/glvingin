file(GLOB_RECURSE SOURCE_FILES "*.h" "*.cpp")

# Define the library in utils
add_library(script_module ${SOURCE_FILES}
    Scenes/MenuScene/Entities/MenuBackground.h Scenes/MenuScene/Entities/MenuBackground.cpp)

target_link_libraries(script_module PRIVATE
    ecs_module
    engine_module
    ids_module
    sceneman_module
    utilities_module
)
# Include directories, if needed
target_include_directories(script_module PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
