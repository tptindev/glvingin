cmake_minimum_required(VERSION 3.5)

project(vingin LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# specify the ouput directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(INC_DIR ${CMAKE_SOURCE_DIR}/include)
set(LIBS_DIR ${CMAKE_SOURCE_DIR}/libs)
set(LINKER_LIBS
    mingw32
    SDL2main
    SDL2
    SDL2_image
    SDL2_mixer
    SDL2_ttf
    glfw3
    glew32
    gdi32
    opengl32
)
file(COPY
    "${CMAKE_SOURCE_DIR}/bin/SDL2.dll"
    "${CMAKE_SOURCE_DIR}/bin/SDL2_image.dll"
    "${CMAKE_SOURCE_DIR}/bin/SDL2_mixer.dll"
    "${CMAKE_SOURCE_DIR}/bin/SDL2_ttf.dll"
    "${CMAKE_SOURCE_DIR}/bin/glew32.dll"
    DESTINATION ${CMAKE_BINARY_DIR})

include_directories(${INC_DIR})
link_directories(${LIBS_DIR})

add_executable(${PROJECT_NAME} src/main.cpp
    src/Engine/Engine.h src/Engine/Engine.cpp
    src/Engine/EngineEnums.h
    src/SceneManager/SceneManager.h src/SceneManager/SceneManager.cpp
    src/SceneManager/AScene.h src/SceneManager/AScene.cpp
    src/SceneManager/Scenes/MenuScene.h src/SceneManager/Scenes/MenuScene.cpp
    src/SceneManager/Scenes/GameScene.h src/SceneManager/Scenes/GameScene.cpp
    src/ECS/AEntity.h src/ECS/AEntity.cpp
    src/ECS/AComponent.h
    src/ECS/AComponent.cpp
    src/ECS/ASystem.h src/ECS/ASystem.cpp
    src/Utilities/IOC.h
    src/ECS/Components/Transform2D.h src/ECS/Components/Transform2D.cpp
    src/ECS/Entities/Player.h src/ECS/Entities/Player.cpp
    src/Utilities/Math/Vec2.h


)

target_link_libraries( ${PROJECT_NAME} ${LINKER_LIBS})

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
