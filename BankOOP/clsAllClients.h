#pragma once
#include "clsMainHeader.h"
#include "clsBankClient.h"
#include <iomanip> 
#include "clsPermissions.h"

class clsAllClients : protected clsMainHeader
{
private:
	static void _PrintClient(clsBankClient Client) {
		cout << "| " << left << setw(15) << Client.AccountNumbr();
		cout << "| " << setw(20) << Client.GetFullName();
		cout << "| " << setw(25) << Client.GetEmail();
		cout << "| " << setw(15) << Client.GetPhone();
		cout << "| " << setw(10) << Client.PinCode();
		cout << "| " << setw(15) << Client.GetBalance();
		cout << endl;
	}

public:
	static void GetAllClients() {
		if (!isPermisson(clsUser::enMainMenuePermissions::pList))
		{
			return;
		}
		vector<clsBankClient> Clients = clsBankClient::GetAllClients();

		// عرض عنوان الجدول
		
		MainHeader("All Clients");
		// عرض رأس الجدول
		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << setw(20) << "Client Name";
		cout << "| " << setw(25) << "Email";
		cout << "| " << setw(15) << "Phone";
		cout << "| " << setw(10) << "Pin Code";
		cout << "| " << setw(15) << "Balance";
		cout << endl;

		cout << "_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		// عرض بيانات العملاء
		for (clsBankClient& Client : Clients) {
			_PrintClient(Client);
		}

		cout << "_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
};

