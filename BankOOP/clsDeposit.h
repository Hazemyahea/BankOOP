#pragma once
#include "clsMainHeader.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsDeposit : protected clsMainHeader
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
	static void DepositFn() {
		MainHeader("Deposit");
		float Amount = 0;
		string AccountNumber;
		char A;
		cout << "Write Account Number" << endl;
		 AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExit(AccountNumber)) {
			cout << "Write Account Number" << endl;
		 AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::FindClientByAccountNumber(AccountNumber);
		Print(Client);
		cout << "Do You Want Deposit To this Client[y]" << endl;
		cin >> A;
		if (!A == 'y')
		{
			return;
		}
		cout << "Write The Amount :" << endl;
		cin >> Amount;
		Client.Deposit(Amount);
		clsBankClient::enSaveResults SaveResults;
		SaveResults = Client.save();
		cout << "-------Status Message!----------" << endl;
		switch (SaveResults)
		{
		case clsBankClient::enSaveResults::svSuccessed:
			system("cls");
			cout << "Deposit Done!" << endl;
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

