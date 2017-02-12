#include "Character.h"

//======================================================
//	PC Class
//======================================================

void PC::Generate(string player, string name, string sector) {
	Player = player;
	Name = name;
	Clearance = "R";
	Sector = sector;
	Clone = 1;
}

PC::PC(string player, string name, string sector) {
	Generate(player,name,sector);
}

void PC::Get_from_file(ifstream file) {
	
}

string PC::Get_name(bool full_name) {
	assert (Clone < 10);
	string name;
	if (full_name) {
		name = Name+'-'+Clearance+'-'+Sector+'-'+to_string(Clone);
	} else {
		name = Name;
	}
	return name;
}

void PC::Display() {
	cout << Player << "'s character is: ";
	cout << Get_name(true) << endl;
}


//======================================================
//	Party Class
//======================================================

void Party::add_member(PC member) {
	party.push_back(&member);
}

void Party::del_member(string member) {
	for (int i = 0; i < party.size(); i++) {
		if (member.compare(party.at(i)->Get_name(false))) {
			member.erase(member.begin()+i);
			break;
		}
	}
}

void Party::gen_MBD() {
	vector<PC*> list = party;
	int j;
	for (int i = 0; (i < party.size()) && (i < 6); i++) {
		j = rand()%list.size();
		switch (i) {
			case 0: Team_Leader 				= list.at(j); break;
			case 1: Loyalty_Officer 		= list.at(j); break;
			case 2: CP_RO 						= list.at(j); break;
			case 3: Happiness_Officer 		= list.at(j); break;
			case 4: Equipment_Guy 			= list.at(j); break;
			case 5: Hygiene_Officer 		= list.at(j); break;
		}
		list.erase(list.begin()+j);
	}
}

void Party::display() {
	for (int i = 0; i < party.size(); i++) {
		party.at(i)->Display();
	}
}
