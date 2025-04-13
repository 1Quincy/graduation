cmake_minimum_required(VERSION 3.16)

project(employee_punch-in_system VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 COMPONENTS Core Widgets Sql REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS WebEngineWidgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindowtotal.cpp
        mainwindowtotal.h
        mainwindowtotal.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(employee_punch-in_system
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        dialoglogin.h dialoglogin.cpp dialoglogin.ui
        src.qrc
        mysql.h mysql.cpp
        dialogemployeeinfo.h dialogemployeeinfo.cpp dialogemployeeinfo.ui
        dialogpersoninfo.h dialogpersoninfo.cpp dialogpersoninfo.ui
        userinfo.h userinfo.cpp
        dialogsignin.h dialogsignin.cpp dialogsignin.ui
        dialogsignout.h dialogsignout.cpp dialogsignout.ui
        dialogleave.h dialogleave.cpp dialogleave.ui
        dialogpermit.h dialogpermit.cpp dialogpermit.ui
        dialogleavelog.h dialogleavelog.cpp dialogleavelog.ui
        dialogworktime.h dialogworktime.cpp dialogworktime.ui
        dialogregister.h dialogregister.cpp dialogregister.ui
        function.h function.cpp




        define.h
        ContactItem.cpp ContactItem.h ContactItem.ui
        talkwindow.h talkwindow.cpp talkwindow.ui
        left.h left.cpp left.ui
        right.h right.cpp right.ui
        clockwidget.h clockwidget.cpp clockwidget.ui
        dialogfindpwd.h dialogfindpwd.cpp dialogfindpwd.ui
        dialogmodifyinfo.h dialogmodifyinfo.cpp dialogmodifyinfo.ui







    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET employee_punch-in_system APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(employee_punch-in_system SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(employee_punch-in_system
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(employee_punch-in_system PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(employee_punch-in_system PRIVATE Qt6::Core Qt6::Widgets Qt6::Sql)
target_link_libraries(employee_punch-in_system PRIVATE Qt6::WebEngineWidgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.employee_punch-in_system)
endif()
set_target_properties(employee_punch-in_system PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS employee_punch-in_system
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(employee_punch-in_system)
endif()


# 添加 QXlsx 子目录
add_subdirectory(QXlsx/QXlsx)

# 链接主程序到 QXlsx
target_link_libraries(employee_punch-in_system PRIVATE
    QXlsx::QXlsx
)
