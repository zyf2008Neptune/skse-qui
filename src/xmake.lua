-- targets
target("QUI")

    -- add compile defination
    add_defines("NOMINMAX")

    -- add dependencies to target
    add_deps("commonlibsse-ng")

    -- add packages
    add_packages("fmt", "frozen", "toml11", "spdlog")

    -- add commonlibsse-ng plugin
    add_rules("commonlibsse-ng.plugin", {
        name = "QUI",
        description = "SKSE64 plugin using CommonLibSSE-NG"
    })

    -- add src files
    add_files("c++/**.cpp")
    add_includedirs("c++")
    add_headerfiles("c++/**.hpp")
    set_pcxxheader("c++/quipch.hpp")

    -- add flags
    add_cxxflags("/EHsc", "/permissive-", { public = true })

    -- add flags (cl)
    add_cxxflags(
        "cl::/sdl",
        "cl::/Zi",
        "cl::/Zc:preprocessor",
        "cl::/cgthreads8",
        "cl::/diagnostics:caret",
        "cl::/external:W0",
        "cl::/fp:contract",
        "cl::/fp:except-",
        "cl::/guard:cf-",
        "cl::/Zc:enumTypes",
        "cl::/bigobj"
    )
    -- add flags (clang-cl)
    add_cxxflags(
        "clang_cl::-fms-compatibility",
        "clang_cl::-fms-extensions",
        { public = true }
    )

    -- add flags (clang-cl: disable warnings)
    add_cxxflags(
        "clang_cl::-Wno-delete-non-abstract-non-virtual-dtor",
        "clang_cl::-Wno-deprecated-volatile",
        "clang_cl::-Wno-ignored-qualifiers",
        "clang_cl::-Wno-inconsistent-missing-override",
        "clang_cl::-Wno-invalid-offsetof",
        "clang_cl::-Wno-microsoft-include",
        "clang_cl::-Wno-overloaded-virtual",
        "clang_cl::-Wno-pragma-system-header-outside-header",
        "clang_cl::-Wno-reinterpret-base-class",
        "clang_cl::-Wno-switch",
        "clang_cl::-Wno-unused-private-field",
        "clang_cl::-Wno-c++98-compat",
        "clang_cl::-Wno-c++11-compat",
        "clang_cl::-Wno-c++14-compat",
        "clang_cl::-Wno-c++17-compat",
        "clang_cl::-Wno-c++20-compat",
        "clang_cl::-Wno-c++23-compat",
        "clang_cl::-Wno-unused-command-line-argument",
        { public = true }
    )

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
