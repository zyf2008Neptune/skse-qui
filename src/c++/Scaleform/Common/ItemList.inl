namespace SF
{
    inline ItemList::ItemList(const super& a_rhs) :
        super(a_rhs)
    {}

    inline ItemList::ItemList(super&& a_rhs) :
        super(std::move(a_rhs))
    {}

    inline auto ItemList::operator=(const super& a_rhs) -> ItemList&
    {
        super::operator=(a_rhs);
        return *this;
    }

    inline auto ItemList::operator=(super&& a_rhs) -> ItemList&
    {
        super::operator=(std::move(a_rhs));
        return *this;
    }
}

namespace SF
{
    inline auto ItemList::Init(RE::GPtr<RE::GFxMovieView> a_view) -> void
    {
        _view = a_view;
        a_view->CreateArray(std::addressof(_provider));
        DataProvider(SF::Array{_provider});
    }

    inline auto ItemList::ModSelectedIndex(double a_mod) -> void
    {
        const auto maxIdx = static_cast<double>(_impl.size()) - 1.0;
        if (maxIdx >= 0.0)
        {
            SelectedIndex(std::clamp(SelectedIndex() + a_mod, 0.0, maxIdx));
        }
    }

    inline auto ItemList::Refresh() -> void
    {
        _provider.ClearElements();

        for (const auto& elem : _impl)
        {
            _provider.PushBack(elem->GFxValue(*_view));
        }

        InvalidateData();
    }

    inline auto ItemList::RestoreIndex(double a_idx) -> void
    {
        RestoreIndex(static_cast<ptrdiff_t>(a_idx));
    }

    inline auto ItemList::RestoreIndex(ptrdiff_t a_idx) -> void
    {
        const auto ssize = std::ssize(_impl);
        if (0 <= a_idx && a_idx < ssize)
        {
            SelectedIndex(static_cast<double>(a_idx));
        }
        else if (!_impl.empty())
        {
            if (a_idx >= ssize)
            {
                SelectedIndex(static_cast<double>(ssize) - 1.0);
            }
            else
            {
                SelectedIndex(0.0);
            }
        }
        else
        {
            SelectedIndex(-1.0);
        }
    }

    inline auto ItemList::SelectedItem() -> IItem::Ptr
    {
        auto pos = static_cast<ptrdiff_t>(SelectedIndex());
        if (0 <= pos && pos < std::ssize(_impl))
        {
            return _impl[static_cast<size_t>(pos)];
        }

        return nullptr;
    }

    template <class T>
    inline auto ItemList::SelectedItem() -> std::shared_ptr<T>
    {
        return std::static_pointer_cast<T>(SelectedItem());
    }
}
