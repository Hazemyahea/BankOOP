#pragma once
#include "clsMainHeader.h"
#include "clsTransfer.h"
#include <iomanip>

class clsTransactionLogs :
    protected clsMainHeader
{
private:

public:
    static void PrintAllTransferLogs() {
           vector<clsTransfer::StLogsTransfer> StructLogs = clsTransfer::GetAllTransferLogsFromFile();
          cout << "----------------------------------------------------------------------------------\n";
           std::cout << "|     Date      |      Sender      |      Receiver     |   Amount   |  Reference  |\n";
           std::cout << "----------------------------------------------------------------------------------\n";
           for (clsTransfer::StLogsTransfer& Log: StructLogs) {
               std::cout << "| " << std::setw(11) << Log.date;
               cout << " | " << std::setw(9) << Log.ClientFrom;
               cout << " | " << std::setw(15) << Log.ClientTo;
               cout << " | " << std::setw(9) << std::fixed << std::setprecision(2) << Log.amout;
                    cout << " | " << std::setw(10) << Log.currentUser << " |\n";
               std::cout << "----------------------------------------------------------------------------------\n";
           }
    }
};

