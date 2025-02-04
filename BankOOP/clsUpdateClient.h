#pragma once
#include "clsMainHeader.h"
#include "clsBankClient.h"
class clsUpdateClient : protected clsMainHeader
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
		cout << "Account Number: " << Client.AccountNumbr()<< endl;
		cout << "Pin Code: " << Client.PinCode() << endl;
		cout << "Account Balance: " << Client.GetBalance() << endl;
		cout << "---------------------------------\n";
	}


public:
	static void updateClient() {
		if (!isPermisson(clsUser::enMainMenuePermissions::pUpdate))
		{
			return;
		}
		MainHeader("Update Client");
		string AccountNumber = "";
		cout << "Write Account Number" << endl;
		cin >> AccountNumber;
		while (!clsBankClient::IsClientExit(AccountNumber)) {
			cout << "Write Account Number" << endl;
			cin >> AccountNumber;
		}
		clsBankClient Client = clsBankClient::FindClientByAccountNumber(AccountNumber);
		Print(Client);
		cout << "Update Client" << endl;
		clsBankClient::ReadClient(Client);

		clsBankClient::enSaveResults SaveResults;
		SaveResults = Client.save();
		cout << "-------Status Message!----------" << endl;
		switch (SaveResults)
		{
		case clsBankClient::enSaveResults::svSuccessed:
			cout << "Client Updated!" << endl;
			Print(Client);
			break;
		case clsBankClient::enSaveResults::svEmptyFalid:
			cout << "Client NOOT Updated!" << endl;
			break;
		default:
			break;
		}

	}

};

