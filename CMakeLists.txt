cmake_minimum_required(VERSION 3.5)

project(vingin LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INC_DIR ${CMAKE_SOURCE_DIR}/include)
set(LIBS_DIR ${CMAKE_SOURCE_DIR}/libs)


include_directories(${INC_DIR})
link_directories(${LIBS_DIR})

add_executable(${PROJECT_NAME} src/main.cpp
    src/Engine/Engine.h src/Engine/Engine.cpp
    src/Engine/EngineEnums.h
    src/SceneManager/SceneManager.h src/SceneManager/SceneManager.cpp
    src/SceneManager/AScene.h src/SceneManager/AScene.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE "-lglfw3 -lgdi32 -lopengl32")

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
