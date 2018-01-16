cmake_minimum_required(VERSION 3.0)
project(tst_error_code CXX)

include(conan.cmake)
conan_cmake_run(
    CONANFILE conanfile.py
    BASIC_SETUP CMAKE_TARGETS
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(test_adapter_errors test_adapter_errors.cpp adapter_errors)
target_link_libraries(test_adapter_errors CONAN_PKG::googletest)
add_test(
    NAME test_adapter_errors
    WORKING_DIRECTORY bin
    COMMAND test_adapter_errors
)
