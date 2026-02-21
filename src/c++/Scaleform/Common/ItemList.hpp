#pragma once

#include <RE/G/GPtr.h>

#include "Item.hpp"
#include "Scaleform/CLIK/GFx/Controls/ScrollingList.hpp"

namespace SF
{
    class ItemList :
        public CLIK::GFx::Controls::ScrollingList
    {
        using super = CLIK::GFx::Controls::ScrollingList;

    public:
        using super::super;
        using super::operator=;

        ItemList() = default;
        ItemList(const ItemList&) = default;
        ItemList(ItemList&&) = default;
        ItemList(const super& a_rhs);
        ItemList(super&& a_rhs);

        ~ItemList() = default;

        auto operator=(const ItemList&) -> ItemList& = default;
        auto operator=(ItemList&&) -> ItemList& = default;
        auto operator=(const super& a_rhs) -> ItemList&;
        auto operator=(super&& a_rhs) -> ItemList&;

    public:
        auto Init(RE::GPtr<RE::GFxMovieView> a_view) -> void;
        auto ModSelectedIndex(double a_mod) -> void;
        auto Refresh() -> void;
        auto RestoreIndex(double a_idx) -> void;
        auto RestoreIndex(ptrdiff_t a_idx) -> void;
        auto SelectedItem() -> IItem::Ptr;

        template <class T>
        auto SelectedItem() -> std::shared_ptr<T>;

    public:
        auto clear() noexcept -> void { _impl.clear(); }
        auto push_back(IItem::Ptr a_item) -> void { _impl.push_back(std::move(a_item)); }

    private:
        RE::GPtr<RE::GFxMovieView> _view;
        RE::GFxValue _provider;
        std::vector<IItem::Ptr> _impl;
    };
}

#include "ItemList.inl"
