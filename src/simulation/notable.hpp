
#pragma once

#include <string>
#include <optional>

#include "culture.hpp"
#include "gods.hpp"
#include "tribe.hpp"


enum class Attributes
{
    DIPLOMACY,
    BARTER,
    NUMBER_OF_ATTRIBURES
};

enum class Profficency
{
    POOR,
    OKAY,
    GOOD,
	VERY_GOOD,
	EXCELLENT,
	LEGENDARY,
	UNDEFINED
};

enum class Sex
{
	MALE,
	FEMALE,
	UNDEFINED
};

class Notable
{
	int id;
	std::string name;
	int age;
	God god;
	Sex sex;
	std::optional<Tribe> tribe;
	const Culture& culture;
	
	Profficency m_profficencys[(size_t)Attributes::NUMBER_OF_ATTRIBURES];

	Notable(const Culture & culture, Sex sex = Sex::UNDEFINED,  const std::string & name = std::string(), std::optional<int> age = std::nullopt, God god = God::UNDEFINED, std::optional<Tribe> tribe = std::nullopt);
};