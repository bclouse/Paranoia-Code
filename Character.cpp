#include "Character.h"

//==============================
//	NPC Class
//==============================

NPC::NPC(string name, string clearance,string sector) {
	int cl;

	Name = name;
	Clearance = clearance;
	Sector = sector;

	if (Clearance.compare("R") == 0) {
		cl = 1;
	} else if (Clearance.compare("O") == 0) {
		cl = 2;
	} else if (Clearance.compare("Y") == 0) {
		cl = 3;
	} else if (Clearance.compare("G") == 0) {
		cl = 4;
	} else if (Clearance.compare("B") == 0) {
		cl = 5;
	} else if (Clearance.compare("I") == 0) {
		cl = 6;
	} else if (Clearance.compare("V") == 0) {
		cl = 7;
	} else if (Clearance.compare("U") == 0) {
		cl = 8;
	} else {
		Clearance = "IR";
		cl = 0;
	}

	switch (cl) {
		case 0: Clone = 1; break;
		case 1 : Clone = rand()%1+1; break;
		case 2 : Clone = rand()%2+1; break;
		case 3 : Clone = rand()%3+1; break;
		case 4 : Clone = rand()%3+1; break;
		case 5 : Clone = rand()%4+1; break;
		case 6 : Clone = rand()%4+1; break;
		case 7 : Clone = rand()%5+1; break;
		case 8 : Clone = rand()%6+1; break;
	}

	Mutant = getM();
	// get_power(Power);
	Access[0] = Access[1] = ROLL/5;
}

string NPC::Get_name(bool full_name) {
	string name;
	if (full_name) {
		name = Name+'-'+Clearance+'-'+Sector+'-'+to_string(Clone);
	} else {
		name = Name;
	}
	return name;
}

void NPC::Display() {
	cout << Get_name(true) << endl;
	cout << "Mutant: " << Mutant << endl;
	printf("Power: %d/%d\nAccess: %d/%d\n", Power[0],Power[1], Access[0], Access[1]);
}

//==============================
//	Functions Class
//==============================

int str2int(string input) {
	int output = 0;

	for (int i = 0; i < input.size(); i++) {
		if (input.at(i) >= '0' && input.at(i) <= 9) {
			output = output*10+input.at(i)-'0';
		} else {
			break;
		}
	}
	return output;
}

string get_rand_name() {
	string test;
	ifstream fp;
	fp.open("assets//Name_List.txt");

	fp.seekg(16*(rand()%2400),ios::beg);
	fp >> test;

	return test;
}

vector<string> get_files(ifstream& file) {
	vector<string> output;
	string dirname = DIRECTORY, fname;

	while (getline(file,fname)) {
		output.push_back(dirname+fname);
	}
	return output;
}

int get_power() {
	int dummy = ROLL;
	if (dummy < 8) {
		return 8;
	} else if (dummy > 18) {
		return 18;
	} else {
		return dummy;
	}
}

string get_skill_names(int main, int sub) {
	switch (main) {
		case 0:
			switch (sub) {
				case 0: return "Bootlicking"; break;
				case 1: return "Chutzpah"; break;
				case 2: return "Con Games"; break;
				case 3: return "Hygiene"; break;
				case 4: return "Interrogation"; break;
				case 5: return "Intimidation"; break;
				case 6: return "Moxie"; break;
				case 7: return "Oratory"; break;
			}
			break;
		case 1:
			switch (sub) {
				case 0: return "Concealment"; break;
				case 1: return "Disguise"; break;
				case 2: return "High Alert"; break;
				case 3: return "Security Systems"; break;
				case 4: return "Shadowing"; break;
				case 5: return "Sleight of Hand"; break;
				case 6: return "Sneaking"; break;
				case 7: return "Surveillance"; break;
			}
			break;
		case 2:
			switch (sub) {
				case 0: return "Agility"; break;
				case 1: return "Energy Weapons"; break;
				case 2: return "Demolition"; break;
				case 3: return "Field Weapons"; break;
				case 4: return "Fine Manipulation"; break;
				case 5: return "Hand Weapons"; break;
				case 6: return "Projectile Weapons"; break;
				case 7: return "Thrown Weapons"; break;
				case 8: return "Unarmed Combat"; break;
				case 9: return "Vehicular Combat"; break;
			}
			break;
		case 3:
			switch (sub) {
				case 0: return "Bot Ops & Maint."; break;
				case 1: return "Chemical Eng."; break;
				case 2: return "Electronic Eng."; break;
				case 3: return "Habitat Eng."; break;
				case 4: return "Mechanical Eng."; break;
				case 5: return "Nuclear Eng."; break;
				case 6: return "Vehicle Ops & Maint."; break;
				case 7: return "Weapon & Armor Maint."; break;
			}
			break;
		case 4:
			switch (sub) {
				case 0: return "Bot Programming"; break;
				case 1: return "C-Bay"; break;
				case 2: return "Data Analysis"; break;
				case 3: return "Data Search"; break;
				case 4: return "Financial Systems"; break;
				case 5: return "Hacking"; break;
				case 6: return "Operating Systems"; break;
				case 7: return "Vehicle Programming"; break;
			}
			break;
		case 5:
			switch (sub) {
				case 0: return "Biosciences"; break;
				case 1: return "Bioweapons"; break;
				case 2: return "Cloning"; break;
				case 3: return "Medical"; break;
				case 4: return "Outdoor Life"; break;
				case 5: return "Pharmatherapy"; break;
				case 6: return "Psychotherapy"; break;
				case 7: return "Suggestion"; break;
			}
			break;
	}
	return "\0";
}

string getM() {
	string output = rand_file_line(true,"assets//Mutations.txt");
	// long int dummy, end;
	// int size = 0;
	// char c, str[50];

	// FILE *fp = fopen("assets//Mutations.txt","r" );
	// fscanf(fp,"%c", &c);
	// size++;
	// while (c != '\n') {
	// 	fscanf(fp,"%c", &c);
	// 	size++;
	// }
	// fseek(fp, 0L, SEEK_END);
	// end = ftell(fp)+1;

	// dummy = (rand()%(end/size))*size;
	// fseek(fp, dummy, SEEK_SET);
	// fgets(str,50,fp);


	// string str = output;
	// for (int i = 0; i < output.size(); i++) {
		
	// }
	return output;
}

string get_service(int *index) {
	*index = rand()%8;
	string service;
	switch (*index) {
		case 0: service = "Armed Forces"; break;
		case 1: service = "Central Processing Unit"; break;
		case 2: service = "Housing Preservation and Development & Mind Control"; break;
		case 3: service = "Internal Security"; break;
		case 4: service = "Power Services"; break;
		case 5: service = "Production, Logistics & Commissary"; break;
		case 6: service = "Research and Design"; break;
		case 7: service = "Technical Services"; break;
	}
	return service;
}

string getSS(int sg) {
	int SSroll;// = rand() % 19 + 1;
	string SS;
	bool spy = false;
	if (spy)	SSroll = rand()%19+1;
	else 		SSroll = rand()%17+1;
	sg++;
	switch (sg) {
		case 1: 
		switch (SSroll) {
			case 1: case 2: case 3: SS = "Anit-Mutant"; break;
			case 4: case 5: case 6: SS = "Death Leopard"; break;
			case 7: case 8: case 9: SS = "Frankenstein Destroyers"; break;
			case 10: case 11: case 12: SS = "PURGE"; break;
			case 13: SS = "Communists"; break;
			case 14: SS = "FCCC-P"; break;
			case 15: SS = "Free Enterprise"; break;
			case 16: SS = "Pro Tech"; break;
			case 17: SS = "Psion"; break;
			case 18: SS = "Illuminati*"; break;
			case 19: SS = "Undercover Agent**"; break;
		} break;
		case 2:  
		switch (SSroll) {
			case 1: case 2: case 3: case 4: SS = "Computer Phreaks"; break;
			case 5: case 6: case 7: case 8: SS = "Corpore Metal"; break;
			case 9: case 10: SS = "FCCC-P"; break;
			case 11: case 12: SS = "Sierra Club"; break;
			case 13: SS = "Anti-Mutant"; break;
			case 14: SS = "Communists"; break;
			case 15: SS = "Pro Tech"; break;
			case 16: SS = "Psion"; break;
			case 17: SS = "PURGE"; break;
			case 18: SS = "Illuminati*"; break;
			case 19: SS = "Undercover Agent**"; break;
		} break;
		case 3:  
		switch (SSroll) {
			case 1: case 2: SS = "Anti-Mutant"; break;
			case 3: case 4: SS = "FCCC-P"; break;
			case 5: case 6: case 7: SS = "Humanists"; break;
			case 8: case 9: case 10: case 11: SS = "Romantics"; break;
			case 12: case 13: SS = "Sierra Club"; break;
			case 14: SS = "Communists"; break;
			case 15: SS = "Mystics"; break;
			case 16: SS = "Psion"; break;
			case 17: SS = "PURGE"; break;
			case 18: SS = "Illuminati*"; break;
			case 19: SS = "Undercover Agent**"; break;
		} break;
		case 4:  
		switch (SSroll) {
			case 1: case 2: case 3: SS = "Anti-Mutant"; break;
			case 4: case 5: case 6: SS = "Death Leopard"; break;
			case 7: case 8: case 9: SS = "FCCC-P"; break;
			case 10: case 11: case 12: SS = "Frankenstein Destroyers"; break;
			case 13: SS = "Communists"; break;
			case 14: SS = "Free Enterprise"; break;
			case 15: SS = "Pro Tech"; break;
			case 16: SS = "Psion"; break;
			case 17: SS = "PURGE"; break;
			case 18: SS = "Illuminati*"; break;
			case 19: SS = "Undercover Agent**"; break;
		} break;
		case 5:  
		switch (SSroll) {
			case 1: case 2: case 3: case 4: case 5: SS = "Free Enterprise"; break;
			case 6: case 7: case 8: case 9: SS = "Humanists"; break;
			case 10: case 11: SS = "Mystics"; break;
			case 12: case 13: SS = "Romantics"; break;
			case 14: SS = "Communists"; break;
			case 15: SS = "Pro Tech"; break;
			case 16: SS = "Psion"; break;
			case 17: SS = "Sierra Club"; break;
			case 18: SS = "Illuminati*"; break;
			case 19: SS = "Undercover Agent**"; break;
		} break;
		case 6:  
		switch (SSroll) {
			case 1: case 2: SS = "Computer Phreaks"; break;
			case 3: case 4: SS = "Death Leopard"; break;
			case 5: case 6: SS = "FCCC-P"; break;
			case 7: case 8: SS = "Sierra Club"; break;
			case 9: case 10: SS = "Free Enterprise"; break;
			case 11: case 12: SS = "Mystics"; break;
			case 13: case 14: SS = "Pro Tech"; break;
			case 15: case 16: SS = "PURGE"; break;
			case 17: SS = "Communists"; break;
			case 18: SS = "Illuminati*"; break;
			case 19: SS = "Undercover Agent**"; break;
		} break;
		case 7:  
		switch (SSroll) {
			case 1: case 2: case 3: SS = "Computer Phreaks"; break;
			case 4: case 5: case 6: SS = "Corpore Metal"; break;
			case 7: case 8: case 9: SS = "Pro Tech"; break;
			case 10: case 11: case 12: SS = "Psion"; break;
			case 13: case 14: case 15: SS = "PURGE"; break;
			case 16: SS = "FCCC-P"; break;
			case 17: SS = "Communists"; break;
			case 18: SS = "Illuminati*"; break;
			case 19: SS = "Undercover Agent**"; break;
		} break;
		case 8:  
		switch (SSroll) {
			case 1: case 2: SS = "Computer Phreaks"; break;
			case 3: case 4: SS = "Corpore Metal"; break;
			case 5: case 6: SS = "Death Leopard"; break;
			case 7: case 8: SS = "Frankenstein Destroyers"; break;
			case 9: case 10: SS = "Mystics"; break;
			case 11: case 12: SS = "Pro Tech"; break;
			case 13: case 14: SS = "Psion"; break;
			case 15: case 16: SS = "Sierra Club"; break;
			case 17: SS = "Communists"; break;
			case 18: SS = "Illuminati*"; break;
			case 19: SS = "Undercover Agent**"; break;
		} break;
		default: assert(0); break;
	}
	return SS;
}

string rand_file_line(bool same_length, string file_name) {		//same_length==true when all of the lines in a file are the same length
	string output;
	ifstream file(file_name);
	long int length = 1, size, pos;
	char c;
	// streamoff pos;


	if (file.is_open()) {
		getline(file,output);
		length = output.size()+1;
		file.seekg(0, file.end);
		size = (int)file.tellg()+1;
		pos = (rand()%(size/length))*length;
		file.seekg(pos, file.beg);

		// printf("Line Length: %ld\nFile Size: %ld\nRand Position: %ld\n", length, size, pos);
		getline(file,output);

		for (int i = 0; i < output.size(); i++) {
			if (output[i] == ' ' && output[i+1] == ' ' && i != output.size()-1) {
				output.erase(output.begin()+i,output.end());
			}
		}

		file.close();
	} else {
		cout << "FILE (" << file_name << ") DOES NOT EXIST" << endl;
	}
	return output;
}

string delete_endline(string str) {
	string dummy = str;

	dummy.erase(dummy.end());

	return dummy;
}