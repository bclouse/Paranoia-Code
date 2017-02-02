#include "Character.h"


//==============================
//	PC Class
//==============================

PC::PC(string player, string name, string sector) {
	Player = player;
	Name = name;
	Clearance = "R";
	Sector = sector;
	Clone = 1;
}

string PC::get_name(bool full_name) {
	assert (Clone < 10);
	string name;
	if (full_name) {
		name = Name+'-'+Clearance+'-'+Sector+'-'+char('0'+Clone);
	} else {
		name = Name;
	}
	return name;
}

void PC::display() {
	cout << Player << "'s character is: ";
	cout << get_name(true) << endl;
}

//==============================
//	Party Class
//==============================

void Party::add_member(PC member) {

}

void Party::gen_MBD() {

}

//==============================
//	NPC Class
//==============================

NPC::NPC(string name,string clearance,string sector) {

}

//==============================
//	NPC Class
//==============================
