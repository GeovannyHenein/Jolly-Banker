#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include <string>
#include <sstream>
#include "Funds.h"
using namespace std;
const char OPEN = 'O';
const char DEPOSIT = 'D';
const char WITHDRAW = 'W';
const char TRANSFER = 'T';
const char HISTORY = 'H';
const int MAX_ID_LENGTH = 5;
class Transaction
{
public:
	Transaction();
	virtual ~Transaction();
	virtual void setTransactionType(char Type);
	virtual void setAccountID(int ID);
	virtual char getTransactionType() const;
	virtual int getAccountID() const;
	virtual int getFundType() const;
	virtual void setAmount(int amount);
	virtual string historyLog() const;
	virtual bool IsValid() const;
	virtual void setValid(bool valid);
protected:
	bool valid;
	char charType;
	int accountID;
	int fundType;
};


#endif 