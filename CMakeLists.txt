cmake_minimum_required(VERSION 3.21)
project(ESAME_LABORATORIO_PROGRAMMAZIONE)

add_subdirectory(test)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES FlexGridSizer.cpp FlexGridSizer.h Observer.h Subject.h CellSubject.cpp CellSubject.h CellObserver.cpp CellObserver.h)
find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})
add_executable(ESAME_LABORATORIO_PROGRAMMAZIONE main.cpp main.h FlexGridSizer.cpp FlexGridSizer.h Observer.h Subject.h CellSubject.cpp CellSubject.h CellObserver.cpp CellObserver.h)
add_library(core ${SOURCE_FILES})
target_link_libraries(ESAME_LABORATORIO_PROGRAMMAZIONE ${wxWidgets_LIBRARIES} core)
