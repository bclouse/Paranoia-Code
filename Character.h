#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <random>
#include <iomanip>

using namespace std;

#ifndef CHARACTER_H
#define CHARACTER_H

//==============================
//	Player Character Class
//==============================

class PC {
	string Player;
	string Name;
	string Clearance;
	string Sector;
	string Skill_names[6][12];
	string Mutant;

	vector<string> Service;
	vector<string> Society;
	vector<string> Uncommon_names;
	vector<string> Unlikely_names;
	vector<string> Unhealthy_names;
	vector<string> Common;
	vector<string> Controverse;
	vector<string> Contraband;

	int Clone;
	int Skills[6][13];
	int Degree;
	int Power[2];
	int Access[2];
	int Perversity;
	int Credits[2];

	vector<int> Uncommon_val;
	vector<int> Unlikely_val;
	vector<int> Unhealthy_val;
	public:
		PC(string, string, string);
		string get_name(bool);
		void display();
		//void displaySkill(int, int);
};

//==============================
//	Party Class
//==============================

class Party {
	vector<PC> party;
	PC *Team_Leader;
	PC *Equipment_Guy;
	PC *Happiness_Officer;
	PC *CP_RO;
	PC *Loyalty_Officer;
	PC *Hygiene_Officer;
	public:
		void add_member(PC);
		void gen_MBD();
};

//==============================
//	NPC Class
//==============================

class NPC {
	string Name;
	string Clearance;
	string Sector;

	int Clone;
	public:
		NPC(string,string,string);
};

//==============================
//	Functions
//==============================


#endif