#pragma once
#include "clsMainHeader.h"
#include "clsUser.h"
#include <iomanip> 
class clsFindUser : public clsMainHeader
{
private:
	static void _PrintUser(clsUser User) {
		cout << "\nUser Details:\n";
		cout << "---------------------------------\n";
		cout << "First Name: " << User.GetFirstName() << endl;
		cout << "Last Name: " << User.GetLastName() << endl;
		cout << "Full Name: " << User.GetFullName() << endl;
		cout << "Email: " << User.GetEmail() << endl;
		cout << "Phone: " << User.GetPhone() << endl;
		cout << "Username: " << User.GetUserName() << endl;
		cout << "Password: " << User.GetPassword() << endl;
		cout << "Permissions: " << User.GetPermission() << endl;
		cout << "---------------------------------\n";
	}
public:
	static void GetUser() {
		MainHeader("Find User");
		string username;
		cout << "Write USerName: " << endl;
		cin >> username;
		while (!clsUser::IsUserExist(username)) {
			cout << "Write USerName you want delete!" << endl;
			cin >> username;
		}
		clsUser newUser = clsUser::Find(username);
		_PrintUser(newUser);
	}
};

