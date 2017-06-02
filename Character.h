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

#define DIRECTORY "assets//"
#define ROLL (int)(rand()%20)+1

using namespace std;

#ifndef CHARACTER_H
#define CHARACTER_H

struct skill {
	string name;
	int value;
};

//==============================
//	Player Character Class
//==============================

class PC {
	string Player;					//Name of the Player
	string Name;					//Name of the Character
	string Clearance;				//Clearance Level
	string Sector;					//Sector
	string Mutant;					//Mutant Ability

	vector<string> Service;		//Service Group in order of involvement (Spy > Group being spied on)
	vector<string> Society;		//Secret Society in order of involvement
	vector<string> Items;		//Items (@ = Assigned, ? = Controverse, ! = Contraband)

	skill Category[6];			//Stores each main skills' names and values
	skill Skills[6][12];			//Stores each sub-skills' names and values
	vector<skill> Uncommon;		//Stores the uncommon skills
	vector<skill> Unlikely;		// ""        unlikely	""
	vector<skill> Unhealthy;	// ""        unhealthy 	""

	int Clone;						//Clone number
	int Degree;						//Secret Sociey degree
	int Treason;					//Number of Treason Points
	int Commendation;				//Number of Commendation Points
	int Power[2];					//Stores Power ranking (current/max)
	int Access[2];					//Stores Access ranking (current/max)
	int Credits[2];				//Stores credits and plasticreds

	bool store;
	public:
		PC(string, string, string);
		//~PC();
		void generate(string,string,string);
		void get_from_file(ifstream&);
		string get_name(bool);
		void display();
		void set_skills();
		void display_skills();
	friend class Party;
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
		void add_member(PC*);
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
		NPC(string,string,string);
		string Get_name(bool);
		void Display();
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
string get_rand_name(ifstream&);
string getM();
vector<string> get_files(ifstream&);
void get_power(int*);
string get_service(int*);
string getSS(int);
string rand_file_line(bool, string);

#endif