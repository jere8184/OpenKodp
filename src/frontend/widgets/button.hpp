
#pragma once

#include <functional>

#include "widget.hpp"
#include "frontend/sprite.hpp"

class button : public widget 
{
public:
	button(const std::string& name, widget_id id, coord postion, const sprite* up_sprite, const sprite* down_sprite, const std::function<void()> on_click_cb) :
		widget(name, id, widget_type::BUTTON, postion),
		on_click_cb(on_click_cb),
		up_sprite(up_sprite),
		down_sprite(down_sprite)
		{};

	const sprite* up_sprite;
	const sprite* down_sprite;
	std::function<void()> on_click_cb;

	void on_click()
	{
		on_click_cb();
	}
};