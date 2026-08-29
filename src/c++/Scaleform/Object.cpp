#include "Object.hpp"

#include "System/Assert.hpp"

namespace SF
{
    Object::Object(std::nullptr_t) : _instance(nullptr) {}

    Object::Object(double a_rhs) : _instance(a_rhs) {}

    Object::Object(bool a_rhs) : _instance(a_rhs) {}

    Object::Object(const char* a_rhs) : _instance(a_rhs) {}

    Object::Object(std::string_view a_rhs) : _instance(a_rhs) {}

    Object::Object(const wchar_t* a_rhs) : _instance(a_rhs) {}

    Object::Object(std::wstring_view a_rhs) : _instance(a_rhs) {}

    Object::Object(const RE::GFxValue& a_rhs) : _instance(a_rhs) { Assert(IsObject()); }

    Object::Object(RE::GFxValue&& a_rhs) : _instance(std::move(a_rhs)) { Assert(IsObject()); }

    auto Object::operator=(const Object& a_rhs) -> Object&
    {
        _instance = a_rhs._instance;
        return *this;
    }

    auto Object::operator=(Object&& a_rhs) -> Object&
    {
        _instance = std::move(a_rhs._instance);
        return *this;
    }

    auto Object::operator=(std::nullptr_t) -> Object&
    {
        _instance = nullptr;
        return *this;
    }

    auto Object::operator=(double a_rhs) -> Object&
    {
        _instance = a_rhs;
        return *this;
    }

    auto Object::operator=(bool a_rhs) -> Object&
    {
        _instance = a_rhs;
        return *this;
    }

    auto Object::operator=(const char* a_rhs) -> Object&
    {
        _instance = a_rhs;
        return *this;
    }

    auto Object::operator=(std::string_view a_rhs) -> Object&
    {
        _instance = a_rhs;
        return *this;
    }

    auto Object::operator=(const wchar_t* a_rhs) -> Object&
    {
        _instance = a_rhs;
        return *this;
    }

    auto Object::operator=(std::wstring_view a_rhs) -> Object&
    {
        _instance = a_rhs;
        return *this;
    }

    auto Object::operator=(const RE::GFxValue& a_rhs) -> Object&
    {
        _instance = a_rhs;
        Assert(IsObject());
        return *this;
    }

    auto Object::operator=(RE::GFxValue&& a_rhs) -> Object&
    {
        _instance = std::move(a_rhs);
        Assert(IsObject());
        return *this;
    }

    Object::operator RE::GFxValue&() { return _instance; }

    Object::operator const RE::GFxValue&() const { return _instance; }
} // namespace SF

namespace SF
{
    auto Object::GetInstance() -> RE::GFxValue& { return _instance; }

    auto Object::Constructor() const -> Object { return GetObject("constructor"); }

    auto Object::Prototype() const -> Object { return GetObject("__proto__"); }

    auto Object::Resolve() const -> Object { return GetObject("__resolve"); }

    auto Object::Resolve(const Object& a_resolve) -> void { SetObject("__resolve", a_resolve); }

    auto Object::HasOwnProperty(std::string_view a_name) -> bool
    {
        RE::GFxValue boolean;
        Assert(InvokeA("hasOwnProperty", std::addressof(boolean), a_name));
        return boolean.GetBool();
    }

    auto Object::IsPropertyEnumerable(std::string_view a_name) -> bool
    {
        RE::GFxValue boolean;
        Assert(InvokeA("isPropertyEnumerable", std::addressof(boolean), a_name));
        return boolean.GetBool();
    }

    auto Object::IsPrototypeOf(const Object& a_theClass) -> bool
    {
        RE::GFxValue boolean;
        Assert(InvokeA("isPrototypeOf", std::addressof(boolean), a_theClass));
        return boolean.GetBool();
    }

    auto Object::Unwatch(std::string_view a_name) -> bool
    {
        RE::GFxValue boolean;
        Assert(InvokeA("unwatch", std::addressof(boolean), a_name));
        return boolean.GetBool();
    }

    auto Object::ToString() -> std::string
    {
        RE::GFxValue str;
        Assert(Invoke("toString", std::addressof(str)));
        return str.GetString();
    }

    auto Object::ValueOf() -> Object
    {
        RE::GFxValue object;
        Assert(Invoke("valueOf", std::addressof(object)));
        return Object(object);
    }
} // namespace SF

namespace SF
{
    auto Object::CreateArray(RE::GPtr<RE::GFxMovieView> a_view) -> void
    {
        a_view->CreateArray(std::addressof(_instance));
        Assert(IsArray());
    }

    auto Object::GetBoolean(const char* a_path) const -> bool
    {
        RE::GFxValue boolean;
        Assert(_instance.GetMember(a_path, &boolean));
        return boolean.GetBool();
    }

    auto Object::GetNumber(const char* a_path) const -> double
    {
        RE::GFxValue number;
        Assert(_instance.GetMember(a_path, &number));
        return number.GetNumber();
    }

    auto Object::GetObject(const char* a_path) const -> Object
    {
        RE::GFxValue object;
        Assert(_instance.GetMember(a_path, &object));
        return Object(object);
    }

    auto Object::GetString(const char* a_path) const -> std::string
    {
        RE::GFxValue str;
        Assert(_instance.GetMember(a_path, &str));
        return str.GetString();
    }

    auto Object::Invoke(const char* a_name) -> bool { return _instance.Invoke(a_name, nullptr, nullptr, 0); }

    auto Object::Invoke(const char* a_name, RE::GFxValue* a_result) -> bool
    {
        return _instance.Invoke(a_name, a_result, nullptr, 0);
    }

    auto Object::Invoke(const char* a_name, RE::GFxValue* a_result, const RE::GFxValue* a_args, RE::UPInt a_numArgs)
        -> bool
    {
        return _instance.Invoke(a_name, a_result, a_args, a_numArgs);
    }

    auto Object::IsArray() const -> bool { return _instance.IsArray(); }

    auto Object::IsObject() const -> bool { return _instance.IsObject(); }

    auto Object::SetBoolean(const char* a_path, bool a_boolean) -> void
    {
        RE::GFxValue boolean(a_boolean);
        Assert(_instance.SetMember(a_path, boolean));
    }

    auto Object::SetNumber(const char* a_path, double a_number) -> void
    {
        RE::GFxValue number(a_number);
        Assert(_instance.SetMember(a_path, number));
    }

    auto Object::SetObject(const char* a_path, const Object& a_object) -> void
    {
        Assert(_instance.SetMember(a_path, a_object));
    }

    auto Object::SetString(const char* a_path, const char* a_str) -> void
    {
        RE::GFxValue str(a_str);
        Assert(_instance.SetMember(a_path, str));
    }

    auto Object::SetString(const char* a_path, std::string_view a_str) -> void
    {
        RE::GFxValue str(a_str);
        Assert(_instance.SetMember(a_path, str));
    }

    auto Object::SetStringW(const char* a_path, const wchar_t* a_str) -> void
    {
        RE::GFxValue str(a_str);
        Assert(_instance.SetMember(a_path, str));
    }

    auto Object::SetStringW(const char* a_path, std::wstring_view a_str) -> void
    {
        RE::GFxValue str(a_str);
        Assert(_instance.SetMember(a_path, str));
    }
} // namespace SF
