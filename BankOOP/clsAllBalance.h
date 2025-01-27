#pragma once
#include "clsMainHeader.h"
#include "clsBankClient.h"
#include <iomanip>

class clsAllBalance : protected clsMainHeader
{


private:
	static void PrintClient(clsBankClient Client) {
		cout << "| " << left << setw(15) << Client.AccountNumbr();
		cout << "| " << setw(20) << Client.GetFullName();
		cout << "| " << setw(25) << Client.GetEmail();
		cout << "| " << setw(15) << Client.GetPhone();
		cout << "| " << setw(10) << Client.PinCode();
		cout << "| " << setw(15) << Client.GetBalance();
		cout << endl;

	}

	static void PrintAllBalance() {
		cout << "ALL Balance: " << clsBankClient::GetAllBalance() << endl;
	}
public:
	static void GetAllBalance() {
		vector<clsBankClient> Clients = clsBankClient::GetAllClients();

		// عرض عنوان الجدول
		cout << "\n\n\t\t\t\t\tClient List (" << Clients.size() << ") Client(s).";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

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
			PrintClient(Client);
		}

		cout << "_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		PrintAllBalance();
	}
};

