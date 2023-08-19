cmake_minimum_required(VERSION 3.23)
project(SearchSystem)

set(CMAKE_CXX_STANDARD 17)

set(FILES_SOURCE
        process_queries.cpp
        document.cpp
        process_queries.cpp
        read_input_functions.cpp
        request_queue.cpp
        search_server.cpp
        string_processing.cpp
        test_example_functions.cpp
        document.cpp)

set(FILE_MAIN main.cpp)

add_executable(SearchServer ${FILE_MAIN} ${FILES_SOURCE} )

if(CMAKE_SYSTEM_NAME MATCHES "^MINGW")
    set(SYSTEM_LIBS -lstdc++)
else()
    set(SYSTEM_LIBS)
endif()

target_link_libraries(SearchServer -ltbb -lpthread ${SYSTEM_LIBS})
