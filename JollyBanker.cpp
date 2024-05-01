// Include necessary header files
#include "stdafx.h" // Precompiled header (if used)
#include <iostream>
#include <string>
#include <fstream>
#include "Account.h"
#include "BSTree.h"
#include "Bank.h"
#include "Transaction.h"

// Entry point of the program
int main()
{
    // Create an instance of the Bank class named 'jolly'
    Bank jolly;

    // Read transactions from a file and create corresponding transaction objects
    jolly.CreateTransactionsFromFile();

    // Process transactions in the order they were read from the file
    jolly.ProcessTransactionsInOrder();

    // Display the accounts and their final balances after processing all transactions
    jolly.DisplayAccounts();

    // Return 0 to indicate successful program execution
    return 0;
}
