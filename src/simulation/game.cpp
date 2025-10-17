

#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <print>


struct Option
{
	std::string prompt;
	std::function<void()> func;

	Option(const std::string& prompt, bool& flag) :
		prompt(prompt)
	{
		func = [&flag](){flag = true;};
	}

	Option(const std::string& prompt, std::function<void()> func) :
		prompt(prompt),
		func(func)
	{}

	Option(std::pair<const std::string, bool>& pair)
	{
		Option(pair.first, pair.second);
	}

	Option(const std::string& prompt) :
		prompt(prompt)
	{
		func = [](){};
	}

};

class Menu
{
public:
	Menu(const std::vector<Option>&& options) :
		options(options)
	{}

	void prompt() 
	{
		do
		{
			int input;

			for (int i = 0; i < options.size(); i++)
				std::println("{}) {}", i+1, options[i].prompt);

			if (!(std::cin >> input) || input > options.size() || input < -1 || input == 0)
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>().max(), '\n');
			}
			else
			{
				options[input-1].func();
				return;
			}
		} while(true);
	}
	
private:	
	std::vector<Option> options;
};


void intro_seqence()
{
	std::println("There once was a time when gods and people walked the earth together.\n"
					"Your clan traces its ancestry back to those times.\n"
					"Your clan history begins when you joined the forces of the\n"
 					"storm god Orlanth. Back then, Orlanth was simply one of many upstart, rebellious\n"
					"gods bent upon conquest of the world. Orlanth's unique contributions\n" 
					"at that time were personal honor, and a close kinship to the other deities\n"
					"who seemed to be on the winning side.\n");

	Menu next({Option("Continue")});
	next.prompt();
	std::println("After many tribulations, adventures, and discoveries\n"
		 		"Orlanth proved himself worthy of marrying Ernalda, the Earth Mother.\n"
				"The two formed the Marriage Ring, and created a great harmony in the world\n"
				"through this sacred bond. Your clan took part in the wedding ceremony.\n"
				"Most clans either whooped with Orlanth, or learned a secret from Ernalda.\n"
				"A few clans stood with Elmal, God of Horses and the Sun, as an honor guard.\n"
				
				"How did you prepare for the great marriage?\n");
	
	const std::string elmal_choice = "Your men and women donned gleaming armor\n"
								"and stood guard with Elmal, to protect the celebrants from Orlanth's; many enemies.\n";
	
	const std::string orlanth_choice = "Your men whooped with Orlanth, and drank the Eight Known Drinks,\n"
	 								"so that your heads would hurt during the ceremony.\n";

	const std::string ernalda_choice = "Your women withdrew with Ernalda, and learned a\n"
										"List of Names, which they promised not to repeat to the men.\n";

	bool chose_elmal = false;
	bool chose_orlanth = false;
	bool chose_ernalda = false;

	Menu ernalds_wedding({Option(elmal_choice, chose_elmal),
						 Option(orlanth_choice, chose_orlanth),
						 Option(ernalda_choice, chose_ernalda)});

	ernalds_wedding.prompt();

	std::println("Orlanth's struggle to remake the world was just beginning, and many other gods joined him in it.\n"
		 			"Orlanth fought Yelm the Bright Emperor, and undertook many wars of conquest.\n"
					"Other, more peaceful deeds were just as important. Your earliest Famous Event was:\n");
	
	std::pair<const std::string, bool> chalan_arroy = {"The Healing of Orlanth, when the merciful goddess Chalana Arroy joined Orlanth's tribe.", false};
	std::pair<const std::string, bool> odayla = {"The Hundred-Day Hunt, when Orlanth and his son Odayla tracked the Sky Bear.", false};
	std::pair<const std::string, bool> issaries = {"Jested's Settlement, where Orlanth and Issaries the Talking God outwitted foreign deities in a difficult negotiation.", false};
	std::pair<const std::string, bool> uralda = {"The Procession of the Animals, where Uralda the Cow Mother led the sacred herds into Orlanth's stead.", false};
	std::pair<const std::string, bool> barntar = {"When Barntar, son of Orlanth and Ernalda, learned of harnessing oxen to plow.", false};
	std::pair<const std::string, bool> lhankor_mhy = {"When Lhankor Mhy, the Knowing God, learned how to use the marking bone, which could mark signs of power upon anything.", false};
	std::pair<const std::string, bool> pella = {"When Pella, the pottery goddess, made the first pot to store grain in.", false};
	std::pair<const std::string, bool> roitina = {"When Roitina, lady of dance, first did the Clan-making Dance.", false};

	Menu first_god({chalan_arroy,
					odayla,
					issaries,
					uralda,
					barntar,
					lhankor_mhy,
					pella,
					roitina});
	
	first_god.prompt();

	std::println("Orlanth succeeded in remaking the world. Thus began the golden era called the Storm Age.\n"
		 			"Orlanth’s son Vingkot was a famous warlord during this time. Most people in the area were his followers.\n"
					"He introduced new principles, such as the rule of hospitality, which said that after you invited people into your steads,\n"
					"you could not attack or harm them. Thus was much treachery banished from Orlanthi society.\n"
					"Many who would not have survived agreed to his new ways in order to gain his protection.\n"
					"He was a great organizer, and helped the many scattered people form into new clans and tribes.\n"
					"Your clan was one of those aided by King Vingkot. After you proved yourselves robust and capable of survival,\n"
					"Vingkot placed a remnant people under your protection. They were the Nalda Bin, or \"Stick Farmers.\" You had a choice\n"
					"whether to make them into thralls (slaves) or adopt them as members of your clan.\n\n"
					"How did you add these strangers?\n");

	bool chose_to_take_thralls; 
	Menu take_thralls({Option("As thralls", chose_to_take_thralls),
						Option("As adpoted family", [&chose_to_take_thralls](){chose_to_take_thralls = false;})});

	take_thralls.prompt();

	std::println("The foes of the Vingkotlings were many, and your people fought hard against them. Which one of them in particular did you fight?");


	std::pair<const std::string, bool> boztakang = {"Boztakang the Troll Lord.", false};
	std::pair<const std::string, bool> ukkar_gra = {"Ukkar Gra, King of the Basmoli Beastmen.", false};
	std::pair<const std::string, bool> chinkis_mor = {"Chinkis Mor, the Elf Warlord.", false};
	std::pair<const std::string, bool> tada_the_green = {"Tada the Green, champion of the flat land&#10;called Prax.", false};
	std::pair<const std::string, bool> ves_venna = {"Ves Venna, Warlord of the Ice Tribe.", false};

	Menu chose_enemy({boztakang, ukkar_gra, chinkis_mor, tada_the_green, ves_venna});
	chose_enemy.prompt();

	std::println("The Storm Age ended in disaster, when the gods and creatures of Chaos came, and destroyed nearly everything.\n"
		 			"Orlanth and his allies fought hard, but Chaos almost always won. Many gods died, and new ones rose to prominence.\n"
					"Many people died, too. Catastrophes shook the world: the Sun Fall, the Rain of Blood, and the terrible Laughing Tsunami.\n"
					"The Darkness got so bad that even Orlanth and his companions had to abandon humans to their own destiny.\n"
					"Only a few deities, either small ones or weak ones, remained. The world stagnated and died.\n"
					"Your clan was diminished to a ragged handful of hardy survivors.\n");

	next.prompt();

	std::println("Heort the King was the leader who emerged amid the turmoil of the Darkness.\n"
		 			"The efforts of Heort and his companions helped set the world in order again.\n"
					"He created the laws that we follow to this day.\n"
					"One of the great distinctions which Heort discerned among his clans was\n"
					"that some of them tended towards either peace or war, while others\n"
					"maintained a balance between these two principles.\n\n"
					"Which kind was your clan?\n");

	std::pair<const std::string, bool> war {"war", false};
	std::pair<const std::string, bool> peace {"peace", false};
	std::pair<const std::string, bool> balenced {"balenced", false};

	Menu war_or_peace({war, peace, balenced});
	war_or_peace.prompt();
	
};


void play()
{
	std::println("Play Seclected!");
	intro_seqence();
}


void start_menu()
{
	Menu start_menu({Option("Play", play), Option("Settings", [&](){std::println("Settings Seclected!");})});
	start_menu.prompt();
}


int main ()
{
	start_menu();
}