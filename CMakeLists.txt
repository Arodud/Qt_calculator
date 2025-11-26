cmake_minimum_required(VERSION 3.16)

project(basic_calculator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appbasic_calculator
    src/main.cpp
)

set(CMAKE_AUTOMOC ON)

target_include_directories(appbasic_calculator PUBLIC include)

qt_add_qml_module(appbasic_calculator
    URI basic_calculator
    QML_FILES src/Main.qml
    QML_FILES src/CalculatorButton.qml
    SOURCES src/main.cpp
    SOURCES src/calculator.cpp
    SOURCES include/buttonmodel.h
    SOURCES src/buttonmodel.cpp
    include/calculator.h
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appbasic_calculator PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appbasic_calculator
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appbasic_calculator
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appbasic_calculator
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
