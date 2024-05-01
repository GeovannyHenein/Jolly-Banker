#ifndef HISTORY_TRANSACTION_H
#define HISTORY_TRANSACTION_H

#include "Transaction.h" // Include the Transaction header file

class HistoryTransaction : public Transaction // Define the HistoryTransaction class as a subclass of Transaction
{
	friend ostream& operator<<(ostream& istr, const HistoryTransaction& rhs); // Declare the overloaded output stream operator as a friend function

public:
	// Default constructor
	HistoryTransaction();
	// Destructor
	virtual ~HistoryTransaction();
	// Constructor that reads data from an input stream
	HistoryTransaction(istream& istr);
	// Function to update the transaction history
	void updateHistory(Transaction* trans, bool valid);
	// Function to check if the transaction is valid
	bool IsValid() const;

private:
	vector<string> history; // Vector to store transaction history
};

#endif // HISTORY_TRANSACTION_H
