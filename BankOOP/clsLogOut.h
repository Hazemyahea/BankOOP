#pragma once
#include "clsMainHeader.h"
#include "clsUser.h"
#include "Global.h"
class clsLogOut : protected clsMainHeader
{
private:
	static  void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
		system("pause>0");
	}
public:
	static void logOut() {
		CurrentCUser = clsUser::Find("", "");

	}
};

