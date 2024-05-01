#ifndef DEPOSIT_TRANSACTION_H
#define DEPOSIT_TRANSACTION_H

#include "Transaction.h"

// Declaration of DepositTransaction class, derived from Transaction class
class DepositTransaction : public Transaction
{
public:
    // Default constructor
    DepositTransaction();
    // Destructor
    virtual ~DepositTransaction();
    // Constructor taking an istream as parameter
    DepositTransaction(istream& istr);
    // Function to generate history log for deposit transaction
    string historyLog() const;
    // Setter function to set the deposit amount
    void setAmount(int amount);
    // Getter function to return the deposit amount
    int getAmount() const;
    // Function to check if the deposit transaction is valid
    bool IsValid() const;

private:
    // Private member variable to store the deposit amount
    int amount;
};

#endif
