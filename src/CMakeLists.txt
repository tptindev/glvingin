set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(LIBRARY_DIR ${CMAKE_SOURCE_DIR}/libs)

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
    sceneman_module
    engine_module
    ecs_module
    ids_module
    utilities_module
    script_module
)
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/ECS
    ${CMAKE_CURRENT_SOURCE_DIR}/IDs
    ${CMAKE_CURRENT_SOURCE_DIR}/Engine
    ${CMAKE_CURRENT_SOURCE_DIR}/Utilities
    ${CMAKE_CURRENT_SOURCE_DIR}/SceneManager
    ${CMAKE_CURRENT_SOURCE_DIR}/Script
)
