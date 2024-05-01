#ifndef WITHDRAW_TRANSACTION_H
#define WITHDRAW_TRANSACTION_H
#include "Transaction.h"

class WithdrawTransaction : public Transaction
{

public:
	WithdrawTransaction();
	virtual ~WithdrawTransaction();
	WithdrawTransaction(istream& istr);
	int getAmount() const;
	void setAmount(int amount);
	string historyLog() const;
	bool IsValid() const;


private:
	int amount;

};
#endif