#pragma once

#include <optional>
#include <queue>
#include <stack>
#include <string>

#include "LocalePackage.hpp"

#include "src/c++/General/Singleton.hpp"

namespace Core
{
	class LocaleManager final :
		public ISingleton<LocaleManager>
	{
		using size_type = std::wstring::size_type;

	public:
		LocaleManager();

		void Load();

		bool SetLocale(const std::string& a_locale = "");

		std::string Translate(const std::string& a_key);

		void Dump();

	public:
		std::wstring GetLocalization(const std::wstring& a_key);
		std::string  GetLocalization(const std::string& a_key);

		LocalePackage& GetLocalePackage();

	private:
		std::wstring GetLocalizationImpl(const std::wstring& a_key);

		std::optional<std::wstring> FindLocalization(const std::wstring& a_key);

		bool GetNestedLocalizations(
			const std::wstring&       a_key,
			std::stack<size_type>&    a_stack,
			std::queue<std::wstring>& a_queue);

		bool InsertLocalizations(
			std::wstring&             a_localization,
			std::stack<size_type>&    a_stack,
			std::queue<std::wstring>& a_queue);

	private:
		std::wstring _locale{ L"ENGLISH" };
		std::wstring _localeDefault{ L"ENGLISH" };

		LocalePackage _packageENG;
		LocalePackage _packageLOC;
	};
}
