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
    src/messanger/tools.cpp
    src/help.cpp
    src/messages/abstract.cpp
    src/messages/text_message.cpp
    src/messages/photo_message.cpp
    src/messanger/scroll_chat.cpp
    src/photo_redactor.cpp
    src/save_load_chat.cpp
)

set(HEADERS
    src/include/include.h
    src/messanger/messanger.h
    src/messanger/tools.h
    src/help.h
    src/messages/abstract.h
    src/messages/text_message.h
    src/messages/photo_message.h
    src/messanger/scroll_chat.h
    src/photo_redactor.h
    src/save_load_chat.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Gui Qt5::Widgets)

set(CSS_FILES
    styles/button.css
    styles/main.css
    styles/tool_bar.css
    styles/message_text.css
    styles/message.css
    styles/chat.css
    styles/message_item.css
    styles/copy_text_from_message_button.css
)

foreach(CSS_FILE ${CSS_FILES})
    configure_file(${CSS_FILE} ${CMAKE_CURRENT_BINARY_DIR}/${CSS_FILE} COPYONLY)
endforeach()