#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include "Transaction.h"
#include "DepositTransaction.h"
#include "OpenAccountTransaction.h"
#include "WithdrawTransaction.h"
#include "HistoryTransaction.h"
#include "TransferTransaction.h"
const int MAX_FUND_SIZE = 10;
const string FUNDS[10] = {
	"Money Market",
	"Prime Money Market",
	"Long-Term Bond",
	"Short-Term Bond",
	"500 Index Fund",
	"Capital Value Fund",
	"Growth Equity Fund",
	"Growth Index Fund",
	"Value Fund",
	"Value Stock Index"
};

using namespace std;
class Account
{
	friend ostream& operator<<(ostream& os, const Account& rhs);
public:
	Account();
	Account(string firstName, string lastName, int ID);
	~Account();
	void setName(string firstName, string lastName);
	void setID(int ID);
	string getFirstName() const;
	string getLastName() const;
	bool Deposit(Transaction *& const depositAmount);
	bool Withdraw(int amount, int fundType, Transaction *& const withdrawAmount);
	bool Transfer(Transaction *& const transferAmount, Account& accountToTransfer);
	int getID() const;
	void displayHistory() const;
	void displayHistoryBySpecifiedFund(int fundType) const;
	bool operator<(const Account& rhs) const;
	bool operator>(const Account& rhs) const;
	bool operator<=(const Account& rhs) const;
	bool operator>=(const Account& rhs) const;
	bool operator==(const Account& rhs) const;
	bool operator!=(const Account& rhs) const;
	enum FundType
	{
		MoneyMarket,
		PrimeMoneyMarket,
		LongTermBond,
		ShortTermBond,
		IndexFund500,
		CapitalValueFund,
		GrowthEquityFund,
		GrowthIndexFund,
		ValueFund,
		ValueStockIndex
	};
	
private:
	bool withdrawHelper(int firstFund, int secondFund, int amount, Transaction *& const trans);
	string firstName;
	string lastName;
	int ID;
	int Balance;
	int fundType;
	vector<bool> active;
	vector<int> fundBalance;
	vector<HistoryTransaction> historyLog;

};

#endif