#include "TextField.hpp"

#include "System/Assert.hpp"

namespace SF
{
    TextField::TextField(const super& a_rhs) : super(a_rhs) {}

    TextField::TextField(super&& a_rhs) : super(std::move(a_rhs)) {}

    auto TextField::operator=(const super& a_rhs) -> TextField&
    {
        super::operator=(a_rhs);
        return *this;
    }

    auto TextField::operator=(super&& a_rhs) -> TextField&
    {
        super::operator=(std::move(a_rhs));
        return *this;
    }
} // namespace SF

namespace SF
{
    auto TextField::AddListener(Object& a_listener) -> bool
    {
        RE::GFxValue boolean;
        Assert(InvokeA("addListener", std::addressof(boolean), a_listener));
        return boolean.GetBool();
    }

    auto TextField::GetDepth() -> double
    {
        RE::GFxValue number;
        Assert((Invoke("getDepth", std::addressof(number))));
        return number.GetNumber();
    }

    auto TextField::RemoveListener(Object& a_listener) -> bool
    {
        RE::GFxValue boolean;
        Assert(InvokeA("removeListener", std::addressof(boolean), a_listener));
        return boolean.GetBool();
    }

    auto TextField::RemoveTextField() -> void { Assert(Invoke("removeTextField")); }

    auto TextField::ReplaceSel(std::string_view a_newText) -> void
    {
        Assert(InvokeA("replaceSel", nullptr, a_newText));
    }

    auto TextField::ReplaceText(double a_beginIndex, double a_endIndex, std::string_view a_newText) -> void
    {
        Assert(InvokeA("replaceText", nullptr, a_beginIndex, a_endIndex, a_newText));
    }
} // namespace SF

namespace SF
{
    auto TextField::AppendText(std::string_view a_newText) -> void
    {
        Assert(InvokeA("appendText", nullptr, a_newText));
    }

    auto TextField::AppendHtml(std::string_view a_newHtml) -> void
    {
        Assert(InvokeA("appendHtml", nullptr, a_newHtml));
    }

    auto TextField::GetCharIndexAtPoint(double a_x, double a_y) -> double
    {
        RE::GFxValue number;
        Assert(InvokeA("getCharIndexAtPoint", std::addressof(number), a_x, a_y));
        return number.GetNumber();
    }

    auto TextField::GetFirstCharInParagraph(double a_charIndex) -> double
    {
        RE::GFxValue number;
        Assert(InvokeA("getFirstCharInParagraph", std::addressof(number), a_charIndex));
        return number.GetNumber();
    }

    auto TextField::GetLineIndexAtPoint(double a_x, double a_y) -> double
    {
        RE::GFxValue number;
        Assert(InvokeA("getLineIndexAtPoint", std::addressof(number), a_x, a_y));
        return number.GetNumber();
    }

    auto TextField::GetLineLength(double a_lineIndex) -> double
    {
        RE::GFxValue number;
        Assert(InvokeA("getLineLength", std::addressof(number), a_lineIndex));
        return number.GetNumber();
    }

    auto TextField::GetLineMetrics(double a_lineIndex) -> Object
    {
        RE::GFxValue object;
        Assert(InvokeA("getLineMetrics", std::addressof(object), a_lineIndex));
        return Object(object);
    }

    auto TextField::GetLineOffset(double a_lineIndex) -> double
    {
        RE::GFxValue number;
        Assert(InvokeA("getLineOffset", std::addressof(number), a_lineIndex));
        return number.GetNumber();
    }

    auto TextField::GetLineText(double a_lineIndex) -> std::string
    {
        RE::GFxValue str;
        Assert(InvokeA("getLineText", std::addressof(str), a_lineIndex));
        return str.GetString();
    }

    auto TextField::CopyToClipboard(bool a_richClipboard, double a_startIndex, double a_endIndex) -> void
    {
        Assert(InvokeA("copyToClipboard", nullptr, a_richClipboard, a_startIndex, a_endIndex));
    }

    auto TextField::CutToClipboard(bool a_richClipboard, double a_startIndex, double a_endIndex) -> void
    {
        Assert(InvokeA("cutToClipboard", nullptr, a_richClipboard, a_startIndex, a_endIndex));
    }

    auto TextField::PasteFromClipboard(bool a_richClipboard, double a_startIndex, double a_endIndex) -> void
    {
        Assert(InvokeA("pasteFromClipboard", nullptr, a_richClipboard, a_startIndex, a_endIndex));
    }
} // namespace SF
