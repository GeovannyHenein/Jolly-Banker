#include "stdafx.h"
#include "Transaction.h"
#include <sstream>

// Constructor initializes the validity of the transaction
Transaction::Transaction()
{
    valid = true;
}

// Destructor (empty)
Transaction::~Transaction()
{
}

// Getter for the transaction type
char Transaction::getTransactionType() const
{
    return charType;
}

// Setter for the transaction type
void Transaction::setTransactionType(char Type)
{
    charType = Type;
}

// Getter for the account ID
int Transaction::getAccountID() const
{
    return accountID;
}

// Getter for the fund type
int Transaction::getFundType() const
{
    return fundType;
}

// Setter for the account ID
void Transaction::setAccountID(int ID)
{
    accountID = ID;
}

// Setter for the amount (empty implementation)
void Transaction::setAmount(int amount)
{
    // This function is empty as it's meant to be overridden by derived classes
}

// Function to generate a history log entry for the transaction
string Transaction::historyLog() const
{
    stringstream ss;
    string type;
    ss << getTransactionType(); // Convert transaction type to string
    ss >> type;
    // Generate history log entry with transaction type, account ID, and fund type
    string retVal = type + " " + to_string(getAccountID()) + " " +
        to_string(getFundType());
    return retVal;
}

// Getter for the validity of the transaction
bool Transaction::IsValid() const
{
    return valid;
}

// Setter for the validity of the transaction
void Transaction::setValid(bool valid)
{
    this->valid = valid;
}
