
#pragma once

#include <vector>
#include <map>


#include "option.hpp"

class Menu
{
public:
	Menu(const std::vector<Option>& options, const std::map<int, std::string>& menu_text = {}, bool is_persistant = false);

	int prompt();

private:	
	std::vector<Option> options;

	std::map<int, std::string> menu_text;

	bool is_persistant;
};