# mkdir build && cd build
# cmake .. -DCMAKE_BUILD_TYPE=Release
# make
# make clean-all

cmake_minimum_required(VERSION 3.10)
project(ShortestPathComparison VERSION 1.0 LANGUAGES CXX)

# Настройка стандарта C++ и предупреждений
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
endif()

# Настройка выходных директорий
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Включение поддиректорий
include_directories(include)

# Список исходных файлов
set(SOURCES
    src/main.cpp
    src/utils/graph_utils.cpp
    src/utils/path_utils.cpp
    src/algorithms/bellman_ford.cpp
    src/algorithms/dijkstra.cpp
    src/algorithms/dijkstra_heap.cpp
    src/algorithms/a_star.cpp
    src/algorithms/floyd_warshall.cpp
)

# Создание исполняемого файла
add_executable(path_compare ${SOURCES})

# Настройка установки
install(TARGETS path_compare
    RUNTIME DESTINATION bin
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

# Дополнительные цели
add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/bin
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/CMakeFiles
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/CMakeCache.txt
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/Makefile
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/cmake_install.cmake
    COMMENT "Очистка всех сгенерированных файлов"
)

# Опционально: поддержка тестов (если есть)
option(BUILD_TESTS "Build tests" OFF)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()