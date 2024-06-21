cmake_minimum_required(VERSION 3.27)

project(QUI
		LANGUAGES CXX
		VERSION 3.3.0)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(PROJECT_ROOT ${CMAKE_SOURCE_DIR})


file(GLOB_RECURSE project_files
    src/c++/core/console/*
    src/c++/core/event/*
    src/c++/core/locale/*
    src/c++/core/menu/items/*
    src/c++/core/menu/*
    src/c++/core/*
    src/c++/general/*
    src/c++/Scaleform/CLIK/GFx/Controls/*
    src/c++/Scaleform/CLIK/GFx/Core/*
    src/c++/Scaleform/common/*
    src/c++/Scaleform/system/*
    src/c++/Scaleform/*
    src/c++/main.cpp
    src/c++/quipch.hpp
)

#message(${project_files})


#CommonLibSSE
include(FetchContent)
FetchContent_Declare(
  CommonLibSSE
  GIT_REPOSITORY https://github.com/zyf2008Neptune/CommonLibSSE-NG

  GIT_TAG        main
 
)
FetchContent_MakeAvailable(CommonLibSSE)

list(APPEND DEP CommonLibSSE::CommonLibSSE)


# fmt
find_package(fmt CONFIG REQUIRED)
list(APPEND DEP fmt::fmt)


# frozen
find_package(frozen CONFIG REQUIRED)
list(APPEND DEP frozen::frozen frozen::frozen-headers)


#toml++
find_package(tomlplusplus CONFIG REQUIRED)
list(APPEND DEP tomlplusplus::tomlplusplus)

# spdlog
find_package(spdlog CONFIG REQUIRED)
list(APPEND DEP spdlog::spdlog)

#add_commonlibsse_plugin(${PROJECT_NAME} SOURCES ${project_files})
add_library(${PROJECT_NAME} SHARED ${project_files})


target_link_libraries(${PROJECT_NAME} ${DEP})

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



target_precompile_headers(
	"${PROJECT_NAME}"
	PRIVATE
		src/c++/quipch.hpp
)










