
#pragma once

#include <string>
#include <functional>

class Menu;

struct Option
{
	const std::string prompt;

	std::function<void()> func;

	Option(const std::string& prompt, bool& flag);

	Option(const std::string& prompt, std::function<void()> func);

	Option(std::pair<const std::string, bool>& pair);

	Option(const std::string& prompt, Menu& menu, int& choice);

	Option(const std::string& prompt, std::string& value);

	Option(const std::string& prompt);

};