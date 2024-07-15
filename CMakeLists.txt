cmake_minimum_required(VERSION 3.5)

project(glvingin LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INC_DIR ${CMAKE_SOURCE_DIR}/include)
set(LIBS_DIR ${CMAKE_SOURCE_DIR}/libs)


include_directories(${INC_DIR})
link_directories(${LIBS_DIR})

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE "-lglfw3 -lgdi32 -lopengl32")

include(GNUInstallDirs)
install(TARGETS glvingin
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
