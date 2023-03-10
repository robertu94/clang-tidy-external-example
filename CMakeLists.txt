cmake_minimum_required(VERSION 3.14)
project(myclang_tidy VERSION "0.0.1" LANGUAGES CXX C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(LibPressio REQUIRED)
find_package(std_compat REQUIRED)
find_package(Clang REQUIRED)
list(APPEND CMAKE_MODULE_PATH "${CLANG_CMAKE_DIR}")
list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(AddLLVM)
include(AddClang)
set( LLVM_LINK_COMPONENTS
  ${LLVM_TARGETS_TO_BUILD}
  Core
  Option
  Support
  )


add_clang_library(myclang_tidy SHARED
  ./src/clangtidy_libpressio.cc
  ./include/clangtidy_libpressio.h
  )
clang_target_link_libraries(myclang_tidy
  PRIVATE
  clangAnalysis
  clangAST
  clangASTMatchers
  clangBasic
  clangFormat
  clangFrontend
  clangLex
  clangRewrite
  clangSema
  clangSerialization
  clangTooling
  clangToolingCore
  clangTidy
  clangTidyModule
  )
target_include_directories(myclang_tidy PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    )

