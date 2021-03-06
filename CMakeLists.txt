cmake_minimum_required(VERSION 3.5.0)

#Project name
project(Camera_Calculator)

#force c++14 compatibility
set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

#for use with YouCompleteMe in VIM
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#setup qt
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

#fine QtWidgets library
find_package(Qt5Widgets REQUIRED)

#setup source files
set(src src/main.cpp
        src/MainWindow.cpp
        src/CmdOptions.cpp
        )
        
#setup header files
set(include inc/MainWindow.h
            inc/CmdOptions.h
            )

set(forms inc/MainWindow.ui
          )
set(resources res/Resources.qrc
              )
            
#create the executable
add_executable(${PROJECT_NAME} ${src} ${include} ${forms})

#setup include and linking directories
target_include_directories(${PROJECT_NAME} PRIVATE inc
                           ${PROJECT_NAME} PRIVATE deps/OutputManager_Qt/inc
                           )

#linking
target_link_libraries(${PROJECT_NAME} Qt5::Widgets
                                      OutputManager_Qt
                                      )

#dependancies
add_subdirectory(deps/OutputManager_Qt)
