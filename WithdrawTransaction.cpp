#include "stdafx.h"
#include "WithdrawTransaction.h"

// Default constructor
WithdrawTransaction::WithdrawTransaction()
{
}

// Destructor
WithdrawTransaction::~WithdrawTransaction()
{
}

// Constructor that reads transaction data from a stream
WithdrawTransaction::WithdrawTransaction(istream& istr)
{
    string ID;
    istr >> ID;
    int length = ID.length();
    
    // Check if the account ID length is valid
    if (length > MAX_ID_LENGTH || length < MAX_ID_LENGTH)
    {
        setValid(false);
        cerr << "Error: Invalid Account Input" << endl;
    }
    else
    {
        // Extract the fund type and account ID from the input string
        fundType = ID[ID.length() - 1] - '0';
        ID.resize(ID.length() - 1);
        accountID = stoi(ID);
        istr >> amount;
        setValid(true);
    }
}

// Getter for the transaction amount
int WithdrawTransaction::getAmount() const
{
    return amount;
}

// Function to generate a history log entry for the transaction
string WithdrawTransaction::historyLog() const
{
    string retVal = Transaction::historyLog();
    retVal += " " + to_string(amount);
    return retVal;
}

// Setter for the transaction amount
void WithdrawTransaction::setAmount(int amount)
{
    this->amount = amount;
}

// Function to check if the transaction is valid
bool WithdrawTransaction::IsValid() const
{
    return valid;
}
