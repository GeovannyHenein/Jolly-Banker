#ifndef DEPOSIT_TRANSACTION_H
#define DEPOSIT_TRANSACTION_H
#include "Transaction.h"

class DepositTransaction : public Transaction
{

public:
	DepositTransaction();
	virtual ~DepositTransaction();
	DepositTransaction(istream& istr);
	string DepositTransaction::historyLog() const;
	void setAmount(int amount);
	int getAmount() const;
	bool IsValid() const;

private:
	int amount;
};

#endif