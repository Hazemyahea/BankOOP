#pragma once
#include <iostream>
#include <string>

using namespace std;
class ClsPerson
{
private:
	string _FirstName;
	string _lastName;
	string _Email;
	string _phone;

public:
	ClsPerson(string FirstName,string lastName, string Email, string Phone) {
		_FirstName = FirstName;
		_lastName = lastName;
		_Email = Email;
		_phone = Phone;
	}
	// Setter Functions
	void SetFirstName(string FirstName) {
		_FirstName = FirstName;
	}
	void SetLastName(string LastName) {
		_lastName = LastName;
	}
	void SetEmail(string Email) {
		_Email = Email;
	}
	void SetPhone(string Phone) {
		_phone = Phone;
	}

	//Get Functions
	string GetFirstName() {
		return _FirstName;
	}
	string GetLastName() {
		return _lastName;
	}
	string GetEmail() {
		return _Email;
	}
	string GetPhone() {
		return _phone;
	}
	string GetFullName() {
		return _FirstName + " " + _lastName;
	}
};

