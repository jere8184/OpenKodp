
#pragma once

#include <string>
#include <vector>
#include <map>
#include <set>

#include "notable.hpp"
#include "relation.hpp"
#include "map.hpp"
#include "notable.hpp"
#include "culture.hpp"


enum MagicPolls {HEALTH, WAR, DIPLOMACY, CROPS, TRADE, NUMBER_OF_MAGIC_POLLS};


const int STARTING_NOTABLES = 30;

class Tribe
{
public:
    struct Population
    {
		size_t m_total_population;
        size_t m_total_farmers;
        size_t m_total_children;
        size_t m_total_warriors;
        size_t m_total_nobles;
        size_t m_total_thralls;
        size_t m_total_crafters;
        size_t m_total_hunters;

		size_t m_wounded_population;
        size_t m_wounded_farmers;
        size_t m_wounded_children;
        size_t m_wounded_warriors;
        size_t m_wounded_nobles;
        size_t m_wounded_thralls;
        size_t m_wounded_crafters;
        size_t m_wounded_hunters;

		size_t m_sick_population;
        size_t m_sick_farmers;
        size_t m_sick_children;
        size_t m_sick_warriors;
        size_t m_sick_nobles;
        size_t m_sick_thralls;
        size_t m_sick_crafters;
        size_t m_sick_hunters;
    };

	struct  Party
	{
		Notable m_leader;
		size_t	m_warriors;
		size_t	m_levy;
		size_t	m_auxilaries;
	};
	

    struct Land
    {
        size_t total_land;
        size_t cropland;
        size_t pasture;
        size_t wildlands;
    };

    struct Animals
    {
        size_t cattle;
        size_t sheep;
        size_t pigs;
        size_t horses;
    };

	struct Ring
	{
		std::set<Notable*> members;
		Notable* leader;
	};

	void add_notable(const Notable &notable);	

private:
	size_t id;
    std::string name;
    Population population;
    size_t food;
    size_t goods;
    size_t cows;
    size_t magic;
    Culture culture;
	std::vector<Notable> notables;
	Ring ring;

    God god;
	Map::Location location;

	int allocated_magic[MagicPolls::NUMBER_OF_MAGIC_POLLS];

	std::map<Tribe*, Relation> relations;

};