cmake_minimum_required(VERSION 3.30)
project(InputMaker)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
        lib/include
        Header
        Header/Interactions
        Header/Managers
        Header/Utils
        Header/VisualElements
)

set(SOURCES
        InputMaker.cpp
        src/Interactions/MyGesture.cpp
        src/Managers/ApplicationManager.cpp
        src/Managers/ResolutionManager.cpp
        src/Managers/WindowManager.cpp
        src/Utils/MathUtils.cpp
        src/Utils/MyVector2.cpp
        src/Utils/MyRectangle.cpp
        src/Utils/MyTexture2D.cpp
        src/Utils/TextureUtils.cpp
        src/Utils/WindowsUtils.cpp
        src/VisualElements/UITexture.cpp
        src/Managers/RenderManager.cpp
)

if (MINGW OR WIN32)
    enable_language("RC")
    set(ICON "res/icon/resources.rc" InputMaker.cpp)

    if (CMAKE_BUILD_TYPE STREQUAL "Release")
        set(WINDOWS_LINK_FLAGS "-mwindows")
    endif()
endif()

add_executable(InputMaker ${SOURCES} ${ICON})

set_target_properties(InputMaker PROPERTIES
        OUTPUT_NAME "InputMaker"
        LINK_FLAGS "${WINDOWS_LINK_FLAGS}"
)

if (WINDOWS_LINK_FLAGS)
    set_target_properties(InputMaker PROPERTIES LINK_FLAGS "${WINDOWS_LINK_FLAGS}")
endif()

link_directories(${CMAKE_SOURCE_DIR}/lib)

target_link_libraries(InputMaker
        -static-libgcc
        -static-libstdc++
        ${CMAKE_SOURCE_DIR}/lib/libraylib.a
        opengl32
        gdi32
        winmm
)