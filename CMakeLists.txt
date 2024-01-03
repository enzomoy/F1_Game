cmake_minimum_required(VERSION 3.25)
project(F1_Game C CXX)


set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_C_COMPILER "C:/msys64/mingw64/bin/g++.exe")
set(CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/g++.exe")


find_package(Qt6 COMPONENTS Widgets REQUIRED)

include_directories("ext/include")
link_directories("ext/lib")

file(GLOB_RECURSE SOURCES "src/.cpp*" "src/.c*" "src/css/*.css" "include/*.h")
add_executable(F1_Game ${SOURCES}
        src/start.cpp
        src/menu.cpp
        src/main.cpp
        src/pilots_fonctions.c)

target_link_libraries(F1_Game PRIVATE ${CMAKE_SOURCE_DIR}/ext/lib/mysql/libmysql.dll)
target_link_libraries(F1_Game PRIVATE ${CMAKE_SOURCE_DIR}/ext/lib/curl/libcurl.dll.a)

target_link_libraries(F1_Game PRIVATE Qt6::Widgets)

add_custom_command(TARGET F1_Game POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/ext/bin/QT $<TARGET_FILE_DIR:F1_Game>)
