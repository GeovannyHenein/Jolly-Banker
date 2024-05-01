#ifndef TRANSFER_TRANSACTION_H
#define TRANSFER_TRANSACTION_H
#include "Transaction.h"
#include <sstream>
class TransferTransaction : public Transaction
{
public:
	TransferTransaction();
	virtual ~TransferTransaction();
	TransferTransaction(istream& istr);
	int getFundType() const;
	int getSecondaryID() const;
	int getSecondFundType() const;
	int getAmount() const;
	void setAmount(int amount);
	string historyLog() const;
	bool IsValid() const;


private:
	int secondFundType;
	int secondaryID;
	int amount;
};

#endif