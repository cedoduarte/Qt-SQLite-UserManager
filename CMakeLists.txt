cmake_minimum_required(VERSION 3.5)

project(UserManager VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Sql)

set(PROJECT_SOURCES
    res.qrc
    main.cpp    
    models/user.cpp models/user.h
    views/mainwindow.cpp views/mainwindow.h views/mainwindow.ui
    shared/util.h shared/util.cpp
    shared/constants.h shared/constants.cpp
    shared/databasehandler.h shared/databasehandler.cpp
    shared/jsonfilereader.cpp shared/jsonfilereader.h
    shared/validators/passwordvalidator.cpp shared/validators/passwordvalidator.h
    shared/validators/emailvalidator.h shared/validators/emailvalidator.cpp
    shared/validators/urlvalidator.h shared/validators/urlvalidator.cpp
    shared/validators/usernamevalidator.h shared/validators/usernamevalidator.cpp
    shared/widgets/urltextinput.h shared/widgets/urltextinput.cpp
    shared/widgets/removebutton.h shared/widgets/removebutton.cpp
    shared/widgets/countrycombo.cpp shared/widgets/countrycombo.h
    shared/widgets/emailtextinput.cpp shared/widgets/emailtextinput.h
    shared/widgets/usernametextinput.h shared/widgets/usernametextinput.cpp
    shared/widgets/passwordtextinput.cpp shared/widgets/passwordtextinput.h
    shared/widgets/passwordexplanationpopup.cpp shared/widgets/passwordexplanationpopup.h
    shared/widgets/notextselectiontextbrowser.h shared/widgets/notextselectiontextbrowser.cpp
    shared/widgets/currentdateedit.cpp shared/widgets/currentdateedit.h
    shared/widgets/areyousuredialog.cpp shared/widgets/areyousuredialog.h
    shared/widgets/usertablewidget.cpp shared/widgets/usertablewidget.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(UserManager
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET UserManager APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(UserManager SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(UserManager
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_include_directories(UserManager PRIVATE ".")

target_include_directories(UserManager PRIVATE "./3rdparty/sha256jeremy/src")
target_link_directories(UserManager PRIVATE "./3rdparty/sha256jeremy/lib")

target_link_libraries(UserManager PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(UserManager PRIVATE Qt${QT_VERSION_MAJOR}::Sql)
target_link_libraries(UserManager PRIVATE libsha256jeremy)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.UserManager)
endif()
set_target_properties(UserManager PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS UserManager
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(UserManager)
endif()
