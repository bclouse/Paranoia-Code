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

#define DIRECTORY "assests//"
#define ROLL rand()%20

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
	int Degree;
	int Skills[6][13];
	int Power[2];
	int Access[2];
	int Perversity;
	int Credits[2];
	int XP_Char;
	int XP_SG;
	int XP_SS;

	vector<int> Uncommon_val;
	vector<int> Unlikely_val;
	vector<int> Unhealthy_val;
	public:
		PC(string, string, string);
		void Generate(string,string,string);
		void Get_from_file(ifstream);
		string Get_name(bool);
		void Display();

		//void displaySkill(int, int);
};

//==============================
//	Party Class
//==============================

class Party {
	vector<PC*> party;
	PC *Team_Leader;
	PC *Equipment_Guy;
	PC *Happiness_Officer;
	PC *CP_RO;
	PC *Loyalty_Officer;
	PC *Hygiene_Officer;
	public:
		void add_member(PC);
		void del_member(string);
		void gen_MBD();
		void display();
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

class Settings {
	public:
	bool Spys;
	bool Auto_Save;
	bool Log_Stats;
	bool Command_Prompt;
};

//==============================
//	Functions
//==============================

int str2int(string);
string get_skill_names(int,int);
string get_rand_name(ifstream);
string getM(int);

#endif