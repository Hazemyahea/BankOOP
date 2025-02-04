#pragma once
#include "clsMainHeader.h"
#include "clsUser.h"
#include <iomanip> 
class clsAddUser : protected clsMainHeader
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
		cout << "Permissions: " << User.GetPermission()<< endl;
		cout << "---------------------------------\n";
	}
	
public:
	static void AddUserFn() {
		MainHeader("Add User");
		string userName;
		cout << "Write User Name: " << endl;
		cin >> userName;
		while (clsUser::IsUserExist(userName)) {
			cout << "Write User Name: " << endl;
			cin >> userName;
		}
		// Create New Object With UserName.. 
		clsUser NewUser = clsUser::GetAddNewUserObject(userName);
		// Enter All Filed To new Object .. 
		clsUser::ReadUser(NewUser);
		_PrintUser(NewUser);
		// Sure Add ? 
		char save;
		cout << "Sure To add This New User [y] 0r [n]?" << endl;
		cin >> save;
		if (save != 'y')
		{
			return;
		}

		clsUser::enSaveResults SaveResults;
		SaveResults = NewUser.Save();
		switch (SaveResults)
		{
		case clsUser::svFaildEmptyObject:
			cout << "There is some This Wrong ! " << endl;
			break;
		case clsUser::svSucceeded:
			cout << "The New User Added Successfully" << endl;
			break;
		case clsUser::svFaildUserExists:
			break;
		default:
			break;
		}

	}
};

