#pragma once
#include "clsMainHeader.h"
#include "Global.h"
#include <iostream>
#include <string>
#include "clsMainScreen.h"
class clsLogin : protected clsMainHeader
{

private:
	static bool _Login() {
		string Username;
		string Password;
		bool LoginFaild = true;
		int tryLogin = 3;
		do
		{
			
			cout << "Write Your User Name: " << endl;
			cin >> Username;
			cout << "Write Your Password: " << endl;
			cin >> Password;
			CurrentCUser = clsUser::Find(Username, Password);
			LoginFaild = CurrentCUser.IsEmpty();
			if (LoginFaild)
			{
				cout << "UserName Or Password is Mistake\n" << endl;
				cout << "You have " << tryLogin << " Times Try" << endl;
				tryLogin--;

			}
			if (tryLogin == 0)
			{
				cout << "You enter Wrong data 3 times!" << endl;
				return false;
			}
			
			
			
		} while (LoginFaild);
		CurrentCUser.AddLogsToLogsFile();
		clsMainScreen::MainScreen();
		return true;

		
	}
public:
	static bool showLoginScreen() {
		system("cls");
		MainHeader("Welcome To CCPP Bank - Login");
		return _Login();
			
	}
};

