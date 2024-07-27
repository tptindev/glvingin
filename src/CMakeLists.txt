set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(LIBRARY_DIR ${CMAKE_SOURCE_DIR}/libs)
set(LINKER_LIBRARY "-lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lglfw3 -lglew32 -lgdi32 -lopengl32 -lglm")

include_directories(${INCLUDE_DIR})
link_directories(${LIBRARY_DIR})

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(Engine)
add_subdirectory(SceneManager)
add_subdirectory(Utilities)
add_subdirectory(ECS)
add_subdirectory(IDs)
add_subdirectory(Script)

target_link_libraries(${PROJECT_NAME} PRIVATE
    utilities_module
    engine_module
    sceneman_module
    ecs_module
    ids_module
    script_module
    ${LINKER_LIBRARY}
)
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/ECS
    ${CMAKE_CURRENT_SOURCE_DIR}/IDs
    ${CMAKE_CURRENT_SOURCE_DIR}/Engine
    ${CMAKE_CURRENT_SOURCE_DIR}/Utilities
    ${CMAKE_CURRENT_SOURCE_DIR}/SceneManager
    ${CMAKE_CURRENT_SOURCE_DIR}/Script
)
