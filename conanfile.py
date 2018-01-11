from conans import ConanFile


class tst_error_code(ConanFile):
   settings = "os", "compiler", "build_type", "arch"
   requires = "googletest/1.8.0@odant/testing"
   generators = "cmake"

