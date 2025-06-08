cmake_minimum_required(VERSION 3.10)
project(SolarExplorer)

set(CMAKE_CXX_STANDARD 20)

# GLFW
find_package(glfw3 REQUIRED)

# ImGui setup
set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/imgui)
set(IMGUI_SOURCES
        ${IMGUI_DIR}/imgui.cpp
        ${IMGUI_DIR}/imgui_demo.cpp
        ${IMGUI_DIR}/imgui_draw.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp
        ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
        ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)
add_library(imgui STATIC ${IMGUI_SOURCES})
target_include_directories(imgui PUBLIC
        ${IMGUI_DIR}
        ${IMGUI_DIR}/backends
        /usr/local/Cellar/glfw/3.4/include
)

# GLAD
set(GLAD_SOURCES external/glad/src/glad.c)

# Saját források
file(GLOB_RECURSE SOURCES "src/*.cpp")
set(STB_IMAGE_SOURCE external/stb/stb_image.cpp)

# Fő program
add_executable(SolarExplorer ${SOURCES} ${GLAD_SOURCES} ${STB_IMAGE_SOURCE})

# Include könyvtárak
target_include_directories(SolarExplorer PRIVATE
        include
        external/glm
        external/glad/include
        external/stb
        ${IMGUI_DIR}
        ${IMGUI_DIR}/backends
)

# Linkelés
target_link_libraries(SolarExplorer PRIVATE imgui glfw ${CMAKE_DL_LIBS})
