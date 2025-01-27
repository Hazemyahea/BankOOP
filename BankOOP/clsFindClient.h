#pragma once
#include "clsMainHeader.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsFindClient : protected clsMainHeader
{
private:
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
	static void FindClient() {
		MainHeader("Find Client");
		string AccountNumber;
		cout << "Write The Account Number: " << endl;
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExit(AccountNumber)) {
			cout << "Write Account Number" << endl;
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::FindClientByAccountNumber(AccountNumber);
		
		Print(Client);
	}
};

