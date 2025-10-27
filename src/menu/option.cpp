
#include <string>
#include <functional>
#include <iostream>

#include "menu.hpp"
#include "option.hpp"

Option::Option(const std::string& prompt, bool& flag) :
	prompt(prompt)
{
	func = [&flag](){flag = true;};
}

Option::Option(const std::string& prompt, std::function<void()> func) :
	prompt(prompt),
	func(func)
{}

Option::Option(std::pair<const std::string, bool>& pair)
{
	Option(pair.first, pair.second);
}

Option::Option(const std::string& prompt, Menu& menu, int& choice) :
	prompt(prompt)
{
	func = [&menu, &choice](){choice = menu.prompt();};
}

Option::Option(const std::string& prompt, std::string& value) :
	prompt(prompt)
{
	auto take_input = [&value]()
	{
		auto is_not_alpha = [](char c){return !(bool)std::isalpha(c);};
		auto valid_str = [&is_not_alpha](const std::string& str){return std::ranges::find_if(str, is_not_alpha) == str.end();};
		
		do
		{
			if (!std::getline(std::cin, value) || !valid_str(value))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>().max(), '\n');
			}
			else
			{
				return;
			}

		} while(true);
	};

	func = take_input;
}

Option::Option(const std::string& prompt) :
	prompt(prompt)
{
	func = [](){};
}