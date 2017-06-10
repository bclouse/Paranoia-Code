#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <random>
#include <iomanip>
#include <fstream>
#include "Character.h"

using namespace std;

int main() {
	srand(time(NULL));
	PC dummy("Bryant","Computer","KH3","U");
	vector<PC> list;
	string player,character,sector,clearance;
	string input;
	bool stop_program = false;
	bool add_new = true;
	int n;

	while (1) {
		cout << ">> ";
		getline(cin,input);
		cout << endl;
		if (input.compare("new character") == 0) {
			add_new = true;
			cout << "Player:    ";	getline(cin,player);
			cout << "Character: ";	getline(cin,character);
			if (character.compare("random") == 0) {
				character = get_rand_name();
			}
			cout << "Sector:    ";	getline(cin,sector);
			// cout << "Clearance: ";	getline(cin,clearance);
			clearance = "R";
			dummy.generate(player,character,sector,clearance);
			dummy.display(false,true,false);
			list.push_back(dummy);
		} else if (input.compare("end") == 0) {
			break;
		} else if (input.compare("new npc") == 0) {
			add_new = true;
			player = "Bryant";
			cout << "Clearance  ";	getline(cin,clearance);	
			cout << "How many? "; 	cin >> n;	getline(cin,input);
			for (int i = 0; i < n; i++) {
				character = get_rand_name();
				switch (rand()%10) {
					case 0: sector = "WIO"; break;
					case 1: sector = "W0Z"; break;
					case 2: sector = "WHI"; break;
					case 3: sector = "XA7"; break;
					case 4: sector = "WJN"; break;
					case 5: sector = "WBW"; break;
					case 6: sector = "V40"; break;
					case 7: sector = "XLI"; break;
					case 8: sector = "WQF"; break;
					case 9: sector = "VUH"; break;
				}
				dummy.generate(player,character,sector,clearance);
				dummy.display(false,true,false);
				list.push_back(dummy);
			}
		} else if (input.compare("view all") == 0) {
			add_new = false;
			for (int i = 0; i < list.size(); i++) {
				list[i].display(false,true,false);
			}
		} else if (input.compare("save") == 0) {
			list[list.size()-1].save();
		} else {
			add_new = false;
			printf("Options:\n");
			printf("\t-new character\n");
			printf("\t-new npc\n");
			printf("\t-view all\n");
			printf("\t-save\n");
			// printf("\t-\n");
			printf("\t-end\n");
		}
		cout << endl;
		// if (add_new) {
		// 	dummy.generate(player,character,sector,clearance);
		// 	dummy.display(false,true,false);
		// 	list.push_back(dummy);
		// }
	}


	// PC test("Bryant", "Computer", "WIO");

	// test.set_skills();
	// test.display_skills();
	// cout << endl;


	return 0;
}