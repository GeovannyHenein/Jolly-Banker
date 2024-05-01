#ifndef OPEN_ACCOUNT_TRANSACTION_H
#define OPEN_ACCOUNT_TRANSACTION_H

#include "Transaction.h" // Include the base Transaction class header

// Declaration of the OpenAccountTransaction class inheriting from Transaction
class OpenAccountTransaction : public Transaction
{
public:
    // Constructor and destructor declarations
    OpenAccountTransaction();
    virtual ~OpenAccountTransaction();
    
    // Constructor taking input stream as parameter
    OpenAccountTransaction(istream& istr);

    // Public member functions declarations
    bool IsValid() const; // Function to check if the transaction is valid
    string getFirstName() const; // Getter function for the first name
    string getLastName() const; // Getter function for the last name

private:
    // Private member variables for first and last names
    string firstName;
    string lastName;
};

#endif // OPEN_ACCOUNT_TRANSACTION_H
