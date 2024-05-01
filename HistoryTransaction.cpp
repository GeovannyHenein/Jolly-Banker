#include "stdafx.h"
#include "HistoryTransaction.h"

// Default constructor
HistoryTransaction::HistoryTransaction()
{
}

// Destructor
HistoryTransaction::~HistoryTransaction()
{
}

// Function to check if the transaction is valid
bool HistoryTransaction::IsValid() const
{
	return valid;
}

// Constructor that reads data from an input stream to initialize a HistoryTransaction object
HistoryTransaction::HistoryTransaction(istream& istr)
{
	string ID;
	istr >> ID;

	// Check the length of the input string to determine the type of history to display
	if (ID.length() == MAX_ID_LENGTH) // Display history by specified fund
	{
		// Extract the fund type from the last character of the ID
		fundType = ID[ID.length() - 1] - '0';
		// Remove the fund type from the ID
		ID.resize(ID.length() - 1);
		// Convert the remaining string to account ID
		accountID = stoi(ID);
		// Set the transaction as valid
		setValid(true);
	}
	else if (ID.length() == 4)	// Display history by fund
	{
		// Set the fund type to -1 to indicate history for all funds
		fundType = -1;
		// Convert the string to account ID
		accountID = stoi(ID);
		// Set the transaction as valid
		setValid(true);
	}
	else 
	{
		// If the input ID is invalid, set the transaction as invalid and display an error message
		cerr << "Error: Invalid Account Input" << endl;
		setValid(false);
	}
}

// Function to update the transaction history based on whether the transaction is valid or not
void HistoryTransaction::updateHistory(Transaction* trans, bool valid)
{
	// Check if the transaction is valid
	if (valid) 
	{
		// If valid, add the transaction log to the history vector
		history.push_back(trans->historyLog());
	}
	else
	{
		// If invalid, add the transaction log with a "(Failed)" tag to the history vector
		history.push_back(trans->historyLog() + " (Failed)");
	}
}

// Overloaded output stream operator to display the transaction history
ostream& operator<<(ostream& istr, const HistoryTransaction& rhs)
{
	// Iterate over each entry in the history vector
	for (int i = 0; i < rhs.history.size(); i++)
	{
		// Output each entry with proper indentation
		istr << "   " + rhs.history[i] << endl;
	}

	return istr;
}
