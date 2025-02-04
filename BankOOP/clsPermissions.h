#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip> 
#include "clsUser.h"
using namespace std;
class clsUserPermissions
{
private:
 
public:


   static void AccessDenied() {
       cout << "You do not have permission to perform this action." << endl;
   }
 
};

