#pragma once
#include "clsMainHeader.h"
#include "clsAllClients.h"
#include "clsAddClient.h"
#include "clsDeleteClient.h"
#include "clsUpdateClient.h"
#include "clsFindClient.h"
#include "clsMainTransactionScreen.h"
#include "clsMangeUsersScreen.h"
class clsMainScreen : protected clsMainHeader
{
private:
	enum EnOptions
	{
		ShowAllClients = 1, // 1 - All Clients
		AddClient = 2,          // 2 - Add Client
		DeleteClient = 3,       // 3 - Delete Clients
		UpdateClient = 4,       // 4 - Update Clients
		FindClient = 5,
		Transactions = 6,
		MangeUsers=7,
		LogOut =8             // 5 - Log Out
	};
	static void _AllOptions() {
		cout << "1 - All Clients" << endl;
		cout << "2 - Add Client" << endl;
		cout << "3 - Delete Clients" << endl;
		cout << "4 - Update Clients" << endl;
		cout << "5 - Find Client" << endl;
		cout << "6 - Transactions" << endl;
		cout << "7 - Mange Users" << endl;
		cout << "8 - Log Out" << endl;
	}
	  static int ReadInt() {
		int choice;
		cout << "Enter your choice: ";
		cin >> choice;
		return choice;
	}

	  static  void _GoBackToMainMenue()
	  {
		  cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		  system("pause>0");
		  MainScreen();
	  }
	static void EnptionsFn(EnOptions options) {
		switch (options) {
		case ShowAllClients:
			system("cls");
			clsAllClients::GetAllClients();
			_GoBackToMainMenue();
			break;
		case AddClient:
			system("cls");
			clsAddClient::AddClient();
			_GoBackToMainMenue();
			break;
		case DeleteClient:
			system("cls");
			clsDeleteClient::DeleteClient();
			_GoBackToMainMenue();
			break;
		case UpdateClient:
			system("cls");
			clsUpdateClient::updateClient();
			_GoBackToMainMenue();
			break;
		case FindClient:
			system("cls");
			clsFindClient::FindClient();
			_GoBackToMainMenue();
			break;
		case Transactions:
			system("cls");
			clsMainTransactionScreen::MainScreenTransaction();
			_GoBackToMainMenue();
		case MangeUsers:
			system("cls");
			clsMangeUsersScreen::ShowMangeUsersScreen();
			_GoBackToMainMenue();
		case LogOut:
			system("cls");
			cout << "You Out!" << endl;
			return;
			break;
		default:
			cout << "Invalid choice!" << endl;
			break;
		}
	}
public:
	static void MainScreen() {
		system("cls");
		MainHeader("Main Screen");
		_AllOptions();
		EnptionsFn((EnOptions)ReadInt());
	}
};

