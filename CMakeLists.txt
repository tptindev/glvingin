cmake_minimum_required(VERSION 3.5)

project(vingin LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# specify the ouput directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

file(COPY
    "${CMAKE_SOURCE_DIR}/bin/SDL2.dll"
    "${CMAKE_SOURCE_DIR}/bin/SDL2_image.dll"
    "${CMAKE_SOURCE_DIR}/bin/SDL2_mixer.dll"
    "${CMAKE_SOURCE_DIR}/bin/SDL2_ttf.dll"
    "${CMAKE_SOURCE_DIR}/bin/glew32.dll"
    DESTINATION ${CMAKE_BINARY_DIR})

add_subdirectory(src)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
