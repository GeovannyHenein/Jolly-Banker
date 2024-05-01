#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>
#include <sstream>
#include "Funds.h" // Include the header file for Funds class if needed

using namespace std;

// Constants defining transaction types
const char OPEN = 'O';
const char DEPOSIT = 'D';
const char WITHDRAW = 'W';
const char TRANSFER = 'T';
const char HISTORY = 'H';

// Maximum length of an account ID
const int MAX_ID_LENGTH = 5;

class Transaction
{
public:
    // Constructor
    Transaction();
    // Destructor (virtual for polymorphic behavior)
    virtual ~Transaction();

    // Setters and getters for transaction type and account ID
    virtual void setTransactionType(char Type);
    virtual void setAccountID(int ID);
    virtual char getTransactionType() const;
    virtual int getAccountID() const;

    // Getter and setter for fund type
    virtual int getFundType() const;
    virtual void setAmount(int amount); // Setter for transaction amount (may be overridden by derived classes)

    // Function to generate a history log entry for the transaction
    virtual string historyLog() const;

    // Functions to check the validity of the transaction
    virtual bool IsValid() const;
    virtual void setValid(bool valid);

protected:
    bool valid;     // Flag to indicate the validity of the transaction
    char charType;  // Transaction type (e.g., 'O' for open account)
    int accountID;  // ID of the account associated with the transaction
    int fundType;   // Type of fund associated with the transaction (may be overridden by derived classes)
};

#endif
