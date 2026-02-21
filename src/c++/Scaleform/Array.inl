#pragma once

namespace SF
{
    inline Array::Array(const super& a_rhs) :
        super(a_rhs)
    {}

    inline Array::Array(super&& a_rhs) :
        super(std::move(a_rhs))
    {}

    inline Array::Array(const RE::GFxValue& a_rhs) :
        super(a_rhs)
    {
        Assert(IsArray());
    }

    inline Array::Array(RE::GFxValue&& a_rhs) :
        super(std::move(a_rhs))
    {
        Assert(IsArray());
    }

    inline Array::Array(RE::GPtr<RE::GFxMovieView> a_rhs) :
        super()
    {
        CreateArray(std::move(a_rhs));
    }

    inline auto Array::operator=(const super& a_rhs) -> Array&
    {
        super::operator=(a_rhs);
        return *this;
    }

    inline auto Array::operator=(super&& a_rhs) -> Array&
    {
        super::operator=(std::move(a_rhs));
        return *this;
    }

    inline auto Array::operator=(const RE::GFxValue& a_rhs) -> Array&
    {
        super::operator=(a_rhs);
        Assert(IsArray());
        return *this;
    }

    inline auto Array::operator=(RE::GFxValue&& a_rhs) -> Array&
    {
        super::operator=(std::move(a_rhs));
        Assert(IsArray());
        return *this;
    }

    inline auto Array::operator=(RE::GPtr<RE::GFxMovieView> a_rhs) -> Array&
    {
        CreateArray(std::move(a_rhs));
        return *this;
    }
}

namespace SF
{
    inline auto Array::Concat(std::optional<std::reference_wrapper<Object>> a_value) -> Array
    {
        RE::GFxValue arr;
        if (a_value)
        {
            Assert(InvokeA("concat", std::addressof(arr), a_value->get()));
        }
        else
        {
            Assert(Invoke("concat", std::addressof(arr), nullptr, 0));
        }

        return Array(arr);
    }

    inline auto Array::Join(std::optional<std::string_view> a_delimiter) -> std::string
    {
        RE::GFxValue str;
        if (a_delimiter)
        {
            Assert(InvokeA("join", std::addressof(str), *a_delimiter));
        }
        else
        {
            Assert(Invoke("join", std::addressof(str), nullptr, 0));
        }

        return str.GetString();
    }

    inline auto Array::Pop() -> Object
    {
        RE::GFxValue object;
        Assert(Invoke("pop", std::addressof(object)));
        return Object(object);
    }

    inline auto Array::Push(Object& a_value) -> double
    {
        RE::GFxValue number;
        Assert(InvokeA("push", std::addressof(number), a_value));
        return number.GetNumber();
    }

    inline auto Array::Reverse() -> void
    {
        Assert(Invoke("reverse"));
    }

    inline auto Array::Shift() -> Object
    {
        RE::GFxValue object;
        Assert(Invoke("shift", std::addressof(object)));
        return Object(object);
    }

    inline auto Array::Splice(double a_startIndex, std::optional<double> a_deleteCount,
                              std::optional<Object> a_value) -> void
    {
        if (a_deleteCount)
        {
            if (a_value)
            {
                Assert(InvokeA("push", nullptr, a_startIndex, *a_deleteCount, *a_value));
            }
            else
            {
                Assert(InvokeA("push", nullptr, a_startIndex, *a_deleteCount));
            }
        }
        else
        {
            Assert(InvokeA("push", nullptr, a_startIndex));
        }
    }
}
