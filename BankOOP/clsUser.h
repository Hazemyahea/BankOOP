#pragma once
#include "ClsPerson.h"
#include <string>
#include <vector>
#include "clsString.h"
#include <fstream>
#include "clsInputValidate.h"
class clsUser : public ClsPerson
{
private:
	enum enMode
	{
		EmptyMode = 0,
		UpdateMode = 1,
		AddNewMode = 3,
	};
	string _Username;
	string _Password;
	enMode _Mode;
	int _PerMission;
	bool _MarkeDelete = false;


	static clsUser _FromLineToObject(string Line, string Seperator = "#//#")
	{
		vector<string> vUserData;
		vUserData = clsString::Split(Line, Seperator);

		return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
			vUserData[3], vUserData[4], vUserData[5], stoi(vUserData[6]));

	}
	static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#")
	{

		string UserRecord = "";
		UserRecord += User.GetFirstName() + Seperator;
		UserRecord += User.GetLastName() + Seperator;
		UserRecord += User.GetEmail() + Seperator;
		UserRecord += User.GetPhone() + Seperator;
		UserRecord += User._Username + Seperator;
		UserRecord += User._Password + Seperator;
		UserRecord += to_string(User._PerMission);

		return UserRecord;

	}

	static vector<clsUser> _loadUserFromFileToVector() {
		vector<clsUser> VBankUser;
		fstream file;
		string line;
		file.open("Users.txt", ios::in);
		if (file.is_open())
		{
			while (getline(file, line)) {
				clsUser User = _FromLineToObject(line);
				VBankUser.push_back(User);
			}
			file.close();
		}
		return VBankUser;
	}
	static void _SaveUsersDataToFile(vector <clsUser> vUsers)
	{

		fstream MyFile;
		MyFile.open("Users.txt", ios::out);

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsUser U : vUsers)
			{
				if (U._MarkeDelete == false)
				{
					//we only write records that are not marked for delete.  
					DataLine = _ConverUserObjectToLine(U);
					MyFile << DataLine << endl;

				}
			}

			MyFile.close();
		}
	}


	void _Update()
	{
		vector <clsUser> _vUsers;
		_vUsers = _loadUserFromFileToVector();

		for (clsUser& U : _vUsers)
		{
			if (U._Username == GetUserName())
			{
				U = *this;
				break;
			}

		}
		_SaveUsersDataToFile(_vUsers);
	}

	void _AddNew()
	{

		_AddDataLineToFile(_ConverUserObjectToLine(*this));
	}
	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}
	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	
public:
	clsUser(enMode Mode, string FirstName, string LastName,
		string Email, string Phone, string UserName, string Password,
		int Permissions) :
		ClsPerson(FirstName, LastName, Email, Phone)

	{
		_Mode = Mode;
		_Username = UserName;
		_Password = Password;
		_PerMission = Permissions;
	}

	string GetUserName() {
		return _Username;
	}
	string GetPassword() {
		return _Password;
	}
	int GetPermission() {
		return _PerMission;
	}
	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	bool MarkedForDeleted()
	{
		return _MarkeDelete;
	}
	void SetUserName(string UserName)
	{
		_Username = UserName;
	}

	void SetPassword(string Password)
	{
		_Password = Password;
	}
	void SetPermissions(int Permissions)
	{
		_PerMission = Permissions;
	}
	int GetPermissions()
	{
		return _PerMission;
	}


	static void ReadUser(clsUser& User) {
		cout << "Enter First Name: ";
		User.SetFirstName(clsInputValidate::ReadString());
		cout << "Enter Last Name: ";
		User.SetLastName(clsInputValidate::ReadString());
		cout << "Enter Email: ";
		User.SetEmail(clsInputValidate::ReadString());
		cout << "Enter Phone: ";
		User.SetPhone(clsInputValidate::ReadString());
		cout << "Enter Password: ";
		User.SetPassword(clsInputValidate::ReadString());

	}
	static clsUser Find(string UserName)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _FromLineToObject(Line);
				if (User._Username == UserName)
				{
					MyFile.close();
					return User;
				}
			}

			MyFile.close();

		}

		return _GetEmptyUserObject();
	}
	static clsUser Find(string UserName, string Password)
	{

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _FromLineToObject(Line);
				if (User._Username == UserName && User._Password == Password)
				{
					MyFile.close();
					return User;
				}
			}
			MyFile.close();

		}
		return _GetEmptyUserObject();
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

	enSaveResults Save()
	{

		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if (IsEmpty())
			{
				return enSaveResults::svFaildEmptyObject;
			}
		}

		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;

			break;
		}

		case enMode::AddNewMode:
		{
			//This will add new record to file or database
			if (clsUser::IsUserExist(_Username))
			{
				return enSaveResults::svFaildUserExists;
			}
			else
			{
				_AddNew();
				//We need to set the mode to update after add new
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}

			break;
		}
		}

	}
	static bool IsUserExist(string UserName)
	{

		clsUser User = clsUser::Find(UserName);
		return (!User.IsEmpty());
	}

	bool Delete()
	{
		vector <clsUser> _vUsers;
		_vUsers = _loadUserFromFileToVector();

		for (clsUser& U : _vUsers)
		{
			if (U._Username == _Username)
			{
				U._MarkeDelete = true;
				break;
			}

		}

		_SaveUsersDataToFile(_vUsers);

		*this = _GetEmptyUserObject();

		return true;

	}

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	static vector <clsUser> GetUsersList()
	{
		return _loadUserFromFileToVector();
	}
};

