cmake_minimum_required (VERSION 3.5)
project(time-will-tell VERSION 1.0 LANGUAGES CXX)

add_executable(time-will-tell 
    src/PopupFrame.cpp
    src/Application.cpp
    src/main.cpp
)

# doesnt seem to be needed
set(CMAKE_TOOLCHAIN_FILE /home/jr/src/time-will-tell-app/vcpkg/scripts/buildsystems/vcpkg.cmake)

find_package(wxWidgets CONFIG REQUIRED)
target_link_libraries(time-will-tell PRIVATE wx::core wx::base)

target_include_directories(time-will-tell PUBLIC src)
target_compile_features(time-will-tell PUBLIC cxx_std_17)