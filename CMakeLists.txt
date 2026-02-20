cmake_minimum_required(VERSION 3.27)

project(QUI	LANGUAGES CXX)
set(PROJECT_VERSION 0.4.0)

set(CMAKE_CXX_STANDARD 20)
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
	src/*.inl
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

#add_library(${PROJECT_NAME} SHARED ${project_files})

#CommonLibSSE
#include(FetchContent)
#FetchContent_Declare(
#  CommonLibSSE
#  GIT_REPOSITORY https://github.com/alandtse/CommonLibVR

#  GIT_TAG        ng
 
#)
#FetchContent_MakeAvailable(CommonLibSSE)

#find_package(CommonLibSSE CONFIG REQUIRED)
#list(APPEND DEP CommonLibSSE::CommonLibSSE)

#to do
#add custom vcpkg port of commlibsse


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

target_link_libraries(${PROJECT_NAME} PRIVATE ${DEP})

if(MSVC)
	target_compile_options(
		"${PROJECT_NAME}"
		PUBLIC

		# disable warnings
		/wd4005 # macro redefinition
		/wd4061 # enumerator 'identifier' in switch of enum 'enumeration' is not explicitly handled by a case label
		/wd4068 # unknown pragma
		/wd4200 # nonstandard extension used : zero-sized array in struct/union
		/wd4201 # nonstandard extension used : nameless struct/union
		/wd4265 # 'type': class has virtual functions, but its non-trivial destructor is not virtual; instances of this class may not be destructed correctly
		/wd4266 # 'function' : no override available for virtual member function from base 'type'; function is hidden
		/wd4371 # 'classname': layout of class may have changed from a previous version of the compiler due to better packing of member 'member'
		/wd4514 # 'function' : unreferenced inline function has been removed
		/wd4582 # 'type': constructor is not implicitly called
		/wd4583 # 'type': destructor is not implicitly called
		/wd4623 # 'derived class' : default constructor was implicitly defined as deleted because a base class default constructor is inaccessible or deleted
		/wd4625 # 'derived class' : copy constructor was implicitly defined as deleted because a base class copy constructor is inaccessible or deleted
		/wd4626 # 'derived class' : assignment operator was implicitly defined as deleted because a base class assignment operator is inaccessible or deleted
		/wd4710 # 'function' : function not inlined
		/wd4711 # function 'function' selected for inline expansion
		/wd4820 # 'bytes' bytes padding added after construct 'member_name'
		/wd4996 # 'deprecated function': required due to Microsoft STL itself using its own deprecated functions
		/wd5026 # 'type': move constructor was implicitly defined as deleted
		/wd5027 # 'type': move assignment operator was implicitly defined as deleted
		/wd5045 # Compiler will insert Spectre mitigation for memory load if /Qspectre switch specified
		/wd5053 # support for 'explicit(<expr>)' in C++17 and earlier is a vendor extension
		/wd5204 # 'type-name': class has virtual functions, but its trivial destructor is not virtual; instances of objects derived from this class may not be destructed correctly
		/wd5220 # 'member': a non-static data member with a volatile qualified type no longer implies that compiler generated copy / move constructors and copy / move assignment operators are not trivial
		
	)
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES Clang)
	target_compile_options(
		"${PROJECT_NAME}"
		PUBLIC

		# disable warnings
		-Wno-invalid-offsetof					  # 
		-Wno-builtin-macro-redefined			  #
		-Wno-overloaded-virtual					  #
		-Wno-infinite-recursion					  #
		-Wno-delete-non-abstract-non-virtual-dtor #
		-Wno-inconsistent-missing-override		  #
		-Wno-reinterpret-base-class               #
		-Wno-dynamic-class-memaccess			  #
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

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_definitions(
            __cpp_lib_char8_t
            __cpp_consteval
            __cpp_lib_format
    )
endif ()



target_precompile_headers(
	"${PROJECT_NAME}"
	PRIVATE
		src/c++/quipch.hpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})








