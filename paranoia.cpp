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
	Party group;
	PC test ("Bryant","Clouse","TAU");
	group.add_member(test);
	group.display();

	return 0;
}