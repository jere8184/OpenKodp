

#include <print>
#include <iostream>
#include <vector>

#include "option.hpp"
#include "menu.hpp"

Menu::Menu(const std::vector<Option>& options, const std::map<int, std::string>& menu_text, bool is_persistant) :
	options(options),
	menu_text(menu_text),
	is_persistant(is_persistant)
{};


int Menu::prompt()
{
	bool can_exit = true;

	if (is_persistant)
	{
		can_exit = false;
		this->options.emplace_back(Option("Exit", can_exit));
	}

	do
	{
		int input;

		for (int i = 0; i < options.size(); i++)
		{
			if (menu_text.contains(i))
				std::println("{}", menu_text.at(i));
			std::println("{}) {}\n", i+1, options[i].prompt);
		}

		if (!(std::cin >> input) || input > options.size() || input < -1 || input == 0)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>().max(), '\n');
		}
		else
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>().max(), '\n');

			options[input-1].func();

			if (!this->is_persistant || can_exit)
				return input;

		}

	} while(true);
}