
#include <vector>

#include "date.hpp"




struct history_event
{
	date date;
};


struct history
{
	std::vector<history_event> events;
};