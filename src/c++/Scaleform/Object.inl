#pragma once
#include "System/Assert.hpp"

namespace SF
{
    inline Object::Object(std::nullptr_t) :
        _instance(nullptr)
    {}

    inline Object::Object(double a_rhs) :
        _instance(a_rhs)
    {}

    inline Object::Object(bool a_rhs) :
        _instance(a_rhs)
    {}

    inline Object::Object(const char* a_rhs) :
        _instance(a_rhs)
    {}

    inline Object::Object(std::string_view a_rhs) :
        _instance(a_rhs)
    {}

    inline Object::Object(const wchar_t* a_rhs) :
        _instance(a_rhs)
    {}

    inline Object::Object(std::wstring_view a_rhs) :
        _instance(a_rhs)
    {}

    inline Object::Object(const RE::GFxValue& a_rhs) :
        _instance(a_rhs)
    {
        Assert(IsObject());
    }

    inline Object::Object(RE::GFxValue&& a_rhs) :
        _instance(std::move(a_rhs))
    {
        Assert(IsObject());
    }

    inline auto Object::operator=(const Object& a_rhs) -> Object&
    {
        _instance = a_rhs._instance;
        return *this;
    }

    inline auto Object::operator=(Object&& a_rhs) -> Object&
    {
        _instance = std::move(a_rhs._instance);
        return *this;
    }

    inline auto Object::operator=(std::nullptr_t) -> Object&
    {
        _instance = nullptr;
        return *this;
    }

    inline auto Object::operator=(double a_rhs) -> Object&
    {
        _instance = a_rhs;
        return *this;
    }

    inline auto Object::operator=(bool a_rhs) -> Object&
    {
        _instance = a_rhs;
        return *this;
    }

    inline auto Object::operator=(const char* a_rhs) -> Object&
    {
        _instance = a_rhs;
        return *this;
    }

    inline auto Object::operator=(std::string_view a_rhs) -> Object&
    {
        _instance = a_rhs;
        return *this;
    }

    inline auto Object::operator=(const wchar_t* a_rhs) -> Object&
    {
        _instance = a_rhs;
        return *this;
    }

    inline auto Object::operator=(std::wstring_view a_rhs) -> Object&
    {
        _instance = a_rhs;
        return *this;
    }

    inline auto Object::operator=(const RE::GFxValue& a_rhs) -> Object&
    {
        _instance = a_rhs;
        Assert(IsObject());
        return *this;
    }

    inline auto Object::operator=(RE::GFxValue&& a_rhs) -> Object&
    {
        _instance = std::move(a_rhs);
        Assert(IsObject());
        return *this;
    }

    inline Object::operator RE::GFxValue&()
    {
        return _instance;
    }

    inline Object::operator const RE::GFxValue&() const
    {
        return _instance;
    }
}

namespace SF
{
    inline auto Object::GetInstance() -> RE::GFxValue&
    {
        return _instance;
    }

    inline auto Object::Constructor() const -> Object
    {
        return GetObject("constructor");
    }

    inline auto Object::Prototype() const -> Object
    {
        return GetObject("__proto__");
    }

    inline auto Object::Resolve() const -> Object
    {
        return GetObject("__resolve");
    }

    inline auto Object::Resolve(Object& a_resolve) -> void
    {
        SetObject("__resolve", a_resolve);
    }

    inline auto Object::HasOwnProperty(std::string_view a_name) -> bool
    {
        RE::GFxValue boolean;
        Assert(InvokeA("hasOwnProperty", std::addressof(boolean), a_name));
        return boolean.GetBool();
    }

    inline auto Object::IsPropertyEnumerable(std::string_view a_name) -> bool
    {
        RE::GFxValue boolean;
        Assert(InvokeA("isPropertyEnumerable", std::addressof(boolean), a_name));
        return boolean.GetBool();
    }

    inline auto Object::IsPrototypeOf(Object& a_theClass) -> bool
    {
        RE::GFxValue boolean;
        Assert(InvokeA("isPrototypeOf", std::addressof(boolean), a_theClass));
        return boolean.GetBool();
    }

    inline auto Object::Unwatch(std::string_view a_name) -> bool
    {
        RE::GFxValue boolean;
        Assert(InvokeA("unwatch", std::addressof(boolean), a_name));
        return boolean.GetBool();
    }

    inline auto Object::ToString() -> std::string
    {
        RE::GFxValue str;
        Assert(Invoke("toString", std::addressof(str)));
        return str.GetString();
    }

    inline auto Object::ValueOf() -> Object
    {
        RE::GFxValue object;
        Assert(Invoke("valueOf", std::addressof(object)));
        return Object(object);
    }
}

namespace SF
{
    inline auto Object::CreateArray(RE::GPtr<RE::GFxMovieView> a_view) -> void
    {
        a_view->CreateArray(std::addressof(_instance));
        Assert(IsArray());
    }

    inline auto Object::GetBoolean(const char* a_path) const -> bool
    {
        RE::GFxValue boolean;
        Assert(_instance.GetMember(a_path, &boolean));
        return boolean.GetBool();
    }

    inline auto Object::GetNumber(const char* a_path) const -> double
    {
        RE::GFxValue number;
        Assert(_instance.GetMember(a_path, &number));
        return number.GetNumber();
    }

    inline auto Object::GetObject(const char* a_path) const -> Object
    {
        RE::GFxValue object;
        Assert(_instance.GetMember(a_path, &object));
        return Object(object);
    }

    inline auto Object::GetString(const char* a_path) const -> std::string
    {
        RE::GFxValue str;
        Assert(_instance.GetMember(a_path, &str));
        return str.GetString();
    }

    inline auto Object::Invoke(const char* a_name) -> bool
    {
        return _instance.Invoke(a_name, nullptr, nullptr, 0);
    }

    inline auto Object::Invoke(const char* a_name, RE::GFxValue* a_result) -> bool
    {
        return _instance.Invoke(a_name, a_result, nullptr, 0);
    }

    inline auto Object::Invoke(const char* a_name, RE::GFxValue* a_result, const RE::GFxValue* a_args,
                               RE::UPInt a_numArgs) -> bool
    {
        return _instance.Invoke(a_name, a_result, a_args, a_numArgs);
    }

    inline auto Object::IsArray() const -> bool
    {
        return _instance.IsArray();
    }

    inline auto Object::IsObject() const -> bool
    {
        return _instance.IsObject();
    }

    inline auto Object::SetBoolean(const char* a_path, bool a_boolean) -> void
    {
        RE::GFxValue boolean(a_boolean);
        Assert(_instance.SetMember(a_path, boolean));
    }

    inline auto Object::SetNumber(const char* a_path, double a_number) -> void
    {
        RE::GFxValue number(a_number);
        Assert(_instance.SetMember(a_path, number));
    }

    inline auto Object::SetObject(const char* a_path, const Object& a_object) -> void
    {
        Assert(_instance.SetMember(a_path, a_object));
    }

    inline auto Object::SetString(const char* a_path, const char* a_str) -> void
    {
        RE::GFxValue str(a_str);
        Assert(_instance.SetMember(a_path, str));
    }

    inline auto Object::SetString(const char* a_path, std::string_view a_str) -> void
    {
        RE::GFxValue str(a_str);
        Assert(_instance.SetMember(a_path, str));
    }

    inline auto Object::SetStringW(const char* a_path, const wchar_t* a_str) -> void
    {
        RE::GFxValue str(a_str);
        Assert(_instance.SetMember(a_path, str));
    }

    inline auto Object::SetStringW(const char* a_path, std::wstring_view a_str) -> void
    {
        RE::GFxValue str(a_str);
        Assert(_instance.SetMember(a_path, str));
    }

    template <class... Args>
    inline auto Object::InvokeA(const char* a_name, RE::GFxValue* a_result, Args... a_args) -> bool
    {
        std::array<RE::GFxValue, sizeof...(a_args)> args{(std::forward<Args>(a_args), ...)};
        return Invoke(a_name, a_result, args.data(), args.size());
    }
}
