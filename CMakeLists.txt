cmake_minimum_required (VERSION 3.5)
project(time-will-tell VERSION 1.0 LANGUAGES CXX)

add_executable(time-will-tell 
    src/TimeService.cpp
    src/TaskBarIcon.cpp
    src/PopupFrame.cpp
    src/Application.cpp
    src/main.cpp
)

# doesnt seem to be needed
set(CMAKE_TOOLCHAIN_FILE /home/jr/src/time-will-tell-app/vcpkg/scripts/buildsystems/vcpkg.cmake)

find_package(wxWidgets CONFIG REQUIRED)
target_link_libraries(time-will-tell PRIVATE wx::core wx::base)

find_package(eventpp CONFIG REQUIRED)
target_link_libraries(time-will-tell PRIVATE eventpp::eventpp)

find_package(unofficial-libuuid CONFIG REQUIRED)
target_link_libraries(time-will-tell PRIVATE unofficial::UUID::uuid)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(time-will-tell PRIVATE fmt::fmt)

find_package(uiohook CONFIG REQUIRED PATHS ./lib/libuiohook/dist/lib/cmake)
target_link_libraries(time-will-tell PRIVATE uiohook)

target_include_directories(time-will-tell PUBLIC src)
target_compile_features(time-will-tell PUBLIC cxx_std_20)