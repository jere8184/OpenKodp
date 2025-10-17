#include "tribe.hpp"
#include "event.hpp"


enum Tactics {MANUVER, EVADE, SKIRMISH, CHARGE};
enum Objectives {PLUNDER, KILL, TAKE_PRISONERS, TAKE_LAND};


struct Battle
{
	Tribe::Party& m_attackers;
	Tribe::Party& m_defenders;

	int m_attacker_magic;
	int m_defender_magic;

	bool m_attacker_sacrafice_to_main_god = false;
	bool m_attacker_sacrafice_to_war_god = false;

	bool m_defender_sacrafice_to_war_god = false;
	bool m_defender_sacrafice_to_main_god = false;
};
