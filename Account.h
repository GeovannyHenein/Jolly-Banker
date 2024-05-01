#ifndef ACCOUNT_H // Header guard to prevent multiple inclusion
#define ACCOUNT_H

#include "stdafx.h" // Precompiled header
#include <string> // Standard string library
#include <iostream> // Input-output stream
#include <vector> // Standard vector container
#include <queue> // Standard queue container
#include "Transaction.h" // Include header file for Transaction class
#include "DepositTransaction.h" // Include header file for DepositTransaction class
#include "OpenAccountTransaction.h" // Include header file for OpenAccountTransaction class
#include "WithdrawTransaction.h" // Include header file for WithdrawTransaction class
#include "HistoryTransaction.h" // Include header file for HistoryTransaction class
#include "TransferTransaction.h" // Include header file for TransferTransaction class

// Constants
const int MAX_FUND_SIZE = 10; // Maximum number of fund types
const string FUNDS[10] = { // Array of fund names
    "Money Market",
    "Prime Money Market",
    "Long-Term Bond",
    "Short-Term Bond",
    "500 Index Fund",
    "Capital Value Fund",
    "Growth Equity Fund",
    "Growth Index Fund",
    "Value Fund",
    "Value Stock Index"
};

using namespace std;

// Account class declaration
class Account
{
    friend ostream& operator<<(ostream& os, const Account& rhs); // Friend function to overload stream insertion operator
public:
    // Constructors and Destructor
    Account(); // Default constructor
    Account(string firstName, string lastName, int ID); // Constructor with parameters
    ~Account(); // Destructor

    // Member functions
    void setName(string firstName, string lastName); // Set account holder's name
    void setID(int ID); // Set account ID
    string getFirstName() const; // Get account holder's first name
    string getLastName() const; // Get account holder's last name
    int getID() const; // Get account ID
    bool Deposit(Transaction *& const depositAmount); // Deposit funds into the account
    bool Withdraw(int amount, int fundType, Transaction *& const withdrawAmount); // Withdraw funds from the account
    bool Transfer(Transaction *& const transferAmount, Account& accountToTransfer); // Transfer funds to another account
    void displayHistory() const; // Display transaction history of all funds
    void displayHistoryBySpecifiedFund(int fundType) const; // Display transaction history of a specified fund

    // Overloaded comparison operators
    bool operator<(const Account& rhs) const;
    bool operator>(const Account& rhs) const;
    bool operator<=(const Account& rhs) const;
    bool operator>=(const Account& rhs) const;
    bool operator==(const Account& rhs) const;
    bool operator!=(const Account& rhs) const;

    // Enum for fund types
    enum FundType
    {
        MoneyMarket,
        PrimeMoneyMarket,
        LongTermBond,
        ShortTermBond,
        IndexFund500,
        CapitalValueFund,
        GrowthEquityFund,
        GrowthIndexFund,
        ValueFund,
        ValueStockIndex
    };

private:
    // Private member functions
    bool withdrawHelper(int firstFund, int secondFund, int amount, Transaction *& const trans); // Helper function for withdrawing from linked funds

    // Private member variables
    string firstName; // Account holder's first name
    string lastName; // Account holder's last name
    int ID; // Account ID
    int Balance; // Total account balance
    int fundType; // Fund type
    vector<bool> active; // Vector to store activity status of funds
    vector<int> fundBalance; // Vector to store individual fund balances
    vector<HistoryTransaction> historyLog; // Vector to store transaction history
};

#endif // End of header guard
