
#include <random>

#include "notable.hpp"


Notable::Notable(const Culture & culture, Sex sex, const std::string & name, std::optional<int> age, God god, std::optional<Tribe> tribe) :
	culture(culture),
	name(name),
	age(age->value_or(-1)),
	god(god),
	tribe(tribe)
{
	if (sex == Sex::UNDEFINED)
		std::rand() % 2  == 0 ? this->sex = Sex::MALE : this->sex = Sex::FEMALE;

	if (name.empty())
	{
		if (sex == Sex::MALE)
			this->name = culture.get_random_male_name();
		else if (sex == Sex::FEMALE)
			this->name = culture.get_random_female_name();
	}

	if (age == std::nullopt)
		this->age = (std::rand() % 45) + 16;

	if (god == God::UNDEFINED)
	{
		int god_roll = std::rand() % (unsigned int)God::UNDEFINED - 1;
		this->god = (God)god_roll;
	}
	
}
