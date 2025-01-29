#pragma once
#include "clsMainHeader.h"
#include "clsUser.h"
#include <iomanip> 
class clsUpdateUser :
    protected clsMainHeader
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
		cout << "Permissions: " << User.GetPermissions() << endl;
		cout << "---------------------------------\n";
	}
public:
    static void updateUser() {
		MainHeader("Update User");
		string userName;
		cout << "Write User Name: " << endl;
		cin >> userName;
		while (!clsUser::IsUserExist(userName)) {
			cout << "Write User Name: " << endl;
			cin >> userName;
		}
		// Create New Object With UserName.. 
		clsUser NewUser = clsUser::Find(userName);
		// Enter All Filed To new Object .. 
		_PrintUser(NewUser);
		clsUser::ReadUser(NewUser);
		_PrintUser(NewUser);
		// Sure Add ? 
		char save;
		cout << "Sure To Update This New User [y] 0r [n]?" << endl;
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
			cout << "The New User Update Successfully" << endl;
			break;
		case clsUser::svFaildUserExists:
			break;
		default:
			break;
		}
    }
};

