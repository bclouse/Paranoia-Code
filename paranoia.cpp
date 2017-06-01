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
	// ifstream fp;
	// vector<string> file_list;
	// string dirname = "assets//", fname, test;

	// fname = dirname+"Filenames.txt";
	// fp.open(fname);
	// file_list = get_files(fp);
	// fp.close();
	// fp.open(file_list.at(3));

	srand(time(NULL));
	int index = 0;
	int n;
	cout << "Number of Characters: ";
	cin >> n; 
	string sg,ss,m;
	for (int i = 0; i < n; i++)	{
		sg = get_service(&index);
		ss = getSS(index);
		m = getM();
		printf("Character #%d\n", i+1);
		printf("\tService: %s\n", sg.c_str());
		printf("\tSecret:  %s\n", ss.c_str());
		printf("\tMutant:  %s\n\n", m.c_str());
	}
	// NPC person(get_rand_name(fp),"R", "WBW");
	// person.Display();

	// fp.close();
	// string test = getM();
	// for (int i = 0; i < 25; i++) {
	// 	cout << getM() << endl;
	// }

	// Party group;
	// PC test ("Bryant","Clouse","TAU");
	// group.add_member(test);
	// group.display();


	return 0;
}