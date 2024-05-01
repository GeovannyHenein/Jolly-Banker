#include "TransferTransaction.h"
#include "stdafx.h"

// Default constructor
TransferTransaction::TransferTransaction()
{
}

// Constructor that reads transaction data from a stream
TransferTransaction::TransferTransaction(istream& istr)
{
    string ID;
    istr >> ID;
    int length = ID.length();

    // Check if the account ID length is valid
    if (length != MAX_ID_LENGTH)
    {
        setValid(false); // Mark transaction as invalid
        cerr << "Error: Invalid Account Input" << endl;
    }
    else
    {
        // Extract account ID and fund type
        fundType = ID[ID.length() - 1] - '0';
        ID.resize(ID.length() - 1);
        accountID = stoi(ID);

        // Read transaction amount
        istr >> amount;

        string secondID;
        istr >> secondID;
        int secondLength = secondID.length();

        // Check if the second account ID length is valid
        if (secondLength != MAX_ID_LENGTH)
        {
            setValid(false); // Mark transaction as invalid
            cerr << "Error: Invalid Account Input" << endl;
        }
        else
        {
            // Extract second account ID and fund type
            secondFundType = secondID[secondID.length() - 1] - '0';
            secondID.resize(secondID.length() - 1);
            secondaryID = stoi(secondID);
            setValid(true); // Mark transaction as valid
        }
    }
}

// Destructor
TransferTransaction::~TransferTransaction()
{
}

// Function to check if the transaction is valid
bool TransferTransaction::IsValid() const
{
    return valid;
}

// Getter for the secondary account ID
int TransferTransaction::getSecondaryID() const
{
    return secondaryID;
}

// Getter for the fund type associated with the transaction
int TransferTransaction::getFundType() const
{
    return fundType;
}

// Getter for the fund type of the secondary account
int TransferTransaction::getSecondFundType() const
{
    return secondFundType;
}

// Getter for the transaction amount
int TransferTransaction::getAmount() const
{
    return amount;
}

// Function to generate a history log entry for the transaction
string TransferTransaction::historyLog() const
{
    stringstream ss;
    string type;
    ss << getTransactionType();
    ss >> type;
    
    // Generate history log entry with account IDs, fund types, and amount
    string retVal = type + " " + to_string(getAccountID()) + " " +
                    to_string(getFundType()) + " " + to_string(getAmount()) + " " +
                    to_string(getSecondaryID()) + " " + to_string(getSecondFundType());
    return retVal;
}

// Setter for the transaction amount
void TransferTransaction::setAmount(int amount)
{
    this->amount = amount;
}
