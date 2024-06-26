set_xmakever("2.9.2")

-- project
set_project("QUI")
set_version("0.3.3.0")
set_license("MIT")
set_languages("c++20")
set_optimize("faster")
set_warnings("allextra", "error")

-- allowed
set_allowedarchs("x64")
set_allowedmodes("debug", "releasedbg")

-- default
set_defaultarchs("x64")
set_defaultmode("releasedbg")

-- rules
add_rules("mode.debug", "mode.releasedbg")


-- packages
 

add_requires("fmt", "frozen", "toml++")
add_requires("spdlog", { configs = { header_only = false } })
add_requires("commonlibsse", { configs = { skyrim_vr = false , skyrim_se = false }})
	
includes("res/package.lua")
includes("src")
