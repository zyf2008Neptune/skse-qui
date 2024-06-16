#pragma once
#include <string>
#include <cstdarg>
#include <vector>

#include "src/c++/quipch.hpp"
#include <RE/G/GFxLog.h>
#include <RE/G/GFxLogConstants.h>

namespace SF
{
    template <class T>
    class Logger : public RE::GFxLog
    {
    public:
        void LogMessageVarg(GFxLog::LogMessageType, const char* a_fmt, std::va_list a_argList) override
        {
            std::string fmt(a_fmt ? a_fmt : "");
            while (!fmt.empty() && fmt.back() == '\n')
            {
                fmt.pop_back();
            }

            std::va_list args;
            va_copy(args, a_argList);
            std::vector<char> buf(static_cast<size_t>(std::vsnprintf(0, 0, fmt.c_str(), a_argList) + 1));
            std::vsnprintf(buf.data(), buf.size(), fmt.c_str(), args);
            va_end(args);

            SKSE::log::info("{}: {}"sv, T::MENU_NAME, buf.data());
        }
    };
}
