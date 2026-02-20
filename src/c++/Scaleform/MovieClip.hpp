#pragma once

#include <string>
#include <string_view>

#include "Object.hpp"

namespace SF
{
    class MovieClip :
        public Object
    {
    private:
        using super = Object;

    public:
        using super::super;
        using super::operator=;

        MovieClip() = default;
        MovieClip(const MovieClip&) = default;
        MovieClip(MovieClip&&) = default;
        MovieClip(const super& a_rhs);
        MovieClip(super&& a_rhs);

        ~MovieClip() = default;

        auto operator=(const MovieClip&) -> MovieClip& = default;
        auto operator=(MovieClip&&) -> MovieClip& = default;
        auto operator=(const super& a_rhs) -> MovieClip&;
        auto operator=(super&& a_rhs) -> MovieClip&;

    public:
        // Properties
        auto Alpha() const -> double { return GetNumber("_alpha"); }
        auto Alpha(double a_alpha) -> void { SetNumber("_alpha", a_alpha); }
        auto BlendMode() const -> Object { return GetObject("blendMode"); }
        auto BlendMode(const Object& a_blendMode) -> void { SetObject("blendMode", a_blendMode); }
        auto CacheAsBitmap() const -> bool { return GetBoolean("cacheAsBitmap"); }
        auto CacheAsBitmap(bool a_cacheAsBitmap) -> void { SetBoolean("cacheAsBitmap", a_cacheAsBitmap); }
        auto Currentframe() const -> double { return GetNumber("_currentframe"); }
        auto Droptarget() const -> std::string { return GetString("_droptarget"); }
        auto Enabled() const -> bool { return GetBoolean("enabled"); }
        auto Enabled(bool a_enabled) -> void { SetBoolean("enabled", a_enabled); }
        auto FocusEnabled() const -> bool { return GetBoolean("focusEnabled"); }
        auto FocusEnabled(bool a_focusEnabled) -> void { SetBoolean("focusEnabled", a_focusEnabled); }
        auto Focusrect() const -> bool { return GetBoolean("_focusrect"); }
        auto Focusrect(bool a_focusrect) -> void { SetBoolean("_focusrect", a_focusrect); }
        auto Framesloaded() const -> double { return GetNumber("_framesloaded"); }
        auto Height() const -> double { return GetNumber("_height"); }
        auto Height(double a_height) -> void { SetNumber("_height", a_height); }
        auto HighQuality() const -> double { return GetNumber("_highquality"); }
        auto HighQuality(double a_highQuality) -> void { SetNumber("_highquality", a_highQuality); }
        auto HitArea() const -> Object { return GetObject("hitArea"); }
        auto HitArea(const Object& a_hitArea) -> void { SetObject("hitArea", a_hitArea); }
        auto LockRoot() const -> double { return GetNumber("_lockroot"); }
        auto LockRoot(double a_lockRoot) -> void { SetNumber("_lockroot", a_lockRoot); }
        auto Name() const -> std::string { return GetString("_name"); }
        auto Name(std::string_view a_name) -> void { SetString("_name", a_name); }
        auto OpaqueBackground() const -> double { return GetNumber("opaqueBackground"); }
        auto OpaqueBackground(double a_opaqueBackground) -> void { SetNumber("opaqueBackground", a_opaqueBackground); }
        auto Parent() const -> MovieClip { return GetObject("_parent"); }
        auto Parent(const MovieClip& a_parent) -> void { SetObject("_parent", a_parent); }
        auto Quality() const -> std::string { return GetString("_quality"); }
        auto Quality(std::string_view a_quality) -> void { SetString("_quality", a_quality); }
        auto Rotation() const -> double { return GetNumber("_rotation"); }
        auto Rotation(double a_rotation) -> void { SetNumber("_rotation", a_rotation); }
        auto ScrollRect() const -> Object { return GetObject("scrollRect"); }
        auto ScrollRect(const Object& a_scrollRect) -> void { SetObject("scrollRect", a_scrollRect); }
        auto SoundBufTime() const -> double { return GetNumber("_soundbuftime"); }
        auto SoundBufTime(double a_soundBufTime) -> void { SetNumber("_soundbuftime", a_soundBufTime); }
        auto TabChildren() const -> bool { return GetBoolean("tabChildren"); }
        auto TabChildren(bool a_tabChildren) -> void { SetBoolean("tabChildren", a_tabChildren); }
        auto TabEnabled() const -> bool { return GetBoolean("tabEnabled"); }
        auto TabEnabled(bool a_tabEnabled) -> void { SetBoolean("tabEnabled", a_tabEnabled); }
        auto TabIndex() const -> double { return GetNumber("tabIndex"); }
        auto TabIndex(double a_tabIndex) -> void { SetNumber("tabIndex", a_tabIndex); }
        auto Target() const -> std::string { return GetString("_target"); }
        auto TotalFrames() const -> double { return GetNumber("_totalframes"); }
        auto TrackAsMenu() const -> bool { return GetBoolean("trackAsMenu"); }
        auto TrackAsMenu(bool a_trackAsMenu) -> void { SetBoolean("trackAsMenu", a_trackAsMenu); }
        auto URL() const -> std::string { return GetString("_url"); }
        auto UseHandCursor() const -> bool { return GetBoolean("useHandCursor"); }
        auto UseHandCursor(bool a_useHandCursor) -> void { SetBoolean("useHandCursor", a_useHandCursor); }
        auto Visible() const -> bool { return GetBoolean("_visible"); }
        auto Visible(bool a_visible) -> void { SetBoolean("_visible", a_visible); }
        auto Width() const -> double { return GetNumber("_width"); }
        auto Width(double a_width) -> void { SetNumber("_width", a_width); }
        auto X() const -> double { return GetNumber("_x"); }
        auto X(double a_x) -> void { SetNumber("_x", a_x); }
        auto XMouse() const -> double { return GetNumber("_xmouse"); }
        auto XScale() const -> double { return GetNumber("_xscale"); }
        auto XScale(double a_xScale) -> void { SetNumber("_xscale", a_xScale); }
        auto Y() const -> double { return GetNumber("_y"); }
        auto Y(double a_y) -> void { SetNumber("_y", a_y); }
        auto YMouse() const -> double { return GetNumber("_ymouse"); }
        auto YScale() const -> double { return GetNumber("_yscale"); }
        auto YScale(double a_yScale) -> void { SetNumber("_yscale", a_yScale); }
    };
}

#include "MovieClip.inl"
