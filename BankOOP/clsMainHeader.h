#pragma once
#include "ClsPerson.h"
#include <iostream>
#include <string>
#include "Global.h"
#include "clsPermissions.h"
#include "clsUser.h"
#include "ClsDate.h"

using namespace std;
class clsMainHeader
{
public:
	static void MainHeader(string title) {
		cout << "\n\n\t\t\t\t\t" << title<<endl;
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "User: " << CurrentCUser.GetUserName() << endl;
		cout << "Date: " << clsDate::DateToString(clsDate()) << endl;
		cout << "_________________________________________\n" << endl;

	}
	static bool isPermisson(clsUser::enMainMenuePermissions Permission) {


		if (CurrentCUser.IsHavePermission(Permission))
		{
			return true;
		}
		else {
			cout << "You do not have permission to perform this action." << endl;
			return false;
		}
	}
};

