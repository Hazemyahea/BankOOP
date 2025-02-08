#pragma once
#include "clsMainHeader.h"
#include <iostream>
#include <iomanip> 
#include "clsUser.h"
#include <vector>
class clsLogs :
    protected clsMainHeader
{
private:

public:

	static void PrintLogs() {
		if (!isPermisson(clsUser::enMainMenuePermissions::PLogs))
		{
			return;
		}
		vector <clsUser::StLogs> Logs = clsUser::GetLosgFromLogsFile();
		cout << "+------------+-----------+----------+------------+\n";
		cout << "| " << std::setw(10) << "Date"
			<< " | " << std::setw(9) << "Username"
			<< " | " << std::setw(8) << "Password"
			<< " | " << std::setw(10) << "Permission"
			<< " |\n";
		std::cout << "+------------+-----------+----------+------------+\n";
		for (clsUser::StLogs Log : Logs) {
			cout << "| " << setw(10) << Log.Date
				<< " | " << setw(9) << Log.userName
				<< " | " << setw(8) << Log.password
				<< " | " << setw(10) << Log.Permission
				<< " |\n";
			cout << "+------------+-----------+----------+------------+\n";
		}


		std::cout << "+------------+-----------+----------+------------+\n";
	}


};