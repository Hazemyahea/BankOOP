#pragma once
#include "ClsPerson.h"
#include <iostream>
#include <string>

using namespace std;
class clsMainHeader
{
	
public:
	static void MainHeader(string title) {
		cout << "\n\n\t\t\t\t\t" << title<<endl;
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
};

