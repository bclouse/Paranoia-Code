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
}


string get_rand_name(ifstream file) {
	string output;
	long int loc = rand()%2400;

	file.seekg(loc*16,ios::beg);
	getline(file,output);

	return output;
}

string getM(int n) {	
	switch (n) {
		case 1: return "Not A Mutant"; break;
		case 2: return "X-Ray Vision"; break;
		case 3: return "Shapeshift"; break;
		case 4: return "Charm"; break;
		case 5: return "Hypersenses"; break;
		case 6: return "Kinetic Blast"; break;
		case 7: return "Electroshock"; break;
		case 8: return "Matter Eater"; break;
		case 9: return "Adrenaline Control"; break;
		case 10: return "Kirby Absorption"; break;
		case 11: return "Acid Spit"; break;
		case 12: return "Adaptive Metabolism"; break;
		case 13: return "Adhesive Skin"; break;
		case 14: return "Bounce"; break;
		case 15: return "Uncanny Luck"; break;
		case 16: return "Doom Magnet"; break;
		case 17: return "Chameleon"; break;
		case 18: return "Color Touch"; break;
		case 19: return "Ink Spray"; break;
		case 20: return "MACHINE EMPATHY"; break;
		case 21: return "Creeping Madness"; break;
		case 22: return "Cryokinesis"; break;
		case 23: return "Play Dead"; break;
		case 24: return "Deep Thought"; break;
		case 25: return "Desolidify"; break;
		case 26: return "Detect Mutant Power"; break;
		case 27: return "Levitation"; break;
		case 28: return "Energy Field"; break;
		case 29: return "Darkness Field"; break;
		case 30: return "Surrounding Environment Control"; break;
		case 31: return "Find Location"; break;
		case 32: return "Forgettable"; break;
		case 33: return "Gravity Manipulation"; break;
		case 34: return "Growth"; break;
		case 35: return "Sensory Haze"; break;
		case 36: return "Hyperreflexes"; break;
		case 37: return "Jump"; break;
		case 38: return "Light Control"; break;
		case 39: return "Magnetize"; break;
		case 40: return "MACHINE EMPATHY"; break;
		case 41: return "Mechanical Intuition"; break;
		case 42: return "Presence Detection"; break;
		case 43: return "Corrosion"; break;
		case 44: return "Past Touch"; break;
		case 45: return "Puppeteer"; break;
		case 46: return "Push Mutant Powers"; break;
		case 47: return "Pyrokinesis"; break;
		case 48: return "Radioactivity"; break;
		case 49: return "Regeneration"; break;
		case 50: return "Rubbery Bones"; break;
		case 51: return "Screech"; break;
		case 52: return "Sculpt"; break;
		case 53: return "Second Skin"; break;
		case 54: return "Shrinking"; break;
		case 55: return "Slippery Skin"; break;
		case 56: return "Speed"; break;
		case 57: return "Spikes"; break;
		case 58: return "Time Stasis"; break;
		case 59: return "Stench"; break;
		case 60: return "MACHINE EMPATHY"; break;
		case 61: return "Telekinesis"; break;
		case 62: return "Teleportation"; break;
		case 63: return "Toxic Metabolism"; break;
		case 64: return "Transmutation"; break;
		case 65: return "Stretchy"; break;
		case 66: return "Ventriloquist"; break;
		case 67: return "Time Speed"; break;
		case 68: return "Weapon Finder"; break;
		case 69: return "Gamemaker"; break;
		case 70: return "Infinite Ammo"; break;
		case 71: return "Head Games"; break;
		case 72: return "Hurricane Lungs"; break;
		case 73: return "Spread Hate"; break;
		case 74: return "Spread Love"; break;
		case 75: return "Mind Wisper"; break;
		case 76: return "Invisibility"; break;
		case 77: return "Materialize Weapons"; break;
		case 78: return "Twin Duplication"; break;
		case 79: return "Create Body Parts"; break;
		case 80: return "MACHINE EMPATHY"; break;
		case 81: return "Portal"; break;
		case 82: return "Blood Lust"; break;
		case 83: return "Muscle Growth"; break;
		case 84: return "Fright"; break;
		case 85: return "Sleep"; break;
		case 86: return "Refractive Skin"; break;
		case 87: return "Earth Glide"; break;
		case 88: return "Bull's Eye"; break;
		case 89: return "Obliterate"; break;
		case 90: return "Disintegration"; break;
		case 91: return "Copy Mutant Power"; break;
		case 92: return "Bone Manipulation"; break;
		case 93: return "Fusion"; break;
		case 94: return "Animated Hair"; break;
		case 95: return "Self Destruct"; break;
		case 96: return "Night Vision"; break;
		case 97: return "Telescopic Vision"; break;
		case 98: return "Astral Projection"; break;
		case 99: return "Telepathy"; break;
		case 100: return "MACHINE EMPATHY"; break;
	}
}