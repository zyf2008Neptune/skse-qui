#pragma once

#include "Object.hpp"

namespace SF
{
    class TextField :
        public Object
    {
    private:
        using super = Object;

    public:
        using super::super;
        using super::operator=;

        TextField() = default;
        TextField(const TextField&) = default;
        TextField(TextField&&) = default;
        TextField(const super& a_rhs);
        TextField(super&& a_rhs);

        ~TextField() = default;

        auto operator=(const TextField&) -> TextField& = default;
        auto operator=(TextField&&) -> TextField& = default;
        auto operator=(const super& a_rhs) -> TextField&;
        auto operator=(super&& a_rhs) -> TextField&;

    public:
        // Properties
        auto Alpha() const -> double { return GetNumber("_alpha"); }
        auto Alpha(double a_value) -> void { SetNumber("_alpha", a_value); }
        auto AntiAliasType() const -> std::string { return GetString("antiAliasType"); }
        auto AntiAliasType(std::string_view a_value) -> void { SetString("antiAliasType", a_value); }
        auto AutoSize() const -> Object { return GetObject("autoSize"); }
        auto AutoSize(const Object& a_value) -> void { SetObject("autoSize", a_value); }
        auto Background() const -> bool { return GetBoolean("background"); }
        auto Background(bool a_value) -> void { SetBoolean("background", a_value); }
        auto BackgroundColor() const -> double { return GetNumber("backgroundColor"); }
        auto BackgroundColor(double a_value) -> void { SetNumber("backgroundColor", a_value); }
        auto Border() const -> bool { return GetBoolean("border"); }
        auto Border(bool a_value) -> void { SetBoolean("border", a_value); }
        auto BorderColor() const -> double { return GetNumber("borderColor"); }
        auto BorderColor(double a_value) -> void { SetNumber("borderColor", a_value); }
        auto BottomScroll() const -> double { return GetNumber("bottomScroll"); }
        auto CondenseWhite() const -> bool { return GetBoolean("condenseWhite"); }
        auto CondenseWhite(bool a_value) -> void { SetBoolean("condenseWhite", a_value); }
        auto EmbedFonts() const -> bool { return GetBoolean("embedFonts"); }
        auto EmbedFonts(bool a_value) -> void { SetBoolean("embedFonts", a_value); }
        auto GridFitType() const -> std::string { return GetString("gridFitType"); }
        auto GridFitType(std::string_view a_value) -> void { SetString("gridFitType", a_value); }
        auto Height() const -> double { return GetNumber("_height"); }
        auto Height(double a_value) -> void { SetNumber("_height", a_value); }
        auto HighQuality() const -> double { return GetNumber("_highquality"); }
        auto HighQuality(double a_value) -> void { SetNumber("_highquality", a_value); }
        auto HScroll() const -> double { return GetNumber("hscroll"); }
        auto HScroll(double a_value) -> void { SetNumber("hscroll", a_value); }
        auto HTML() const -> bool { return GetBoolean("html"); }
        auto HTML(bool a_value) -> void { SetBoolean("html", a_value); }
        auto HTMLText() const -> std::string { return GetString("htmlText"); }
        auto HTMLText(std::string_view a_value) -> void { SetString("htmlText", a_value); }
        auto Length() const -> double { return GetNumber("length"); }
        auto MaxChars() const -> double { return GetNumber("maxChars"); }
        auto MaxChars(double a_value) -> void { SetNumber("maxChars", a_value); }
        auto MaxHScroll() const -> double { return GetNumber("maxhscroll"); }
        auto MaxScroll() const -> double { return GetNumber("maxscroll"); }
        auto MouseWheelEnabled() const -> bool { return GetBoolean("mouseWheelEnabled"); }
        auto MouseWheelEnabled(bool a_value) -> void { SetBoolean("mouseWheelEnabled", a_value); }
        auto Multiline() const -> bool { return GetBoolean("multiline"); }
        auto Multiline(bool a_value) -> void { SetBoolean("multiline", a_value); }
        auto Name() const -> std::string { return GetString("_name"); }
        auto Name(std::string_view a_value) -> void { SetString("_name", a_value); }
        auto Password() const -> bool { return GetBoolean("password"); }
        auto Password(bool a_value) -> void { SetBoolean("password", a_value); }
        auto Quality() const -> std::string { return GetString("_quality"); }
        auto Quality(std::string_view a_value) -> void { SetString("_quality", a_value); }
        auto Restrict() const -> std::string { return GetString("restrict"); }
        auto Restrict(std::string_view a_value) -> void { SetString("restrict", a_value); }
        auto Rotation() const -> double { return GetNumber("_rotation"); }
        auto Rotation(double a_value) -> void { SetNumber("_rotation", a_value); }
        auto Scroll() const -> double { return GetNumber("scroll"); }
        auto Scroll(double a_value) -> void { SetNumber("scroll", a_value); }
        auto Selectable() const -> bool { return GetBoolean("selectable"); }
        auto Selectable(bool a_value) -> void { SetBoolean("selectable", a_value); }
        auto Sharpness() const -> double { return GetNumber("sharpness"); }
        auto Sharpness(double a_value) -> void { SetNumber("sharpness", a_value); }
        auto SoundBufTime() const -> double { return GetNumber("_soundbuftime"); }
        auto SoundBufTime(double a_value) -> void { SetNumber("_soundbuftime", a_value); }
        auto TabEnabled() const -> bool { return GetBoolean("tabEnabled"); }
        auto TabEnabled(bool a_value) -> void { SetBoolean("tabEnabled", a_value); }
        auto TabIndex() const -> double { return GetNumber("tabIndex"); }
        auto TabIndex(double a_value) -> void { SetNumber("tabIndex", a_value); }
        auto Target() const -> std::string { return GetString("_target"); }
        auto Text() const -> std::string { return GetString("text"); }
        auto Text(std::string_view a_value) -> void { SetString("text", a_value); }
        auto TextColor() const -> double { return GetNumber("textColor"); }
        auto TextColor(double a_value) -> void { SetNumber("textColor", a_value); }
        auto TextHeight() const -> double { return GetNumber("textHeight"); }
        auto TextHeight(double a_value) -> void { SetNumber("textHeight", a_value); }
        auto TextWidth() const -> double { return GetNumber("textWidth"); }
        auto TextWidth(double a_value) -> void { SetNumber("textWidth", a_value); }
        auto Thickness() const -> double { return GetNumber("thickness"); }
        auto Thickness(double a_value) -> void { SetNumber("thickness", a_value); }
        auto Type() const -> std::string { return GetString("type"); }
        auto Type(std::string_view a_value) -> void { SetString("type", a_value); }
        auto URL() const -> std::string { return GetString("_url"); }
        auto Variable() const -> std::string { return GetString("variable"); }
        auto Variable(std::string_view a_value) -> void { SetString("variable", a_value); }
        auto Visible() const -> bool { return GetBoolean("_visible"); }
        auto Visible(bool a_value) -> void { SetBoolean("_visible", a_value); }
        auto Width() const -> double { return GetNumber("_width"); }
        auto Width(double a_value) -> void { SetNumber("_width", a_value); }
        auto WordWrap() const -> bool { return GetBoolean("wordWrap"); }
        auto WordWrap(bool a_value) -> void { SetBoolean("wordWrap", a_value); }
        auto X() const -> double { return GetNumber("_x"); }
        auto X(double a_value) -> void { SetNumber("_x", a_value); }
        auto XMouse() const -> double { return GetNumber("_xmouse"); }
        auto XScale() const -> double { return GetNumber("_xscale"); }
        auto XScale(double a_value) -> void { SetNumber("_xscale", a_value); }
        auto Y() const -> double { return GetNumber("_y"); }
        auto Y(double a_value) -> void { SetNumber("_y", a_value); }
        auto YMouse() const -> double { return GetNumber("_ymouse"); }
        auto YScale() const -> double { return GetNumber("_yscale"); }
        auto YScale(double a_value) -> void { SetNumber("_yscale", a_value); }

        // GFx Properties
        auto AlwaysShowSelection() const -> bool { return GetBoolean("alwaysShowSelection"); }
        auto AlwaysShowSelection(bool a_value) -> void { SetBoolean("alwaysShowSelection", a_value); }
        auto AutoFit() const -> bool { return GetBoolean("autoFit"); }
        auto AutoFit(bool a_value) -> void { SetBoolean("autoFit", a_value); }
        auto CaretIndex() const -> double { return GetNumber("caretIndex"); }
        auto CaretIndex(double a_value) -> void { SetNumber("caretIndex", a_value); }
        auto FocusGroup() const -> double { return GetNumber("focusGroup"); }
        auto FocusGroup(double a_value) -> void { SetNumber("focusGroup", a_value); }
        auto FontScaleFactor() const -> double { return GetNumber("fontScaleFactor"); }
        auto FontScaleFactor(double a_value) -> void { SetNumber("fontScaleFactor", a_value); }
        auto HitTestDisable() const -> bool { return GetBoolean("hitTestDisable"); }
        auto HitTestDisable(bool a_value) -> void { SetBoolean("hitTestDisable", a_value); }
        auto InactiveSelectionBkgColor() const -> double { return GetNumber("inactiveSelectionBkgColor"); }
        auto InactiveSelectionBkgColor(double a_value) -> void { SetNumber("inactiveSelectionBkgColor", a_value); }
        auto InactiveSelectionTextColor() const -> double { return GetNumber("inactiveSelectionTextColor"); }
        auto InactiveSelectionTextColor(double a_value) -> void { SetNumber("inactiveSelectionTextColor", a_value); }
        auto NoAutoSelection() const -> bool { return GetBoolean("noAutoSelection"); }
        auto NoAutoSelection(bool a_value) -> void { SetBoolean("noAutoSelection", a_value); }
        auto NoTranslate() const -> bool { return GetBoolean("noTranslate"); }
        auto NoTranslate(bool a_value) -> void { SetBoolean("noTranslate", a_value); }
        auto NumLines() const -> double { return GetNumber("numLines"); }
        auto NumLines(double a_value) -> void { SetNumber("numLines", a_value); }
        auto SelectionBeginIndex() const -> double { return GetNumber("selectionBeginIndex"); }
        auto SelectionBeginIndex(double a_value) -> void { SetNumber("selectionBeginIndex", a_value); }
        auto SelectionEndIndex() const -> double { return GetNumber("selectionEndIndex"); }
        auto SelectionEndIndex(double a_value) -> void { SetNumber("selectionEndIndex", a_value); }
        auto SelectionBkgColor() const -> double { return GetNumber("selectionBkgColor"); }
        auto SelectionBkgColor(double a_value) -> void { SetNumber("selectionBkgColor", a_value); }
        auto SelectionTextColor() const -> double { return GetNumber("selectionTextColor"); }
        auto SelectionTextColor(double a_value) -> void { SetNumber("selectionTextColor", a_value); }
        auto TextAutoSize() const -> std::string { return GetString("textAutoSize"); }
        auto TextAutoSize(std::string_view a_value) -> void { SetString("textAutoSize", a_value); }
        auto TopmostLevel() const -> bool { return GetBoolean("topmostLevel"); }
        auto TopmostLevel(bool a_value) -> void { SetBoolean("topmostLevel", a_value); }
        auto UseRichTextClipboard() const -> bool { return GetBoolean("useRichTextClipboard"); }
        auto UseRichTextClipboard(bool a_value) -> void { SetBoolean("useRichTextClipboard", a_value); }
        auto VerticalAlign() const -> std::string { return GetString("verticalAlign"); }
        auto VerticalAlign(std::string_view a_value) -> void { SetString("verticalAlign", a_value); }
        auto VerticalAutoSize() const -> std::string { return GetString("verticalAutoSize"); }
        auto VerticalAutoSize(std::string_view a_value) -> void { SetString("verticalAutoSize", a_value); }

    public:
        // Methods
        auto AddListener(Object& a_listener) -> bool;
        auto GetDepth() -> double;
        auto RemoveListener(Object& a_listener) -> bool;
        auto RemoveTextField() -> void;
        auto ReplaceSel(std::string_view a_newText) -> void;
        auto ReplaceText(double a_beginIndex, double a_endIndex, std::string_view a_newText) -> void;

        // GFx Methods
        auto AppendText(std::string_view a_newText) -> void;
        auto AppendHtml(std::string_view a_newHtml) -> void;
        auto GetCharIndexAtPoint(double a_x, double a_y) -> double;
        auto GetFirstCharInParagraph(double a_charIndex) -> double;
        auto GetLineIndexAtPoint(double a_x, double a_y) -> double;
        auto GetLineLength(double a_lineIndex) -> double;
        auto GetLineMetrics(double a_lineIndex) -> Object;
        auto GetLineOffset(double a_lineIndex) -> double;
        auto GetLineText(double a_lineIndex) -> std::string;
        auto CopyToClipboard(bool a_richClipboard, double a_startIndex, double a_endIndex) -> void;
        auto CutToClipboard(bool a_richClipboard, double a_startIndex, double a_endIndex) -> void;
        auto PasteFromClipboard(bool a_richClipboard, double a_startIndex, double a_endIndex) -> void;
    };
}

#include "TextField.inl"
