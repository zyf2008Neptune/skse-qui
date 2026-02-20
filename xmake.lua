set_xmakever("2.9.2")

--submodule
includes(CommonLib)

-- project
set_project("QUI")
set_version("0.4.0.0")
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
set_toolchains("msvc")

-- packages

add_requires("fmt", "frozen", "toml11")
add_requires("spdlog", { configs = { header_only = false } })

-- targets
target("QUI")
-- add dependencies to target
    add_deps("commonlibsse-ng")

    -- add commonlibsse-ng plugin
    add_rules("commonlibsse-ng.plugin", {
        name = "QUI",
        description = "SKSE64 plugin using CommonLibSSE-NG"
    })

    -- add src files
    add_files("src/**.cpp" "src/**.cc")
    add_headerfiles("src/**.h" "src/**.hpp")
    add_includedirs("src")
    set_pcxxheader("src/quipch.hpp")
