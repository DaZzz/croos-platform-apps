cmake_minimum_required(VERSION 2.8.11)

project(lab02)

# Find includes in the build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Turn on automatic invocation of the MOC
set(CMAKE_AUTOMOC ON)

# Cmake prefix for Qt5
set(CMAKE_PREFIX_PATH "/Users/DaZzz/Qt/5.3/clang_64/")


# There may be a way to tell up front if Qt5 is going to be found, but I haven't found
# a foolproof way to do it yet, so settle for the default error message for now.
#if(NOT CMAKE_PREFIX_PATH AND NOT Qt5Widgets_DIR)
#    message(WARNING "CMAKE_PREFIX_PATH is not defined, so find_package may not work. Set the CMAKE_PREFIX_PATH "
#            "environment variable to the install prefix of Qt 5, either on the command line as "
#            "-DCMAKE_PREFIX_PATH=\"path/to/Qt5/lib/cmake\" or with set(CMAKE_PREFIX_PATH path/to/Qt5/lib/cmake)")
#endif(NOT CMAKE_PREFIX_PATH AND NOT Qt5Widgets_DIR)

# Add a compiler flag
set(CMAKE_CXX_FLAGS "-std=c++0x -stdlib=libc++ -g3 -Wall -O0")

# Find the QtWidgets library
find_package(Qt5Widgets REQUIRED)

# Tell CMake to create the helloworld executable
add_executable(lab02 main.cpp mainwindow.cpp aboutdialog.cpp inputdialog.cpp canvas.cpp ${UI_HEADERS} ${QRCS})

# Add the Qt5 Widgets for linking
target_link_libraries(lab02 Qt5::Widgets)
