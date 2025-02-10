#pragma once
#include "clsMainHeader.h"
#include <iostream>
#include <string>
#include "clsBankClient.h"
#include <fstream>
#include "Global.h";
#include "ClsDate.h"
#include <vector>
#include "clsString.h"
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
	struct StLogsTransfer
	{
		string date;
		string ClientFrom;
		string ClientTo;
		float amout;
		string currentUser;

	};
	static string _TransferLogsFromStructToString(StLogsTransfer stTransfer) {
		string line;
		line += stTransfer.date + "#//#";
		line += stTransfer.ClientFrom + "#//#";
		line += stTransfer.ClientTo + "#//#";
		line += to_string(stTransfer.amout) + "#//#";
		line += stTransfer.currentUser;
		return line;
	}
	static void _addTransferLogsToFile(string line) {
		fstream file;
		file.open("TransferLogs.txt", ios::app | ios::out);
		if (file.is_open())
		{
			file << line << endl;
		}
		file.close();
	}
	static StLogsTransfer TransferStringLineToStruct(string line) {
		vector<string> VTransferLog = clsString::Split(line, "#//#");
		StLogsTransfer logsTransferStruct;
		logsTransferStruct.date = VTransferLog[0];
		logsTransferStruct.ClientFrom = VTransferLog[1];
		logsTransferStruct.ClientTo = VTransferLog[2];
		logsTransferStruct.amout = stof(VTransferLog[3]);
		logsTransferStruct.currentUser = VTransferLog[4];
		return logsTransferStruct;
	}
	static vector<StLogsTransfer> GetAllTransferLogsFromFile() {
		fstream file;
		vector<StLogsTransfer> LogsTransferVector;
		StLogsTransfer LogsTransferSt;
		string line;
		file.open("TransferLogs.txt", ios::in);
		if (file.is_open())
		{
			while (getline(file,line)) {
				LogsTransferSt = TransferStringLineToStruct(line);
				LogsTransferVector.push_back(LogsTransferSt);
			}
		}
		file.close();
		return LogsTransferVector;
	}
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
		// Create LogsTransferStruct to add it to file..
		StLogsTransfer LogsTransfer;
		LogsTransfer.amout = Amount;
		LogsTransfer.ClientFrom = ClientFrom.GetFullName();
		LogsTransfer.ClientTo = ClientTo.GetFullName();
		LogsTransfer.currentUser = CurrentCUser.GetUserName();
		LogsTransfer.date = clsDate::GetSystemDateTimeString();
		_addTransferLogsToFile(_TransferLogsFromStructToString(LogsTransfer));
	}

};

