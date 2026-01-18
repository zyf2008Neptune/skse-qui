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
set_allowedmodes("release","debug")

-- default
set_defaultarchs("x64")
set_defaultmode("release")

-- rules
add_rules("mode.releasedbg")
add_rules("plugin.vsxmake.autoupdate")

-- toolchains
set_toolchains("clang-cl")

-- packages

add_requires("fmt", "frozen", "toml11")
add_requires("spdlog", { configs = { header_only = false } })

package("alandtse-CommonLib-ng")
    set_base("commonlibsse-ng")
    set_urls("https://github.com/alandtse/CommonLibVR/tree/ng.git")
package_end()

add_requires("alandtse-CommonLib-ng ng", {alias ="commonlibsse-ng", configs = { skyrim_vr = false , skyrim_se = false }})
	
includes("res/package.lua")
includes("src")

