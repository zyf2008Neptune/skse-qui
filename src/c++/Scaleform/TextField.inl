namespace SF
{
    inline TextField::TextField(const super& a_rhs) :
        super(a_rhs)
    {}

    inline TextField::TextField(super&& a_rhs) :
        super(std::move(a_rhs))
    {}

    inline auto TextField::operator=(const super& a_rhs) -> TextField&
    {
        super::operator=(a_rhs);
        return *this;
    }

    inline auto TextField::operator=(super&& a_rhs) -> TextField&
    {
        super::operator=(std::move(a_rhs));
        return *this;
    }
}

namespace SF
{
    inline auto TextField::AddListener(Object& a_listener) -> bool
    {
        RE::GFxValue boolean;
        Assert(InvokeA("addListener", std::addressof(boolean), a_listener));
        return boolean.GetBool();
    }

    inline auto TextField::GetDepth() -> double
    {
        RE::GFxValue number;
        Assert((Invoke("getDepth", std::addressof(number))));
        return number.GetNumber();
    }

    inline auto TextField::RemoveListener(Object& a_listener) -> bool
    {
        RE::GFxValue boolean;
        Assert(InvokeA("removeListener", std::addressof(boolean), a_listener));
        return boolean.GetBool();
    }

    inline auto TextField::RemoveTextField() -> void
    {
        Assert(Invoke("removeTextField"));
    }

    inline auto TextField::ReplaceSel(std::string_view a_newText) -> void
    {
        Assert(InvokeA("replaceSel", nullptr, a_newText));
    }

    inline auto TextField::ReplaceText(double a_beginIndex, double a_endIndex, std::string_view a_newText) -> void
    {
        Assert(InvokeA("replaceText", nullptr, a_beginIndex, a_endIndex, a_newText));
    }
}

namespace SF
{
    inline auto TextField::AppendText(std::string_view a_newText) -> void
    {
        Assert(InvokeA("appendText", nullptr, a_newText));
    }

    inline auto TextField::AppendHtml(std::string_view a_newHtml) -> void
    {
        Assert(InvokeA("appendHtml", nullptr, a_newHtml));
    }

    inline auto TextField::GetCharIndexAtPoint(double a_x, double a_y) -> double
    {
        RE::GFxValue number;
        Assert(InvokeA("getCharIndexAtPoint", std::addressof(number), a_x, a_y));
        return number.GetNumber();
    }

    inline auto TextField::GetFirstCharInParagraph(double a_charIndex) -> double
    {
        RE::GFxValue number;
        Assert(InvokeA("getFirstCharInParagraph", std::addressof(number), a_charIndex));
        return number.GetNumber();
    }

    inline auto TextField::GetLineIndexAtPoint(double a_x, double a_y) -> double
    {
        RE::GFxValue number;
        Assert(InvokeA("getLineIndexAtPoint", std::addressof(number), a_x, a_y));
        return number.GetNumber();
    }

    inline auto TextField::GetLineLength(double a_lineIndex) -> double
    {
        RE::GFxValue number;
        Assert(InvokeA("getLineLength", std::addressof(number), a_lineIndex));
        return number.GetNumber();
    }

    inline auto TextField::GetLineMetrics(double a_lineIndex) -> Object
    {
        RE::GFxValue object;
        Assert(InvokeA("getLineMetrics", std::addressof(object), a_lineIndex));
        return Object(object);
    }

    inline auto TextField::GetLineOffset(double a_lineIndex) -> double
    {
        RE::GFxValue number;
        Assert(InvokeA("getLineOffset", std::addressof(number), a_lineIndex));
        return number.GetNumber();
    }

    inline auto TextField::GetLineText(double a_lineIndex) -> std::string
    {
        RE::GFxValue str;
        Assert(InvokeA("getLineText", std::addressof(str), a_lineIndex));
        return str.GetString();
    }

    inline auto TextField::CopyToClipboard(bool a_richClipboard, double a_startIndex, double a_endIndex) -> void
    {
        Assert(InvokeA("copyToClipboard", nullptr, a_richClipboard, a_startIndex, a_endIndex));
    }

    inline auto TextField::CutToClipboard(bool a_richClipboard, double a_startIndex, double a_endIndex) -> void
    {
        Assert(InvokeA("cutToClipboard", nullptr, a_richClipboard, a_startIndex, a_endIndex));
    }

    inline auto TextField::PasteFromClipboard(bool a_richClipboard, double a_startIndex, double a_endIndex) -> void
    {
        Assert(InvokeA("pasteFromClipboard", nullptr, a_richClipboard, a_startIndex, a_endIndex));
    }
}
