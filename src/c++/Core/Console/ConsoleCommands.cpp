#include "ConsoleCommands.hpp"

#include <cstdint>
#include <RE/C/CommandTable.h>
#include <RE/C/Console.h>
#include <RE/U/UI.h>
#include <SKSE/Logger.h>

namespace Core::ConsoleCommand
{
    void Clear::Register()
    {
        const auto info = RE::SCRIPT_FUNCTION::LocateConsoleCommand("DumpNiUpdates");
        if (!info)
        {
            SKSE::log::info("Console command (DumpNiUpdates) not found. Skipping...");
            return;
        }

        info->functionName = FUNC_NAME;
        info->shortName = SHORT_NAME;
        info->helpString = HELP_STR;
        info->numParams = 0;
        info->params = nullptr;
        info->executeFunction = &Execute;
        info->conditionFunction = nullptr;
        info->referenceFunction = false;
    }

    bool Clear::Execute(const RE::SCRIPT_PARAMETER*, RE::SCRIPT_FUNCTION::ScriptData*,
                        RE::TESObjectREFR*, RE::TESObjectREFR*, RE::Script*, RE::ScriptLocals*, double&, uint32_t&)
    {
        const auto task = SKSE::GetTaskInterface();
        task->AddUITask([]
        {
            const auto ui = RE::UI::GetSingleton();
            const auto console = ui ? ui->GetMenu<RE::Console>() : nullptr;
            const auto movie = console ? console->uiMovie : nullptr;
            if (movie)
                movie->Invoke("Console.ClearHistory", nullptr, nullptr, 0);
        });

        return true;
    }

    void Register()
    {
        Clear::Register();
    }
}
