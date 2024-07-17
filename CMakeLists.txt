cmake_minimum_required(VERSION 3.5)

project(vingin LANGUAGES CXX)

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
    gdi32
    opengl32
)
file(COPY
    "${CMAKE_SOURCE_DIR}/bin/glew32.dll"
    "${CMAKE_SOURCE_DIR}/bin/SDL2.dll"
    "${CMAKE_SOURCE_DIR}/bin/SDL2_image.dll"
    "${CMAKE_SOURCE_DIR}/bin/SDL2_mixer.dll"
    "${CMAKE_SOURCE_DIR}/bin/SDL2_ttf.dll"
    DESTINATION ${CMAKE_BINARY_DIR})

include_directories(${INC_DIR})
link_directories(${LIBS_DIR})

add_executable(${PROJECT_NAME} src/main.cpp
    src/Engine/Engine.h src/Engine/Engine.cpp
    src/Engine/EngineEnums.h
    src/SceneManager/SceneManager.h src/SceneManager/SceneManager.cpp
    src/SceneManager/AScene.h src/SceneManager/AScene.cpp
    src/SceneManager/MenuScene.h src/SceneManager/MenuScene.cpp
    src/SceneManager/GameScene.h src/SceneManager/GameScene.cpp)

target_link_libraries( ${PROJECT_NAME} PRIVATE ${LINKER_LIBS})

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
