#ifndef TRANSFER_TRANSACTION_H
#define TRANSFER_TRANSACTION_H

#include "Transaction.h"
#include <sstream>

// Declaration of the TransferTransaction class inheriting from Transaction
class TransferTransaction : public Transaction
{
public:
    // Default constructor
    TransferTransaction();
    
    // Destructor
    virtual ~TransferTransaction();
    
    // Constructor that reads transaction data from a stream
    TransferTransaction(istream& istr);
    
    // Getter for the fund type associated with the transaction
    int getFundType() const;
    
    // Getter for the secondary account ID
    int getSecondaryID() const;
    
    // Getter for the fund type of the secondary account
    int getSecondFundType() const;
    
    // Getter for the transaction amount
    int getAmount() const;
    
    // Setter for the transaction amount
    void setAmount(int amount);
    
    // Function to generate a history log entry for the transaction
    string historyLog() const;
    
    // Function to check if the transaction is valid
    bool IsValid() const;

private:
    // Member variables to store information about the secondary account and amount
    int secondFundType;
    int secondaryID;
    int amount;
};

#endif
