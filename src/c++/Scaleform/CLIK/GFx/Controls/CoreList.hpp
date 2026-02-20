#pragma once

#include <string>
#include <string_view>

#include "src/c++/Scaleform/Array.hpp"
#include "src/c++/Scaleform/CLIK/GFx/Core/UIComponent.hpp"

namespace SF::CLIK::GFx::Controls
{
    class CoreList :
        public Core::UIComponent
    {
    private:
        using super = Core::UIComponent;

    public:
        using super::super;
        using super::operator=;

        CoreList() = default;
        CoreList(const CoreList&) = default;
        CoreList(CoreList&&) = default;
        CoreList(const super& a_rhs);
        CoreList(super&& a_rhs);

        ~CoreList() = default;

        auto operator=(const CoreList&) -> CoreList& = default;
        auto operator=(CoreList&&) -> CoreList& = default;
        auto operator=(const super& a_rhs) -> CoreList&;
        auto operator=(super&& a_rhs) -> CoreList&;

    public:
        auto AvailableWidth() const -> double { return GetNumber("availableWidth"); }
        auto AvailableHeight() const -> double { return GetNumber("availableHeight"); }
        auto DataProvider() const -> Object { return GetObject("dataProvider"); }
        auto DataProvider(const Object& a_dataProvider) -> void { SetObject("dataProvider", a_dataProvider); }
        auto ItemRenderer() const -> std::string { return GetString("itemRenderer"); }
        auto ItemRenderer(std::string_view a_itemRenderer) -> void { SetString("itemRenderer", a_itemRenderer); }
        auto LabelField() const -> std::string { return GetString("labelField"); }
        auto LabelField(std::string_view a_labelField) -> void { SetString("labelField", a_labelField); }
        auto RendererInstanceName() const -> std::string { return GetString("rendererInstanceName"); }

        auto RendererInstanceName(std::string_view a_rendererInstanceName) -> void
        {
            SetString("rendererInstanceName", a_rendererInstanceName);
        }

        auto SelectedIndex() const -> double { return GetNumber("selectedIndex"); }
        auto SelectedIndex(double a_selectedIndex) -> void { SetNumber("selectedIndex", a_selectedIndex); }

    public:
        auto ItemToLabel(Object& a_item) -> std::string;
        auto InvalidateData() -> void;
        auto ScrollToIndex(double a_index) -> void;
        auto SetRendererList(Array& a_value) -> void;
        auto ToString() -> std::string;
    };
}

#include "CoreList.inl"
