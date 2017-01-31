#include <iostream>
#include <string>
#include <assert.h>
#include <random>
#include <time.h>

#ifndef PC_H
#define PC_H

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
		string getPlayer();
		string getName(bool);
		void displayPC();
		void displaySkill(int , int);

};

#endif
/*
class Party {
	vector<PC> party;
	int size;
	PC *Team_Leader;
	PC *Equipment_Guy;
	PC *Happiness_Officer;
	PC *CP&RO;
	PC *Loyalty_Officer;
	PC *Hygiene_Officer;
};

class NPC {

};