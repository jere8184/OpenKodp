#pragma once

#include "tribe.hpp"
#include "notable.hpp"

#include <vector>

enum struct Opinion {POOR, NEUTUAL, GOOD, NUMBER_OF_OPINIONS};
enum struct Stance {HOSTILE, AGRESSIVE, OPPITUNISTIC, COOPERATIVE, CONSILITORY, NUMBER_OF_STANCES};
enum struct State {WAR, PEACE, ALLIANCE};


struct HistoryEvent;

//inter-tribe relationsions
class Relation
{
	Tribe& m_them;
	int m_opinion;
	int m_favours_owed;
	std::vector<HistoryEvent> m_history;
	bool m_is_allied;
	bool m_is_fueding;
	bool m_is_paying_tribute;
	bool m_is_trading;

	void cattle_raid(Tribe::Party& party);
	void raid(Tribe::Party& party);
	void trade(Tribe::Party& party);
	void request_peace(Notable& diplomat);
	void demand_tribute(Notable& diplomat);
	void request_alliance(Notable& diplomat);
};