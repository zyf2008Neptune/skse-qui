#pragma once

#include <cstdint>
#include <map>
#include <RE/B/BSCoreTypes.h>
#include <RE/B/BSPointerHandle.h>
#include <RE/F/FormTypes.h>
#include <RE/T/TESForm.h>
#include <RE/T/TESObjectCONT.h>
#include <RE/T/TESObjectREFR.h>
#include <string_view>
#include <string>
#include <unordered_map>

namespace Core::Menu
{
    class PluginExplorer
    {
    public:
        class PluginInfo
        {
        public:
            using FormMap = std::map<RE::FormID, std::string_view>;
            using TypeMap = std::unordered_map<RE::FormType, FormMap>;

            PluginInfo(std::string_view a_name, uint32_t a_index) :
                _name(a_name),
                _index(a_index)
            {
            }

            auto AddForm(RE::TESForm* a_form, RE::FormType a_type) -> void;

            auto GetName() const noexcept -> std::string_view { return _name; }

            auto GetForms() -> TypeMap& { return _forms; }
            auto GetForms(RE::FormType a_type) -> FormMap& { return _forms[a_type]; }

            auto GetCount() -> size_t { return _count; }

        private:
            std::string_view _name{""};
            TypeMap _forms{};
            uint32_t _index{0};
            size_t _count{0};
        };

        using PluginList = std::map<uint32_t, PluginInfo>;
        using PluginCache = std::unordered_map<std::string, uint32_t>;

        static auto Init() -> void;
        static auto Reset() -> void { _plugins.clear(); }

        static auto GetPlugins() -> PluginList& { return _plugins; }
        static auto FindPlugin(uint32_t a_index) -> PluginInfo*;

        static auto GetContainer() -> RE::TESObjectREFRPtr;
        static auto OpenContainer(uint32_t a_index, RE::FormType a_type) -> bool;

    private:
        static auto InitContainer() -> void;
        static auto InitContainerRef() -> void;

        static auto GetTypeCount(RE::FormType a_type) -> uint32_t;

        static auto AddForms(RE::FormType a_type) -> void;

    private:
        static inline PluginList _plugins;
        static inline PluginCache _cache;

        //static inline RE::TESObjectCELL* _cell;
        static inline RE::TESObjectCONT* _container{nullptr};
        static inline RE::ObjectRefHandle _containerRef{};
    };
}
