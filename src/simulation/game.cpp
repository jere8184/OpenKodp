

#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <print>
#include <cctype>
#include <ranges>
#include <string_view>

#include "utils/page_parser.hpp"
#include "menu/menu.hpp"
#include "menu/option.hpp"

std::tuple<std::vector<int>, std::string> intro_seqence()
{
	std::vector<PageParser::Page> pages = PageParser::get_pages("Intro.plist");
	std::vector<int> choices;

	for (const PageParser::Page& page : pages)
	{
		if (page.contains("text"))
			std::println("\n{}\n", page.at("text")[0]);

		if (page.contains("responses"))
		{
			std::vector<Option> options;
			std::map<int, std::string> menu_strings;

			int i = 0;
			for (const std::string& response : page.at("responses"))
			{
				if(response.front() == '~')
					menu_strings[i] = std::string_view(&response[1], response.length() - 1);
				else
					options.push_back(response);
				i++;
			}
			
			choices.push_back(Menu(options, menu_strings).prompt());
		}
		else
		{
			Menu({Option("Continue")}).prompt();		
		}
	}

	Menu difficulty_menu = Menu({Option("Normal"), Option("Medium"), Option("Hard")});
	choices.push_back(0);

	Menu length_menu = Menu({Option("Short"), Option("Long")});
	choices.push_back(0);


	std::string tribe_name; 
	Menu({Option("Set Difficulty", difficulty_menu, choices[choices.size() - 1]),
		  Option("Set Length", length_menu, choices[choices.size() - 2]),
		  Option("Choose Tribe Name", tribe_name)}, {}, true).prompt();

	return {choices, tribe_name};
}


enum class WeddingChoice
{
	NOT_SET,
	ELMAL,
	ORLANTH,
	ERNALDA
};

enum class EarlyEventChoice
{			
	NOT_SET,
	CHALAN_ARROY,
	ODAYLA,
	ISSARIES,
	URALDA,
	BARNTAR,
	LHANKOR_MHY,
	PELLA,
	ROITINA
};

enum class ThrallsChoice
{
	NOT_SET,
	TOOK_THRALLS,
	DIDNT_TAKE_THRALLS
};

enum class EnemyChoice
{
	NOT_SET,
	BOZTAKANG,
	UKKAR_GRA,
	CHINKIS_MOR,
	TADA_THE_GREEN,
	VES_VENNA
};

enum class WarPeaceChoice
{
	NOT_SET,
	WAR,
	PEACE,
	BALLENCED
};

enum class FirstGodChoice
{
	NOT_SET,
	ANCESTORS,
	LIVING_DIETY,
	ELMAL,
	UROX,
	ODAYLA,
	ERNALDA,
	ORLANTH,
	ISSARIES,
	LHANKOR_MHY,
	CHALANA_ARROY,
	URALDA
};

enum class DragonChoice
{
	NOT_SET,
	HOSTILE,
	NEUTRAL,
	POSITIVE
};

enum class LandClaimChoice
{
	NOT_SET,
	SMALL,
	NORMAL,
	LOTS,
	HUGE
};

enum class DifficultyChoice
{
	NOT_SET,
	NORMAL,
	MEDIUM,
	HARD
};

enum class GameDurationChoice
{
	NOT_SET,
	SHORT,
	LONG
};


void play()
{
	std::println("Play Seclected!");
	auto res = intro_seqence();
	std::vector<int> choices = std::get<std::vector<int>>(res);

	WeddingChoice wedding_choice = static_cast<WeddingChoice>(choices[0]);
	EarlyEventChoice first_god_choice = static_cast<EarlyEventChoice>(choices[1]);
	ThrallsChoice thralls_choice = static_cast<ThrallsChoice>(choices[2]);
	EnemyChoice enemy_choice = static_cast<EnemyChoice>(choices[3]);
	WarPeaceChoice war_and_peace_chocie = static_cast<WarPeaceChoice>(choices[4]);
	FirstGodChoice fierst_god_chocie = static_cast<FirstGodChoice>(choices[5]);
	DragonChoice dragon_choice = static_cast<DragonChoice>(choices[6]);
	LandClaimChoice land_claim_choice = static_cast<LandClaimChoice>(choices[7]);
	DifficultyChoice diffculty_chocie = static_cast<DifficultyChoice>(choices[8]);
	GameDurationChoice game_duration_choice = static_cast<GameDurationChoice>(choices[9]);
	
	std::string tribe_name = std::get<std::string>(res);
}

void start_menu()
{
	Menu start_menu({Option("Play", play), Option("Settings", [&](){std::println("Settings Seclected!");})});
	start_menu.prompt();
}


int main ()
{
	start_menu();
}