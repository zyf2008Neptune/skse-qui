#pragma once

#include <string>
#include <string_view>

#include <RE/G/GFxMovieView.h>
#include <RE/G/GFxValue.h>
#include <RE/G/GPtr.h>
#include <RE/S/SFTypes.h>

namespace SF
{
    class Object
    {
    public:
        Object() = default;
        Object(const Object&) = default;
        Object(Object&&) = default;

        explicit Object(std::nullptr_t);
        explicit Object(double a_rhs);
        explicit Object(bool a_rhs);
        explicit Object(const char* a_rhs);
        explicit Object(std::string_view a_rhs);
        explicit Object(const wchar_t* a_rhs);
        explicit Object(std::wstring_view a_rhs);
        explicit Object(const RE::GFxValue& a_rhs);
        explicit Object(RE::GFxValue&& a_rhs);

        ~Object() = default;

        auto operator=(const Object& a_rhs) -> Object&;
        auto operator=(Object&& a_rhs) -> Object&;
        auto operator=(std::nullptr_t) -> Object&;
        auto operator=(double a_rhs) -> Object&;
        auto operator=(bool a_rhs) -> Object&;
        auto operator=(const char* a_rhs) -> Object&;
        auto operator=(std::string_view a_rhs) -> Object&;
        auto operator=(const wchar_t* a_rhs) -> Object&;
        auto operator=(std::wstring_view a_rhs) -> Object&;
        auto operator=(const RE::GFxValue& a_rhs) -> Object&;
        auto operator=(RE::GFxValue&& a_rhs) -> Object&;

        operator RE::GFxValue&();
        operator const RE::GFxValue&() const;

    public:
        auto Constructor() const -> Object;
        auto GetInstance() -> RE::GFxValue&;
        auto HasOwnProperty(std::string_view a_name) -> bool;
        auto IsPropertyEnumerable(std::string_view a_name) -> bool;
        auto IsPrototypeOf(Object& a_theClass) -> bool;
        auto Prototype() const -> Object;
        auto Resolve() const -> Object;
        auto Resolve(Object& a_resolve) -> void;
        auto ToString() -> std::string;
        auto Unwatch(std::string_view a_name) -> bool;
        auto ValueOf() -> Object;

    public:
        auto CreateArray(RE::GPtr<RE::GFxMovieView> a_view) -> void;
        auto GetBoolean(const char* a_path) const -> bool;
        auto GetNumber(const char* a_path) const -> double;
        auto GetObject(const char* a_path) const -> Object;
        auto GetString(const char* a_path) const -> std::string;
        auto Invoke(const char* a_name) -> bool;
        auto Invoke(const char* a_name, RE::GFxValue* a_result) -> bool;
        auto Invoke(const char* a_name, RE::GFxValue* a_result, const RE::GFxValue* a_args,
                    RE::UPInt a_numArgs) -> bool;
        auto IsArray() const -> bool;
        auto IsObject() const -> bool;
        auto SetBoolean(const char* a_path, bool a_bool) -> void;
        auto SetNumber(const char* a_path, double a_num) -> void;
        auto SetObject(const char* a_path, const Object& a_object) -> void;
        auto SetString(const char* a_path, const char* a_str) -> void;
        auto SetString(const char* a_path, std::string_view a_str) -> void;
        auto SetStringW(const char* a_path, const wchar_t* a_str) -> void;
        auto SetStringW(const char* a_path, std::wstring_view a_str) -> void;

        template <class... Args>
        auto InvokeA(const char* a_name, RE::GFxValue* a_result, Args... a_args) -> bool;

    protected:
        RE::GFxValue _instance{};
    };
}

#include "Object.inl"
