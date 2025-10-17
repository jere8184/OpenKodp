
#pragma once

#include <string>
#include <vector>
#include <unordered_map>

namespace PageParser
{
	using Page = std::unordered_map<std::string, std::string>;
	
	std::vector<Page> get_pages(std::string kodp_xml);
}