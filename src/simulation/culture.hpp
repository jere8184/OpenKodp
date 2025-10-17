#pragma once

#include "notable.hpp"

#include <vector>
#include <string>

class Culture 
{

public:
	const std::string & get_random_male_name() const;
	const std::string & get_random_female_name() const;
	const std::string & get_random_tribe_name() const;


private:
	std::vector<std::string> men_names;
	std::vector<std::string> women_names;
	
	std::vector<std::string> tribe_names;
};