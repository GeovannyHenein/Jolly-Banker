#ifndef HISTORY_TRANSACTION_H
#define HISTORY_TRANSACTION_H
#include "Transaction.h"
class HistoryTransaction : public Transaction
{
	friend ostream& operator<<(ostream& istr, const HistoryTransaction& rhs);
public:
	HistoryTransaction();
	virtual ~HistoryTransaction();
	HistoryTransaction(istream& istr);
	void updateHistory(Transaction* trans, bool valid);
	bool IsValid() const;

private:
	vector<string> history;
};

#endif