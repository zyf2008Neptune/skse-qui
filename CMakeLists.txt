cmake_minimum_required(VERSION 3.27)

project(QUI	LANGUAGES CXX)
set(PROJECT_VERSION 1.0.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(PROJECT_ROOT ${CMAKE_SOURCE_DIR})

set(SKSE_SUPPORT_XBYAK ON)
set(ENABLE_SKYRIM_VR OFF)
set(BUILD_TESTS OFF)

add_subdirectory(Commonlib)

include(Commonlib/cmake/CommonLibSSE.cmake)

file(GLOB_RECURSE headers
 src/*.h
 src/*.hpp
)

file(GLOB_RECURSE sources
 src/*.cc
 src/*.cpp
)

add_commonlibsse_plugin(
  ${PROJECT_NAME}
  AUTHOR Qudix
  SOURCES ${headers} ${sources}
)

set(project_files ${headers} ${sources})

add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
# fmt
find_package(fmt CONFIG REQUIRED)
list(APPEND DEP fmt::fmt)


# frozen
find_package(frozen CONFIG REQUIRED)
list(APPEND DEP frozen::frozen frozen::frozen-headers)

#toml11
find_package(toml11 CONFIG REQUIRED)
list(APPEND DEP toml11::toml11)

# spdlog
find_package(spdlog CONFIG REQUIRED)
list(APPEND DEP spdlog::spdlog)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src/c++)
target_link_libraries(${PROJECT_NAME} PRIVATE ${DEP})

if(MSVC)
  target_compile_options(
  "${PROJECT_NAME}"
  PUBLIC
    "/sdl" # Enable Additional Security Checks
    "/utf-8" # Set Source and Executable character sets to UTF-8
    "/Zi" # Debug Information Format
    "/permissive-" # Standards conformance
    "/Zc:preprocessor" # Enable preprocessor conformance mode
    "/bigobj" # Increase Number of Sections in .obj file
    "/WX" # Warnings as errors
    "$<$<CONFIG:DEBUG>:>"
    "$<$<OR:$<CONFIG:RELEASE>,$<CONFIG:PROFILE>>:/Zc:inline;/JMC-;/Ob3>"
 )

  target_link_options("${PROJECT_NAME}" PRIVATE "$<$<CONFIG:DEBUG>:/INCREMENTAL;/OPT:NOREF;/OPT:NOICF>"
     "$<$<OR:$<CONFIG:RELEASE>,$<CONFIG:PROFILE>>:/INCREMENTAL:NO;/OPT:REF;/OPT:ICF;/DEBUG:FULL>")
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES Clang)
  target_compile_options(
  "${PROJECT_NAME}"
  PUBLIC
  -Wno-c++98-compat
  -Wno-c++11-compat
  -Wno-c++14-compat
  -Wno-c++17-compat
  -Wno-c++20-compat
  -Wno-c++23-compat
  -Wno-unused-command-line-argument
  -Wno-invalid-offsetof					  #
  -Wno-builtin-macro-redefined			  #
  -Wno-overloaded-virtual					  #
  -Wno-infinite-recursion					  #
  -Wno-delete-non-abstract-non-virtual-dtor #
  -Wno-inconsistent-missing-override		  #
  -Wno-reinterpret-base-class               #
  -Wno-dynamic-class-memaccess			  #
  "/Z7"
  "/utf-8"
  "$<$<CONFIG:DEBUG>:>"
  "$<$<OR:$<CONFIG:RELEASE>,$<CONFIG:PROFILE>>:/Zc:inline;/JMC-;/Ob3>"		  #
 )
endif()

if (WIN32)
  add_compile_definitions(
          UNICODE
          _UNICODE
          NOMINMAX
          _AMD64_
          WIN32_LEAN_AND_MEAN
  )
endif ()

target_precompile_headers(
 "${PROJECT_NAME}"
 PRIVATE
  src/c++/quipch.hpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
