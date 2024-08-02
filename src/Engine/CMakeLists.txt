set(LINKER_LIBRARY "-lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lglfw3 -lglew32 -lgdi32 -lopengl32 -lglm")

file(GLOB_RECURSE SOURCE_FILES "*.h" "*.cpp")

# Define the library in utils
add_library(engine_module ${SOURCE_FILES})

target_link_libraries(engine_module PRIVATE
    sceneman_module
    utilities_module
    ${LINKER_LIBRARY}
)
# Include directories, if needed
target_include_directories(engine_module PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Event
    ${CMAKE_CURRENT_SOURCE_DIR}/Graphics
    ${CMAKE_CURRENT_SOURCE_DIR}/Graphics/Renderer
)
