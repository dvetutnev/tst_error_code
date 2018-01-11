cmake_minimum_required(VERSION 3.0)
project(tst_error_code CXX)

include(conan.cmake)
conan_cmake_run(
    CONANFILE conanfile.py
    BASIC_SETUP CMAKE_TARGETS
)

add_executable(${PROJECT_NAME} main.cpp)

enable_testing()

add_executable(t t.cpp)
target_link_libraries(t CONAN_PKG::googletest)
add_test(
    NAME t
    WORKING_DIRECTORY bin
    COMMAND t
)
