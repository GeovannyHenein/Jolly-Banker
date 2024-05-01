#include "stdafx.h"
#include "DepositTransaction.h"

// Default constructor
DepositTransaction::DepositTransaction()
{
}

// Constructor that takes an istream as parameter
DepositTransaction::DepositTransaction(istream& istr)
{
    string ID;

    // Read account ID from the input stream
    istr >> ID;
    int length = ID.length();
    
    // Validate the length of the account ID
    if (length != MAX_ID_LENGTH)
    {
        setValid(false); // Set transaction as invalid
        cerr << "Error: Invalid Account Input" << endl; // Print error message
    }
    else
    {
        // Extract fund type from the last character of the account ID
        fundType = ID[ID.length() - 1] - '0';
        ID.resize(ID.length() - 1); // Remove the last character
        accountID = stoi(ID); // Convert remaining string to integer (account ID)
        istr >> amount; // Read deposit amount from the input stream
        setValid(true); // Set transaction as valid
    }
}

// Destructor
DepositTransaction::~DepositTransaction()
{
}

// Getter function to return the deposit amount
int DepositTransaction::getAmount() const
{
    return amount;
}

// Function to generate history log for deposit transaction
string DepositTransaction::historyLog() const
{
    // Get history log from the base class (Transaction)
    string retVal = Transaction::historyLog();
    // Append deposit amount to the history log
    retVal += " " + to_string(getAmount());
    return retVal;
}

// Setter function to set the deposit amount
void DepositTransaction::setAmount(int amount)
{
    this->amount = amount;
}

// Function to check if the deposit transaction is valid
bool DepositTransaction::IsValid() const
{
    return valid;
}
