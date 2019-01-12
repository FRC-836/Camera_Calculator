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

#find QtWidgets library
find_package(Qt5Widgets REQUIRED)

if(WIN32)
  if(CMAKE_CL_64)
    set(ARCH "64")
  else(CMAKE_CL_64)
    set(ARCH "32")
  endif(CMAKE_CL_64)
else(WIN32)
  string(REGEX MATCH ".*[86|32]$" matches "${CMAKE_SYSTEM_PROCESSOR}")
  if(matches)
    set(ARCH "32")
  else(matches)
    set(ARCH "64")
  endif(matches)
endif(WIN32)
set(TARGET_DIR ${CMAKE_BINARY_DIR}/${CMAKE_SYSTEM_NAME}${ARCH})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${TARGET_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${TARGET_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${TARGET_DIR}/lib)

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
