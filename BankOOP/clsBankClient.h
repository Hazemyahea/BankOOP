#pragma once
#include "ClsPerson.h"
#include <iostream>
#include <string>
#include "clsString.h"
#include <vector>
#include "clsUtil.h"
#include <fstream>
#include "clsInputValidate.h"
using namespace std;
class clsBankClient :  public ClsPerson
{
private:
	enum enMode
	{
		EmptyMode = 0,
		UpdateMode = 1,
		AddMoade = 3,
	};
	enMode _Mode;
	string _AccountNumer;
	float _AccountBalance;
	string _pinCode;
	bool _DeleteMark = false;

	static clsBankClient _FromLineToObject(string line) {
		vector<string> clsBankClientVector;
		clsBankClientVector = clsString::Split(line, "#//#");
		// Extract fields from the vector
		string FirstName = clsBankClientVector[0];
		string LastName = clsBankClientVector[1];
		string Email = clsBankClientVector[2];
		string Phone = clsBankClientVector[3];
		string AccountNumber = clsBankClientVector[4];
		string PinCode = clsBankClientVector[5];
		float AccountBalance = stof(clsBankClientVector[6]); // Convert string to float

		// Create and return a clsBankClient object
		return clsBankClient(clsBankClient::UpdateMode, AccountNumber, PinCode, AccountBalance, FirstName, LastName, Email, Phone);

	}

	static vector<clsBankClient> _loadClientFromFileToVector() {
		vector<clsBankClient> VBankClients;
		fstream file;
		string line;
		file.open("Client.txt", ios::in);
		if (file.is_open())
		{
			while (getline(file, line)) {
				clsBankClient Client = _FromLineToObject(line);
				VBankClients.push_back(Client);
			}
			file.close();
		}
		return VBankClients;
	}
	

	static string _FromObjectToLineString(clsBankClient ClientClass) {
		string line = ClientClass.GetFirstName() + "#//#";
		line += ClientClass.GetLastName() + "#//#";
		line += ClientClass.GetEmail() + "#//#";
		line += ClientClass.GetPhone() + "#//#";
		line += ClientClass.AccountNumbr() + "#//#";
		line += ClientClass.PinCode() + "#//#";
		line += to_string(ClientClass._AccountBalance);
		return line;
	}
	static void  _SaveClientDataFromVectorToFile(vector<clsBankClient> ClientVector) {
		fstream file;
		file.open("Client.txt", ios::out);
		string dateLine;
		if (file.is_open())
		{
			for (clsBankClient& Client : ClientVector)
			{
				if (Client._DeleteMark == false)
				{
					file << _FromObjectToLineString(Client) << endl;
				}
			}
		}
		file.close();
	}
	void _update() {
		vector<clsBankClient> ClientsVector;
		ClientsVector = _loadClientFromFileToVector();
		for (clsBankClient& Client : ClientsVector)
		{
			if (Client.AccountNumbr() == AccountNumbr())
			{
				Client = *this;
			}
		}
		_SaveClientDataFromVectorToFile(ClientsVector);

		
	}

	static clsBankClient _EmptyObject() {
		return clsBankClient(clsBankClient::EmptyMode, "", "", 0, "", "", "", "");
	}

	 void _AddNewObjectToFile() {
		fstream file;
		file.open("Client.txt", ios::app);
		if (file.is_open())
		{
			file << _FromObjectToLineString(*this) << endl;
		}
		file.close();
	}
	
public:
	clsBankClient(enMode Mode, string AccountNumber, string pinCode, float AccountBalance, string FirstName, string LastName, string Email, string Phone) :ClsPerson(FirstName,LastName,Email,Phone) {
		_Mode = Mode;
		_AccountNumer = AccountNumber;
		_AccountBalance = AccountBalance;
		_pinCode = pinCode;
	}

	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	string AccountNumbr() {
		return _AccountNumer;
	}
	void SetPinCode(string pinCode) {
		_pinCode = pinCode;
	}
	string PinCode() {
		return _pinCode;
	}
	void setAccountBalance(float AccountBalance) {
		_AccountBalance = AccountBalance;
	}

	float GetBalance() {
		return _AccountBalance;
	}
	static clsBankClient FindClientByAccountNumber(string AccountNumber) {
		fstream file;
		string line;
		file.open("Client.txt", ios::in);

		if (!file.is_open()) {
			cerr << "Error: Could not open file " << "Client.txt" << endl;
			return _EmptyObject();
		}

		while (getline(file, line)) {
			clsBankClient Client = _FromLineToObject(line);
			if (Client.AccountNumbr() == AccountNumber) {
				file.close();
				return Client;
			}
		}

		file.close();
		return _EmptyObject();
	}

	static clsBankClient FindClientByAccountNumberAndPinCode(string AccountNumber,string PinCode) {
		fstream file;
		string line;
		file.open("Client.txt", ios::in);

		if (!file.is_open()) {
			cerr << "Error: Could not open file " << "Client.txt" << endl;
			return _EmptyObject();
		}

		while (getline(file, line)) {
			clsBankClient Client = _FromLineToObject(line);
			if (Client.AccountNumbr() == AccountNumber && Client.PinCode() == PinCode) {
				file.close();
				return Client;
			}
		}

		file.close();
		return _EmptyObject();
	}


	void  _DeleteObjectFromFile() {
		vector <clsBankClient> ClientVector = _loadClientFromFileToVector();
		for (clsBankClient& Client : ClientVector) {
			if (Client.AccountNumbr() == _AccountNumer)
			{
				Client._DeleteMark = true;
				break;
			}
		}
		_SaveClientDataFromVectorToFile(ClientVector);
		*this = _EmptyObject();
	}

	static vector<clsBankClient> GetAllClients() {
		return _loadClientFromFileToVector();
	}

	static void OpenFile() {
		fstream file;
		file.open("Client.txt", ios::out);
		if (file.is_open())
		{
			file << "he" << endl;
		}
		file.close();
	}

	static bool IsClientExit(string AccountNumber) {
		clsBankClient Client = clsBankClient::FindClientByAccountNumber(AccountNumber);
		return (!Client.IsEmpty());
	}

	static clsBankClient CreatNewBankClientObject(string AccountNumber) {
		return clsBankClient(enMode::AddMoade,AccountNumber, "", 0, "", "", "", "");
	}

	static double GetAllBalance() {
		vector<clsBankClient> Clients = _loadClientFromFileToVector();
		double sum = 0;
		for (clsBankClient Client: Clients)
		{
			sum += Client.GetBalance();
		}
		return sum;
	}

	static void ReadClient(clsBankClient& clsClient) {
		cout << "FirstName" << endl;
		clsClient.SetFirstName(clsInputValidate::ReadString());
		cout << "LastName" << endl;
		clsClient.SetLastName(clsInputValidate::ReadString());
		cout << "email" << endl;
		clsClient.SetEmail(clsInputValidate::ReadString());
		cout << "Phone" << endl;
		clsClient.SetPhone(clsInputValidate::ReadString());
		cout << "PinCode" << endl;
		clsClient.SetPinCode(clsInputValidate::ReadString());
		cout << "Account Balance" << endl;
		clsClient.setAccountBalance(clsInputValidate::ReadFloatNumber());
	}
	enum enSaveResults
	{
		svEmptyFalid = 0,
		svSuccessed = 1,
		svAdded = 3,
		svFadiled = 4,
		DelectSuccessed = 5
	};



	void Deposit(float amount) {
		_AccountBalance += amount;
		
	}
	void Witdrwa(float amount) {
		_AccountBalance -= amount;

	}

	 enSaveResults save() {
		 switch (_Mode)
		 {
		 case enMode::EmptyMode:
			 return enSaveResults::svEmptyFalid;
			 break;
		 case enMode::UpdateMode:
			 _update();
			 return enSaveResults::svSuccessed;
			 break;
		 case enMode::AddMoade:
			 if (clsBankClient::IsClientExit(_AccountNumer))
			 {
				 return enSaveResults::svFadiled;
			 }
			 else {
				 _AddNewObjectToFile();
				 return enSaveResults::svAdded;
			 }
			 break;
		 default:
			 break;
		 }
	}
};

