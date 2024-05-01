#ifndef OPEN_ACCOUNT_TRANSACTION_H
#define OPEN_ACCOUNT_TRANSACTION_H
#include "Transaction.h"

class OpenAccountTransaction : public Transaction
{
public:
	OpenAccountTransaction();
	virtual ~OpenAccountTransaction();
	OpenAccountTransaction(istream& istr);
	bool IsValid() const;
	string getFirstName() const;
	string getLastName() const;
private:
	string firstName;
	string lastName;
};
#endif
