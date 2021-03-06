#include "Character.h"

//======================================================
//	PC Class
//======================================================

void PC::generate(string player, string name, string sector,string clearance) {
	int index;
	Service.clear();
	Society.clear();

	Player = player;
	Name = name;
	Clearance = clearance;
	Sector = sector;
	Clone = 1;
	Degree = 1;
	Service.push_back(get_service(&index));
	Society.push_back(getSS(index));
	Mutant = getM();
	store = true;
	Treason = 1;
	Commendation = 0;
	Credits[0] = 1000;
	Credits[1] = 0;
	Power[0] = Power[1] = get_power();
	Access[0] = Access[1] = rand()%5+1;
	Perversity = 25;
	for (int i = 0; i < 6; i++) {
		Category[i].value = 0;
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
	Category[6].name = "Uncommon";
	Category[7].name = "Unlikely";
	Category[8].name = "Unhealthy";
}

PC::PC(string player, string name, string sector,string clearance) {
	generate(player,name,sector,clearance);
}

void PC::get_from_file(ifstream& file) {
	
}

string PC::get_name(bool full_name, bool clone) {
	// assert (Clone < 10);
	string name;
	if (full_name) {
		name = Name+'-'+Clearance+'-'+Sector;
		if (clone) name += '-'+to_string(Clone);
	} else {
		name = Name;
	}
	return name;
}

void PC::display(bool see_skills,bool see_secret,bool items) {
	cout << "=========================================" << endl;
	cout << Player << "'s character is: ";
	cout << get_name(true,true) << endl;
	printf("Service Group:  %s",Service[0].c_str());
	for (int i = 1; i < Service.size(); i++) {
		printf(" << %s",Service[i].c_str());
	}
	cout << endl;
	if (see_skills) display_skills(false);
	if (see_secret) {
		printf("Secret Society: %s",Society[0].c_str());
		for (int i = 1; i < Society.size(); i++) {
			printf(" << %s",Society[i].c_str());
		}
		cout << endl;
		printf("Degree:________ %d\n", Degree);
		printf("Mutant Ability: %s\n", Mutant.c_str());
		// if (see_skills) display_skills(true);
		printf("Perversity:____ %d\n", Perversity);
		printf("Power:_________ %d/%d\n", Power[0], Power[1]);
		printf("Access:________ %d/%d\n", Access[0], Access[1]);
		printf("Credits:_______ %d/%d\n", Credits[0], Credits[1]);
		printf("Treason:_______ -%d, +%d\n", Treason, Commendation);
		//if (items) display_items();
	}
	cout << "=========================================" << endl;
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

void PC::display_skills(bool secret) {
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

void PC::save() {
	ifstream blank ("assets//Blank_Character.txt");
	string dummy = "assets//characters//";
	ofstream file;
	int rewrite;
	int num;
	char c;

	dummy += get_name(false,false)+".txt";
	file.open(dummy);

	getline(blank,dummy);	dummy.erase(dummy.end()-1);	file << dummy << Player << endl;
	getline(blank,dummy);	dummy.erase(dummy.end()-1);	file << dummy << Name << endl;
	getline(blank,dummy);	dummy.erase(dummy.end()-1);	file << dummy << Clearance << endl;
	getline(blank,dummy);	dummy.erase(dummy.end()-1);	file << dummy << Sector << endl;
	getline(blank,dummy);	dummy.erase(dummy.end()-1);	file << dummy << Clone << endl;

	getline(blank,dummy);	dummy.erase(dummy.end()-1);	file << dummy << Service[0];
	for (int i = 1; i < Service.size(); i++) {file << ", " << Service[i];}
									file << endl;
	for (int j = 0; j < 6; j++) {
		getline(blank,dummy);	dummy.erase(dummy.end()-1);	file << dummy << setw(3) << setfill(' ') << left << Category[j].value << resetiosflags(ios::showbase);
		rewrite = 0;
		for (int i = 0; i < 12; i++) {
			if (!Skills[j][i].name.empty()) {
				c = 'a' + Skills[j][i].value;
				file << c;
				if (i >= 10 || (j != 2 && i >= 8)) rewrite++;				
			} else {
				file << '/';
			}

			
		}
		if (rewrite > 0) {
			if (j == 2)	num = 10;
			else			num = 8;
			for (int k = num; k < num+rewrite; k++) {
				if (k > num)	file << ", " << Skills[j][k].name;
				else				file << Skills[j][k].name;
			}
		}
		file << endl;
	}

	getline(blank,dummy);	dummy.erase(dummy.end()-1);	file << dummy << Society[0];
	for (int i = 1; i < Society.size(); i++) {file << ", " << Society[i];}
									file << endl;

	getline(blank,dummy);	dummy.erase(dummy.end()-1);	file << dummy << Mutant << endl;

	getline(blank,dummy);	dummy.erase(dummy.end()-1);	file << dummy;
	for (int i = 0; i < Uncommon.size(); i++) {
		if (i != 0)	file << ", ";
		file << Uncommon[i].name << "/" << Uncommon[i].value;
	}
	file << endl;
	// cout << "uncommon" << endl;
	getline(blank,dummy);	dummy.erase(dummy.end()-1);	file << dummy;
	for (int i = 0; i < Unlikely.size(); i++) {
		if (i != 0)	file << ", ";
		file << Unlikely[i].name << "/" << Unlikely[i].value;
	}
	file << endl;
	// cout << "unlikely" << endl;
	getline(blank,dummy);	dummy.erase(dummy.end()-1);	file << dummy;
	for (int i = 0; i < Unhealthy.size(); i++) {
		if (i != 0)	file << ", ";
		file << Unhealthy[i].name << "/" << Unhealthy[i].value;
	}
	file << endl;
	// cout << "uncommon" << endl;

	getline(blank,dummy);	dummy.erase(dummy.end()-1);	file << dummy << Power[0] << '/' << Power[1] << endl;
	getline(blank,dummy);	dummy.erase(dummy.end()-1);	file << dummy << Access[0] << '/' << Access[1] << endl;
	getline(blank,dummy);	dummy.erase(dummy.end()-1);	file << dummy << Credits[0] << '/' << Credits[1] << endl;
	getline(blank,dummy);	dummy.erase(dummy.end()-1);	file << dummy << Perversity << endl;
	getline(blank,dummy);	file << dummy << endl;
	for (int i = 0; i < Items.size();i++) {
		file << Items[i] << endl;
	}

	blank.close();
	file.close();
}

//======================================================
//	Party Class
//======================================================

void Party::add_member(PC* member) {
	party.push_back(member);
}

void Party::del_member(string member) {
	for (int i = 0; i < party.size(); i++) {
		if (member.compare(party.at(i)->get_name(false,false))) {
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
		party.at(i)->display(false,true,false);
	}
}
