// BankOOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "clsLogin.h"
using namespace std;




int main()
{
	
	while (true)
	{
		if (!clsLogin::showLoginScreen()) {
			break;
		}
	}

	return 0;
;}
