#pragma once
#include "clsMainHeader.h"
#include "clsUser.h"
#include <iomanip>
#include <string>
class clsUserAllList : protected clsMainHeader
{
private:
	static void _PrintUser(clsUser User) {
		cout << "| " << left << setw(15) << User.GetFirstName();
		cout << "| " << setw(20) << User.GetLastName();
		cout << "| " << setw(25) << User.GetEmail();
		cout << "| " << setw(15) << User.GetPhone();
		cout << "| " << setw(10) << User.GetUserName();
		cout << "| " << setw(15) << User.GetPassword();
		cout << "| " << setw(15) << User.GetPermission();
		cout << endl;
	}

public:
	static void GetAllClients() {
		vector<clsUser> Users = clsUser::GetUsersList();

		// عرض عنوان الجدول

		MainHeader("All Users");
		// عرض رأس الجدول
		cout << "| " << left << setw(15) << "First Name";
		cout << "| " << setw(20) << "Last Name";
		cout << "| " << setw(25) << "Email";
		cout << "| " << setw(15) << "Phone";
		cout << "| " << setw(10) << "user Name";
		cout << "| " << setw(15) << "Password";
		cout << "| " << setw(15) << "PerMission";
		cout << endl;

		cout << "_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		// عرض بيانات العملاء
		for (clsUser& User : Users) {
			_PrintUser(User);
		}

		cout << "_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
};

