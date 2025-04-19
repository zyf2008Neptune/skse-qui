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
set_allowedmodes("releasedbg")

-- default
set_defaultarchs("x64")
set_defaultmode("releasedbg")

-- rules
add_rules("mode.releasedbg")
add_rules("plugin.vsxmake.autoupdate")

-- toolchains
set_toolchains("clang")

-- packages

add_requires("fmt", "frozen", "toml++")
add_requires("spdlog", { configs = { header_only = false } })
--add_repositories("my-commonlibsse-ng https://github.com/alandtse/CommonLibVR.git ng")
--add_requires("my-commonlibsse-ng", { configs = { skyrim_vr = false , skyrim_se = false }})

package("my-commonlibsse-ng")
    set_base("commonlibsse-ng")
    set_urls("https://github.com/alandtse/CommonLibVR.git")
    on_install(function (package)
        import("package.tools.xmake").install(package)
    end)
package_end()

add_requires("my-commonlibsse-ng ng", {configs = { skyrim_vr = false , skyrim_se = false }})
	
includes("res/package.lua")
includes("src")

