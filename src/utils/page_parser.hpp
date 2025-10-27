
#pragma once

#include <string>
#include <vector>
#include <unordered_map>

namespace PageParser
{
	using Values = std::vector<std::string>;

	using Page = std::unordered_map<std::string, Values>;
	
	std::vector<Page> get_pages(std::string kodp_xml);
}