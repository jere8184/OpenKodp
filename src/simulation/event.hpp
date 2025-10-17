#pragma once

#include <stddef.h>
#include <String>

#include "tribe.hpp"

class Event
{
	size_t m_id;

	std::string m_name;
	std::string m_text;
	Option		m_options[5];
	Tribe*		m_us = nullptr;
	Tribe* 		m_them = nullptr;
	Notable*		m_participants[5];
};


struct Option
{
	std::string 	m_text;
	Notable*		m_pSupporters[7] = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
	Event*			m_triggered_event = nullptr;
};