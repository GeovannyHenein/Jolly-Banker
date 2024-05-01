#ifndef BANK_H // Header guard to prevent multiple inclusion
#define BANK_H

#include "BSTree.h" // Include header file for Binary Search Tree
#include "Transaction.h" // Include header file for Transaction class
#include "OpenAccountTransaction.h" // Include header file for OpenAccountTransaction class
#include "DepositTransaction.h" // Include header file for DepositTransaction class
#include "WithdrawTransaction.h" // Include header file for WithdrawTransaction class
#include "TransferTransaction.h" // Include header file for TransferTransaction class
#include "HistoryTransaction.h" // Include header file for HistoryTransaction class
#include <queue> // Include header file for queue data structure
#include <string> // Include header file for string manipulation

using namespace std;

const string FILE_TO_READ = "BankTransIn.txt"; // File name for input transactions

class Bank
{
public:
    Bank(); // Constructor
    ~Bank(); // Destructor
    const BSTree getAccounts() const; // Getter function for accounts
    const queue<Transaction*> getTransactions() const; // Getter function for transactions
    bool CreateTransactionsFromFile(); // Create transactions from input file
    void ProcessTransactionsInOrder(); // Process transactions in order
    void DisplayAccounts() const; // Display account balances

private:
    // Private helper functions to process transactions
    Transaction* CreateTransaction(string file); // Create transaction object from input string
    bool PerformTransaction(Transaction *& const trans); // Perform transaction
    void Deposit(Transaction*& trans); // Process deposit transaction
    void Withdraw(Transaction *& const trans); // Process withdrawal transaction
    void Transfer(Transaction *& const trans); // Process transfer transaction
    void OpenAccount(Transaction *& const trans); // Process account opening transaction
    void DisplayHistory(Transaction *& const trans) const; // Display transaction history

    BSTree accounts; // Binary Search Tree to store accounts
    queue<Transaction*> transactions; // Queue to store transactions
};

#endif // End of header guard
