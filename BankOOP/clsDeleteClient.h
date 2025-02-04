#pragma once
#include "clsMainHeader.h"
#include "clsBankClient.h"
class clsDeleteClient : protected clsMainHeader
{
	static void Print(clsBankClient Client) {
		cout << "\nClient Details:\n";
		cout << "---------------------------------\n";
		cout << "First Name: " << Client.GetFirstName() << endl; // Using getter from ClsPerson
		cout << "Last Name: " << Client.GetLastName() << endl;   // Using getter from ClsPerson
		cout << "Full Name: " << Client.GetFullName() << endl;   // Using getter from ClsPerson
		cout << "Email: " << Client.GetEmail() << endl;          // Using getter from ClsPerson
		cout << "Phone: " << Client.GetPhone() << endl;          // Using getter from ClsPerson
		cout << "Account Number: " << Client.AccountNumbr() << endl;
		cout << "Pin Code: " << Client.PinCode() << endl;
		cout << "Account Balance: " << Client.GetBalance() << endl;
		cout << "---------------------------------\n";
	}

public:
    static
		void DeleteClient() {
		if (!isPermisson(clsUser::enMainMenuePermissions::pDelete))
		{
			return;
		}
		MainHeader("Delete Client");
		string AccountNumber = "";
		char Result;
		cout << "Write Account Number" << endl;
		cin >> AccountNumber;
		while (!clsBankClient::IsClientExit(AccountNumber)) {
			cout << "Write Account Number" << endl;
			cin >> AccountNumber;
		}
		clsBankClient Client = clsBankClient::FindClientByAccountNumber(AccountNumber);
		Print(Client);
		cout << "Do You Want Delete This Client" << endl;
		cin >> Result;
		if (Result == 'Y' || Result == 'y')
		{
			Client._DeleteObjectFromFile();
			cout << "User Deleted!" << endl;
		}
		else {
			cout << "Okay.. We Will Keep it" << endl;
		}

		Print(Client);
	}

};

