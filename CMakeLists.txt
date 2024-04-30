cmake_minimum_required(VERSION 3.10)

project(messanger VERSION 1.0 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
 
find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

include_directories(src)

set(SOURCES
    src/app/main.cpp
    src/messanger/messanger.cpp
    src/messanger/tool_bar/tools.cpp
    src/read_file.cpp
)

set(HEADERS
    src/include/include.h
    src/messanger/messanger.h
    src/messanger/tool_bar/tools.h
    src/read_file.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Gui Qt5::Widgets)

set(CSS_FILES
    styles/button.css
    styles/main.css
    styles/tool_bar.css
    styles/message_text.css
)

foreach(CSS_FILE ${CSS_FILES})
    configure_file(${CSS_FILE} ${CMAKE_CURRENT_BINARY_DIR}/${CSS_FILE} COPYONLY)
endforeach()