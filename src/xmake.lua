target("QUI")
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

    add_packages("frozen", "toml++", "fmt", "spdlog", "commonlibsse")

    add_rules("@commonlibsse-ng/plugin", {
        name = "QUI",
        author = "Qudix",
        description = "Various UI tools, tweaks, and fixes"
    })

    add_files("c++/**.cpp")
    add_includedirs("c++")
    set_pcxxheader("c++/quipch.hpp")

    add_rules("mod.package", {
        ["@{target}-@{target_ver}.zip"] = {
            { "@{target_dir}", "@{target}.dll", "Data/SKSE/Plugins/" },
            { "@{project_dir}/res/plugins/", "@{target}.toml", "Data/SKSE/Plugins/" },
            { "@{project_dir}/res/translations/", "@{target}_*.txt", "Data/Interface/Translations/" },
            { "@{project_dir}/src/swf/", "*.swf", "Data/Interface/" }
        },
        ["@{target}-@{target_ver}_pdb.zip"] = {
            { "@{target_dir}", "@{target}.pdb" },
        }
    })
