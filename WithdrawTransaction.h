#ifndef WITHDRAW_TRANSACTION_H
#define WITHDRAW_TRANSACTION_H

#include "Transaction.h" // Include the base class header file

class WithdrawTransaction : public Transaction // Define the WithdrawTransaction class as a subclass of Transaction
{
public:
    WithdrawTransaction(); // Default constructor
    virtual ~WithdrawTransaction(); // Destructor
    WithdrawTransaction(istream& istr); // Constructor that reads transaction data from a stream
    int getAmount() const; // Getter for the transaction amount
    void setAmount(int amount); // Setter for the transaction amount
    string historyLog() const; // Function to generate a history log entry for the transaction
    bool IsValid() const; // Function to check if the transaction is valid

private:
    int amount; // Amount to withdraw
};

#endif
