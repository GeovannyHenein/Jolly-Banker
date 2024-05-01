// Include necessary header file
#include "stdafx.h"
#include "OpenAccountTransaction.h"

// Default constructor definition
OpenAccountTransaction::OpenAccountTransaction()
{
}

// Parameterized constructor definition
OpenAccountTransaction::OpenAccountTransaction(istream& istr)
{
    // Read account details from the input stream
    istr >> lastName;
    istr >> firstName;
    string ID;
    istr >> ID;
    int length = ID.length();

    // Validate the account ID
    if (length != 4)
    {
        // If the ID is invalid, set the transaction as invalid and print an error message
        setValid(false);
        cerr << "Error: Invalid Account Input" << endl;
    }
    else
    {
        // If the ID is valid, store it and set the transaction as valid
        accountID = stoi(ID);
        setValid(true);
    }
}

// Destructor definition
OpenAccountTransaction::~OpenAccountTransaction()
{
}

// Getter function for the first name
string OpenAccountTransaction::getFirstName() const
{
    return firstName;
}

// Getter function for the last name
string OpenAccountTransaction::getLastName() const
{
    return lastName;
}

// Function to check if the transaction is valid
bool OpenAccountTransaction::IsValid() const
{
    return valid;
}
