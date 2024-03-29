###############################################################################
#  Copyright (c) 2016-2020 Joel de Guzman
#
#  Distributed under the MIT License (https://opensource.org/licenses/MIT)
###############################################################################
set(CMAKE_C_COMPILER gcc)
cmake_minimum_required(VERSION 3.7.2...3.15.0)
include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)

project(artist LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)

set(DEFAULT_BUILD_TYPE "Release")
if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
   message(STATUS "Setting build type to '${DEFAULT_BUILD_TYPE}' as none was specified.")
   set(CMAKE_BUILD_TYPE "${DEFAULT_BUILD_TYPE}" CACHE
      STRING "Choose the type of build." FORCE)
   # Set the possible values of build type for cmake-gui
   set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
     "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

include(CheckIPOSupported)
check_ipo_supported(RESULT IPO_SUPPORTED)
if (IPO_SUPPORTED)
   message(STATUS "Link-time optimization supported. Will be enabled in Release build type")
endif()

if (APPLE)
  option(ARTIST_QUARTZ_2D "build Artist using quartz 2d on MacOS" ON)
  option(ARTIST_SKIA "build Artist using skia" OFF)
else()
  option(ARTIST_SKIA "build Artist using skia" ON)
endif()

if (ARTIST_SKIA)
  set(ARTIST_QUARTZ_2D OFF)
endif()

if (ARTIST_SKIA AND WIN32)
   ExternalProject_Add(windows_dlls
      PREFIX "windows-x64-dll"
      URL https://github.com/cycfi/artist/releases/download/prebuilt-binaries/windows-x64-dll.zip
      URL_MD5 4c07a5aa4bfddff268535244196f900f
      CONFIGURE_COMMAND ""
      BUILD_COMMAND ""
      INSTALL_COMMAND ""
   )
   set(FONTCONFIG_DLL ${CMAKE_CURRENT_BINARY_DIR}/windows-x64-dll/src/windows_dlls/fontconfig.dll)
   set(ICONV_DLL ${CMAKE_CURRENT_BINARY_DIR}/windows-x64-dll/src/windows_dlls/libiconv.dll)
   set(XML2_DLL ${CMAKE_CURRENT_BINARY_DIR}/windows-x64-dll/src/windows_dlls/libxml2.dll)
   set(FREETYPE_DLL ${CMAKE_CURRENT_BINARY_DIR}/windows-x64-dll/src/windows_dlls/freetype.dll)
endif()

if (ARTIST_SKIA AND WIN32)
   message(STATUS "Building Artist lib for Win32 with Skia.")
elseif (ARTIST_SKIA AND APPLE)
   message(STATUS "Building Artist lib for MacOS with Skia.")
elseif (ARTIST_QUARTZ_2D AND APPLE)
   message(STATUS "Building Artist lib for MacOS with Quartz2D.")
endif()

add_subdirectory(lib)

option(ARTIST_BUILD_EXAMPLES "build Artist library examples" ON)
option(ARTIST_BUILD_TESTS "build Artist library tests" ON)

if (ARTIST_BUILD_EXAMPLES)
   add_subdirectory(examples)
endif()

if (ARTIST_BUILD_TESTS)
   add_subdirectory(test)
endif()
