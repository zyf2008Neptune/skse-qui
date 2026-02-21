set_xmakever("2.9.2")

-- project
set_project("QUI")
set_version("0.4.0")
set_license("MIT")
set_languages("c++23")
set_encodings("utf-8")
set_warnings("allextra", "error")
set_optimize("smallest")

--submodule
includes("CommonLib")

-- configs
set_config("skyrim_vr", false)
set_config("skyrim_ae", true)
set_config("skyrim_se", true)
set_config("skse_xbyak", true)

-- allowed
set_allowedarchs("x64")
set_allowedmodes("release","debug")

-- default
set_defaultarchs("x64")
set_defaultmode("release")

-- rules
add_rules("mode.releasedbg")
add_rules("plugin.vsxmake.autoupdate")
if is_mode("release", "releasedbg") then
    -- Enable LTO (Link Time Optimization) only in release and releasedbg modes
    -- This ensures that the releasedbg mode closely resembles the release mode
    set_policy("build.optimization.lto", true)
end

-- toolchains
set_toolchains("msvc")

-- packages

add_requires("fmt", "frozen", "toml11")
add_requires("spdlog", { configs = { header_only = false } })

includes("res/package.lua")
includes("src")

