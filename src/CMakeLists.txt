cmake_minimum_required(VERSION 3.5)

project(SmartCalc VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets PrintSupport)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets PrintSupport)

# Add include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/view)

# Add source files
set(PROJECT_SOURCES
    controller/calcController.cc
    model/credModel.cc
    model/model.cc
    view/credit.cpp
    view/deposit.cpp
    view/info.cpp
    main.cpp
    view/mainwindow.cpp
    view/plotter.cpp
    view/qcustomplot.cpp
    controller/calcController.h
    controller/credController.h
    controller/deposController.h
    model/credModel.h
    model/deposModel.h
    model/model.h
    view/deposit.h
    view/info.h
    view/mainwindow.h
    view/plotter.h
    view/qcustomplot.h
    view/credit.h
    view/deposit.ui
    view/info.ui
    view/mainwindow.ui
    view/plotter.ui
    view/credit.ui
    view/resource.qrc
    view/fonts/Quicksand-Bold.ttf
    view/fonts/Quicksand-Medium.ttf
    view/fonts/Quicksand-Regular.ttf
    view/icons/app_icon.png
    view/icons/calc_icn.icns
    view/icons/credit1.png
    view/icons/credit2.png
    view/icons/favicon.ico
    view/icons/graph1.png
    view/icons/graph2.png
    view/icons/info.gif
    view/icons/piggy1.png
    view/icons/piggy2.png
)

# Add resource files
#set(RESOURCES

#)

set(MACOSX_BUNDLE_ICON_FILE calc_icn.icns)

if(APPLE)
    set(app_icon_macos "${CMAKE_CURRENT_SOURCE_DIR}/view/icons/calc_icn.icns")
    set_source_files_properties(${app_icon_macos} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
endif()


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SmartCalc
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${app_icon_macos}
#        ${RESOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Calc APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(SmartCalc SHARED
            ${PROJECT_SOURCES}
#            ${RESOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(SmartCalc
            ${PROJECT_SOURCES}
            ${app_icon_macos}
#            ${RESOURCES}
        )
    endif()
endif()

target_link_libraries(SmartCalc PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt6::PrintSupport)

set_target_properties(SmartCalc PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SmartCalc)
endif()

