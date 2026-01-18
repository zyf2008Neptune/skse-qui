#include "Core/Core.hpp"

void InitLogger()
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
