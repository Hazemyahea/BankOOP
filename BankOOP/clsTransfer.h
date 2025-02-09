#pragma once
#include "clsMainHeader.h"
#include <iostream>
#include <string>
#include "clsBankClient.h"

class clsTransfer : protected clsMainHeader
{
private:
	
	static clsBankClient _GetUser(string Message) {
		string AccountNumberFrom;
		cout << Message << endl;
		cout << "Write Account Number" << endl;
		cin >> AccountNumberFrom;
		while (!clsBankClient::IsClientExit(AccountNumberFrom)) {
			cout << "This User Not Exist !" << endl;
			cout << "Write Account Number" << endl;
			cin >> AccountNumberFrom;
		}
		return clsBankClient::FindClientByAccountNumber(AccountNumberFrom);
	}

	static void _PrintClient(clsBankClient Client) {
		cout << "-----------------------" << endl;
		cout << "UserName: " << Client.GetFullName() << endl;
		cout << "balance: " << Client.GetBalance() << endl;


	}
public:
	static void MainTransferFunction() {
		MainHeader("Transfer Money");
		float Amount;
		char yes = 'y';
		clsBankClient ClientFrom = _GetUser("Please Write The Account you want transfer from:");
		_PrintClient(ClientFrom);
		clsBankClient ClientTo = _GetUser("Please Write The Account you want transfer to:");
		_PrintClient(ClientTo);
		// Wihdraw
		cout << "Write The Amount You Want Transfer :" << endl;
		cin >> Amount;
		cout << "Are you Sure You Want Trasfer This Amount [y] ? :" << endl;
		cin >> yes;
		if (yes != 'y')
		{
			return;
		}
		if (Amount > ClientFrom.GetAllBalance())
		{
			cout << "The Balance Is Not Enough" << endl;
			return;
		}
		ClientFrom.Witdrwa(Amount);
		ClientTo.Deposit(Amount);
		clsBankClient::enSaveResults SaveResults;
		SaveResults = ClientFrom.save();
		SaveResults = ClientTo.save();
		_PrintClient(ClientFrom);
		_PrintClient(ClientTo);

	}

};

