#include "Character.h"

//======================================================
//	PC Class
//======================================================

void PC::generate(string player, string name, string sector) {
	int index;
	Player = player;
	Name = name;
	Clearance = "R";
	Sector = sector;
	Clone = 1;
	Service.push_back(get_service(&index));
	Society.push_back(getSS(index));
	Mutant = getM();
	store = true;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 12; j++) {
			Skills[i][j].name = get_skill_names(i,j);
			Skills[i][j].value = 0;
		}
	}
	Category[0].name = "Management";
	Category[1].name = "Stealth";
	Category[2].name = "Violence";
	Category[3].name = "Hardware";
	Category[4].name = "Software";
	Category[5].name = "Wetware";
}

PC::PC(string player, string name, string sector) {
	generate(player,name,sector);
}

void PC::get_from_file(ifstream& file) {
	
}

string PC::get_name(bool full_name) {
	assert (Clone < 10);
	string name;
	if (full_name) {
		name = Name+'-'+Clearance+'-'+Sector+'-'+to_string(Clone);
	} else {
		name = Name;
	}
	return name;
}

void PC::display() {
	cout << Player << "'s character is: ";
	cout << get_name(true) << endl;

}

void PC::set_skills() {
	bool set_all = true;
	string input;

	if (set_all) {
		for (int i = 0; i < 6; i++) {
			cout << endl << Category[i].name << ": "; 	cin >> Category[i].value;
			if (i == 0) cout << "Use the following code to input values:\n\t\"-\" for +0\n\t\"s\" for a specialty\n\t\"d\" for a double specialty\n\t\"w\" for a weakness" << endl;
			while (1) {
				cout << "> ";
				cin >> input;
				if (input.size() <= 12) break;
				cout << ">Too many inputs!" << endl;
			}
			for (int j = 0; j < input.size(); j++) {
				switch (input[j]) {
					case 's': case 'S': 	Skills[i][j].value = Category[i].value+4; 	break;
					case 'd': case 'D': 	Skills[i][j].value = Category[i].value+8; 	break;
					case 'w': case 'W': 	Skills[i][j].value = 1; 							break;
					default: 				Skills[i][j].value = Category[i].value; 
				}
			}
			input.clear();
		} 
		cout << endl;
	}
}

void PC::display_skills() {
	for (int i = 0; i < 12; i++) {
		if (i == 0) {
			cout << setfill(' ');
			cout << setw(11) << left << Category[0].name << setw(2) << right << Category[0].value << "           \t";
			cout << setw(11) << left << Category[1].name << setw(2) << right << Category[1].value << "           \t";
			cout << setw(11) << left << Category[2].name << setw(2) << right << Category[2].value << "           \n\n";
		}
		for (int j = 0; j < 3; j++) {
			cout << setfill('_') << setw(22) << left << Skills[j][i].name;
			printf("%2d\t", Skills[j][i].value);
		}
		cout << endl;
	}
	cout << endl << endl;
	for (int i = 0; i < 12; i++) {
		if (i == 0) {
			cout << setfill(' ');
			cout << setw(11) << left << Category[3].name << setw(2) << right << Category[3].value << "           \t";
			cout << setw(11) << left << Category[4].name << setw(2) << right << Category[4].value << "           \t";
			cout << setw(11) << left << Category[5].name << setw(2) << right << Category[5].value << "           \n\n";
		}
		for (int j = 3; j < 6; j++) {
			cout << setfill('_') << setw(22) << left << Skills[j][i].name;
			printf("%2d\t", Skills[j][i].value);
		}
		cout << endl;			
	}
}

//======================================================
//	Party Class
//======================================================

void Party::add_member(PC* member) {
	party.push_back(member);
}

void Party::del_member(string member) {
	for (int i = 0; i < party.size(); i++) {
		if (member.compare(party.at(i)->get_name(false))) {
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
		party.at(i)->display();
	}
}
