#pragma once
#include "clsMainHeader.h"
#include "clsInputValidate.h"
#include <iomanip> 
#include "clsUserAllList.h"

class clsMangeUsersScreen : protected clsMainHeader
{
private:
	enum EnOptions
	{
		ShowAllUsers = 1, // 1 - All Clients
		AddUser = 2,          // 2 - Add Client
		DeleteUser = 3,       // 3 - Delete Clients
		UpdateUser = 4,       // 4 - Update Clients
		FindUser = 5,
		BackToMain = 8             // 5 - Log Out
	};
	static void _AllOptions() {
		cout << "1 - All Users" << endl;
		cout << "2 - Add User" << endl;
		cout << "3 - Delete User" << endl;
		cout << "4 - Update User" << endl;
		cout << "5 - Find User" << endl;
		cout << "6 - Back to Main Menue" << endl;
	}
	static  void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Mange Users Screen...\n";

		system("pause>0");
		ShowMangeUsersScreen();
	}
 static	void ReadChoose(EnOptions Options) {
		switch (Options)
		{
		case EnOptions::ShowAllUsers:
			system("cls");
			clsUserAllList::GetAllClients();
			_GoBackToMainMenue();
			break;
		case EnOptions::AddUser:
			system("cls");
			cout << "Show All Users" << endl;
			_GoBackToMainMenue();
			break;
		case EnOptions::DeleteUser:
			system("cls");
			cout << "Show All Users" << endl;
			_GoBackToMainMenue();
			break;
		case EnOptions::UpdateUser:
			system("cls");
			cout << "Show All Users" << endl;
			_GoBackToMainMenue();
			break;
		case EnOptions::FindUser:
			system("cls");
			cout << "Show All Users" << endl;
			_GoBackToMainMenue();
			break;
		case EnOptions::BackToMain:
			break;
		default:
			break;
		}
	}

public:
	static void ShowMangeUsersScreen() {
		system("cls");
		MainHeader("Mange Users");
		_AllOptions();
		ReadChoose((EnOptions) clsInputValidate::ReadIntNumber());
	}
};

