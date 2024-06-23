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

package("commonlibsse")
    set_homepage("https://github.com/zyf2008Neptune/CommonLibSSE-NG")
    set_description("A reverse engineered library for Skyrim Special Edition.")
    set_license("MIT")

    add_urls("https://github.com/zyf2008Neptune/CommonLibSSE-NG.git")
    
    add_configs("skyrim_se", {description = "Enable runtime support for Skyrim SE", default = true, type = "boolean"})
    add_configs("skyrim_ae", {description = "Enable runtime support for Skyrim AE", default = true, type = "boolean"})
    add_configs("skyrim_vr", {description = "Enable runtime support for Skyrim VR", default = true, type = "boolean"})
    add_configs("skse_xbyak", {description = "Enable trampoline support for Xbyak", default = false, type = "boolean"})

    add_deps("fmt", "rapidcsv", "directxmath", "directxtk")
    add_deps("spdlog", { configs = { header_only = false, wchar = true, std_format = true } })

    add_syslinks("version", "user32", "shell32", "ole32", "advapi32")

    on_load("windows|x64", function(package)
        if package:config("skyrim_se") then
            package:add("defines", "ENABLE_SKYRIM_SE=1")
        end
        if package:config("skyrim_ae") then
            package:add("defines", "ENABLE_SKYRIM_AE=1")
        end
        if package:config("skyrim_vr") then
            package:add("defines", "ENABLE_SKYRIM_VR=1")
        end
        if package:config("skse_xbyak") then
            package:add("defines", "SKSE_SUPPORT_XBYAK=1")
            package:add("deps", "xbyak")
        end

        package:add("defines", "HAS_SKYRIM_MULTI_TARGETING=1")
    end)

    on_install("windows|x64", function(package)
        os.cp(path.join(package:scriptdir(), "port", "xmake.lua"), "xmake.lua")

        local configs = {}
        configs.skyrim_se = package:config("skyrim_se")
        configs.skyrim_ae = package:config("skyrim_ae")
        configs.skyrim_vr = package:config("skyrim_vr")
        configs.skse_xbyak = package:config("skse_xbyak")

        import("package.tools.xmake").install(package, configs)
    end)
  

add_requires("fmt", "frozen", "toml++")
add_requires("spdlog", { configs = { header_only = false } })
add_requires("commonlibsse", { configs = { skyrim_vr = false , skyrim_se = false }})
	
includes("res/package.lua")
includes("src")
