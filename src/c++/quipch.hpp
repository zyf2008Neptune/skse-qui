#pragma once

#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#define TOML_EXCEPTIONS 0

#pragma warning(push)
#pragma warning(disable : 4200)
#include <SKSE/SKSE.h>
#include <RE/Skyrim.h>
#pragma warning(pop)

#include <fmt/format.h>
#include <frozen/map.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/msvc_sink.h>
#include <toml++/toml.h>

#include <source_location>

using namespace std::literals;

namespace stl
{
    using namespace SKSE::stl;
}
