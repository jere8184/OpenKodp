#pragma once

#include <string>
#include <vector>

#include "frontend/coord.hpp"

enum class widget_type {NOT_SET, BUTTON, SLIDER, NUMBER_OF_WIDGET_TYPES};
using widget_id = size_t;

class widget
{
public:
	widget(const std::string& name, widget_id id, widget_type type, coord postion) :
		name(name),
		id(id),
		type(type),
		postion(postion)
	{

	}

	std::string name;
	widget_id id;
	widget_type type;
	coord postion;

	std::vector<widget> sub_widgets;
};