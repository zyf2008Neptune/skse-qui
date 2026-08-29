#pragma once

#pragma warning(push)
#pragma warning(disable : 4200)
#include <RE/Skyrim.h>
#include <SKSE/SKSE.h>
#pragma warning(pop)

#include <fmt/format.h>
#include <frozen/map.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/msvc_sink.h>
#include <toml.hpp>

using namespace std::literals;

namespace stl
{
    using namespace SKSE::stl;
}
