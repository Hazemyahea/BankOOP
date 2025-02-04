#pragma once
#include "clsMainHeader.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsDeposit.h"
#include "clsWitdraw.h"
#include "clsAllBalance.h"
class clsMainTransactionScreen :
    protected clsMainHeader
{

private:
    enum enTransctions
    {
        Deposit = 1,
        withdraw = 2,
        TotalBalance=3,
        MainMenu=4
    };
    static void _ShowAllTransctions() {
        cout << "1 - Deposit" << endl;
        cout << "2 - withdraw" << endl;
        cout << "3 - TotalBalance" << endl;
        cout << "4 - Main Menu" << endl;
    } static  void _GoBackToTransaction()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Transaction...\n";

        system("pause>0");
        MainScreenTransaction();
    }
    static void _ReadTransctionsChoose(enTransctions Choose) {
      
        switch (Choose)
        {
        case enTransctions::Deposit:
            system("cls");
            clsDeposit::DepositFn();
            _GoBackToTransaction();
            break;
        case enTransctions::withdraw:
            system("cls");
            clsWitdraw::Witdraw();
            _GoBackToTransaction();
            break;
        case enTransctions::TotalBalance:
            system("cls");
            clsAllBalance::GetAllBalance();
            _GoBackToTransaction();
            break;
        case enTransctions::MainMenu:
          
        default:
            break;
        }
    }
public:
    static void MainScreenTransaction() {
        if (!isPermisson(clsUser::enMainMenuePermissions::pTranactions))
        {
            return;
        }
        system("cls");
        MainHeader("Transaction");
        _ShowAllTransctions();
        _ReadTransctionsChoose((enTransctions)clsInputValidate::ReadIntNumberBetween(1, 5));

    }
};

