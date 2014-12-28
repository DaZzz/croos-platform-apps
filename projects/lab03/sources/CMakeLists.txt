cmake_minimum_required(VERSION 2.8.11)

project(lab03)

# Find includes in the build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Turn on automatic invocation of the MOC
qt5_wrap_cpp(
  MOC_WRAPPERS
  main.h
  mainwindow.h
  mdichild.h
  aboutdialog.h
  zipitem.h
  zipmodel.h
  )

find_package(libarchive REQUIRED)
include_directories(${LIBARCHIVE_INCLUDES})

# Find the QtWidgets library
find_package(Qt5Widgets REQUIRED)

# Find the QtWidgets library
find_package(Qt5LinguistTools REQUIRED)

SET(TRANS lab03_en_US.ts)

# Generate code from ui files
qt5_wrap_ui(UI_HEADERS mainwindow.ui aboutdialog.ui)
qt5_add_translation(QM ${TRANS})


if(WIN32)
  set(gui_type WIN32)
endif()

# Tell CMake to create the helloworld executable
add_executable(lab03 ${gui_type} main.cpp mainwindow.cpp mdichild.cpp  aboutdialog.cpp zipitem.cpp zipmodel.cpp ${UI_HEADERS} ${QRCS} ${QM})

# Add the Qt5 Widgets for linking
target_link_libraries(lab03 Qt5::Widgets ${LIBARCHIVE_INCLUDES})


Installation
install(
  TARGETS lab03
  RUNTIME DESTINATION bin)

install(
  FILES ${QM}
  DESTINATION translations)

include(DeployQt4)

get_property(
  EXE_PATH
  TARGET lab03
  PROPERTY LOCATION)

message(${QM})

if(EXE_PATH)
  get_filename_component(EXE_NAME ${EXE_PATH} NAME)
  install_qt4_executable(bin/${EXE_NAME})
endif()