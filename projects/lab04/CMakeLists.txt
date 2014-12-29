cmake_minimum_required(VERSION 2.8.11)

project(lab04)

find_package(Qt5Widgets)
find_package(OpenCV REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

qt5_wrap_cpp(
  MOC_WRAPPERS
  mainwindow.h
  canvas.h
  workerthread.h
  )

qt5_wrap_ui(
  UIC_WRAPPERS
  mainwindow.ui
  )

if(WIN32)
  set(gui_type WIN32)
endif()

add_executable(
  lab04 ${gui_type}
  main.cpp
  mainwindow.cpp
  mainwindow.h
  workerthread.cpp
  workerthread.h
  canvas.cpp
  canvas.h
  ${MOC_WRAPPERS}
  ${UIC_WRAPPERS})

target_link_libraries(
  lab04
  Qt5::Widgets
  ${OpenCV_LIBS})

# End of File
