cmake_minimum_required(VERSION 3.21)
project(ESAME_LABORATORIO_PROGRAMMAZIONE)

set(CMAKE_CXX_STANDARD 14)
find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})
add_executable(ESAME_LABORATORIO_PROGRAMMAZIONE main.cpp main.h FlexGridSizer.cpp FlexGridSizer.h)
target_link_libraries(ESAME_LABORATORIO_PROGRAMMAZIONE ${wxWidgets_LIBRARIES})
