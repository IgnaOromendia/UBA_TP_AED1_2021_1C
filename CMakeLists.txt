cmake_minimum_required(VERSION 3.5)
project(ajedrezLite)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)

file(GLOB DIR_TESTS_EN "tests/*.cpp")

set(SOURCE_FILES_TEST
        main.cpp
        ejercicios.cpp
        auxiliares.cpp
        )
add_executable(ajedrezLite 
		${SOURCE_FILES_TEST}
		${DIR_TESTS_EN})

target_link_libraries(ajedrezLite gtest gtest_main)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

# -g: Hace que podamos debuggear el programa.
# --coverage: Hace que se pueda calcular el cubrimiento de los casos de test.
set(CMAKE_CXX_FLAGS "-g --coverage")
# Un temita de gcov que no se lleva tan bien con CMake,
# y entonces hay que poner esta línea.
# Para más información, ver https://texus.me/2015/09/06/cmake-and-gcov/.
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)
