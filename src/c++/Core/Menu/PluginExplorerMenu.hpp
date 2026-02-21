#pragma once

#include <cstdint>
#include <string>
#include <string_view>

#include <RE/B/ButtonEvent.h>
#include <RE/F/FormTypes.h>
#include <RE/G/GFxMovieView.h>
#include <RE/G/GFxValue.h>
#include <RE/G/GPtr.h>
#include <RE/G/GRefCountBaseStatImpl.h>
#include <RE/I/IMenu.h>
#include <RE/I/InputEvent.h>
#include <RE/M/MenuEventHandler.h>

#include "Scaleform/CLIK/GFx/Controls/ButtonBar.hpp"
#include "Scaleform/Common/ItemList.hpp"
#include "Scaleform/MovieClip.hpp"
#include "Scaleform/TextField.hpp"

namespace Core::Menu
{
    class PluginExplorerMenu :
        public RE::IMenu,
        public RE::MenuEventHandler
    {
    public:
        using Super = RE::IMenu;
        using GRefCountBaseStatImpl::operator new;
        using GRefCountBaseStatImpl::operator delete;

    public:
        static constexpr std::string_view FILE_NAME{"PluginExplorerMenu"sv};
        static constexpr std::string_view MENU_NAME{"PluginExplorerMenu"sv};
        static constexpr std::int8_t SORT_PRIORITY{3};

        PluginExplorerMenu();
        ~PluginExplorerMenu() override;

        static auto Create() -> RE::IMenu* { return new PluginExplorerMenu(); }

        // override (IMenu)
        auto ProcessMessage(RE::UIMessage& a_message) -> RE::UI_MESSAGE_RESULTS override;
        auto AdvanceMovie(float a_interval, uint32_t a_currentTime) -> void override;
        auto RefreshPlatform() -> void override { UpdateButtonBar(); }

        // override (MenuEventHandler)
        auto CanProcess(RE::InputEvent* a_event) -> bool override;
        auto ProcessButton(RE::ButtonEvent* a_event) -> bool override;

    public:
        enum class Focus:std::uint8_t
        {
            Plugin,
            Form,
            Container,
            ContainerLoop
        };

    public:
        static auto IsOpen() -> bool;

        static auto Open() -> void;
        static auto Close() -> void;
        static auto Toggle() -> void;

        static auto SetFocus(Focus a_focus) -> void { _focus = a_focus; }
        static auto GetFocus() -> Focus { return _focus; }

        static auto GetPluginName() -> std::string { return _pluginName; }
        static auto GetPluginIndex() -> uint32_t { return _pluginIndex; }

        static auto GetFormName() -> std::string { return _formName; }
        static auto GetFormType() -> RE::FormType { return _formType; }

    private:
        auto Init() -> void;
        auto InitExtensions() -> void;

        auto OnOpen() -> void;
        auto OnClose() -> void;

        auto Refresh() -> void;
        auto RefreshPlugins() -> void;
        auto RefreshForms() -> void;
        auto RefreshUI() -> void;

        auto ModSelectedIndex(double a_mod) -> void;
        auto ModSelectedPage(double a_mod) -> void;

        auto Select() -> void;
        auto Back() -> void;

        auto UpdatePosition() -> void;
        auto UpdateTitle() -> void;
        auto UpdateButtonBar() -> void;

    private:
        RE::GPtr<RE::GFxMovieView> _view;

        SF::MovieClip _rootObj;
        SF::TextField _title;

        SF::ItemList _pluginList;
        SF::ItemList _formList;

        SF::CLIK::GFx::Controls::ButtonBar _buttonBar;
        RE::GFxValue _buttonBarProvider;

        uint32_t _heldGuard{0};
        uint32_t _heldCount{0};
        uint32_t _upHeld{0};
        uint32_t _downHeld{0};

        static inline auto _focus{Focus::Plugin};

        static inline std::string _pluginName;
        static inline uint32_t _pluginIndex{0};
        static inline double _pluginListIndex{0};

        static inline std::string _formName;
        static inline auto _formType{RE::FormType::None};
        static inline double _formListIndex{0};
    };
}
