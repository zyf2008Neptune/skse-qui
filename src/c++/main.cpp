#include <memory>
#include <string>
#include <string_view>

#include <fmt/format.h>
#include <REX/W32/KERNEL32.h>
#include <SKSE/API.h>
#include <SKSE/Interfaces.h>
#include <SKSE/Logger.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/msvc_sink.h>
#include <spdlog/sinks/sink.h>
#include <spdlog/spdlog.h>

#include "Core/Core.hpp"

auto InitLogger() -> void
{
    auto path = SKSE::log::log_directory();
    if (!path)
    {
        return;
    }

    const auto plugin = SKSE::PluginDeclaration::GetSingleton();
    *path /= fmt::format(FMT_STRING("{}.log"), plugin->GetName());

    std::shared_ptr<spdlog::sinks::sink> sink;
    if (REX::W32::IsDebuggerPresent())
    {
        sink = std::make_shared<spdlog::sinks::msvc_sink_mt>();
    }
    else
    {
        sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(path->string(), true);
    }

    auto splog = std::make_shared<spdlog::logger>("global log"s, sink);
    splog->set_level(spdlog::level::info);
    splog->flush_on(spdlog::level::info);

    spdlog::set_default_logger(std::move(splog));
    spdlog::set_pattern("%s(%#): [%^%l%$] %v"s);
}

SKSEPluginLoad(const SKSE::LoadInterface* a_skse)
{
    InitLogger();

    const auto plugin = SKSE::PluginDeclaration::GetSingleton();
    SKSE::log::info("{} v{}"sv, plugin->GetName(), plugin->GetVersion());

    SKSE::Init(a_skse);
    Core::Init();

    SKSE::log::info("{} loaded"sv, plugin->GetName());

    return true;
}
