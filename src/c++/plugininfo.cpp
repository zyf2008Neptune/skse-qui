#include "REL/Rel.h"
#include "SKSE/SKSE.h"

using namespace REL::literals;
using namespace SKSE;

namespace
{
    constinit PluginDeclaration WithAddressLibrary(
    {.Version = "0.3.3.0"_v,
     .Name = "QUI",
     .RuntimeCompatibility = VersionIndependence::AddressLibrary});

    constinit PluginDeclaration ForSpecificRuntimes({.Version = "0.3.3.0"_v,
                                                     .Name = "QUI",
                                                     .RuntimeCompatibility = {
                                                         "1.6.640.0"_v, "1.6.1130.0"_v, "1.6.1170.0"_v}});

    SKSEPluginInfo(.Version = "0.3.3.0"_v, .Name = "QUI")
} // namespace
