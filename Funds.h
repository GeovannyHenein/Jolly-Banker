#pragma once
#include <iostream>
#include <string>
//#include "Transaction.h"
#include <vector>
//#include "Account.h"
using namespace std;
/*const int MAX_FUND_SIZE = 10;
const string FUNDS[10] = {
	"Money Market",
	"Prime Money Market",
	"Long-Term Bond",
	"Short-Term Bond",
	"Index Fund 500",
	"Capital Value Fund",
	"Growth Equity Fund",
	"Growth Index Fund",
	"Value Fund",
	"Value Stock Index"
};*/
class Funds
{
	//friend ostream& operator<<(ostream& os, const Funds& rhs);
public:
	Funds();
	~Funds();
	/*Funds(int fundType);
	~Funds();
	bool deposit(const int amount, const int fundType);
	bool withdraw(const int amount, const int fundType, Transaction* trans);
	int getFundID() const;
	bool setFundType(const int fundType);
	int getFundBalance(int index) const;
	//bool updateHistory(Transaction update);
	string getFundType() const;*/
private:
	//string Type;
	//int Balance;
	//int fundBalance[MAX_FUND_SIZE];
	//int fundType;
};



/*else if (fundType == 0)
{
int bal = fundBalance[0] + fundBalance[1];
int remaining = 0;
if ((fundBalance[0] < amount && fundBalance[1] < amount) && bal >= amount)
{
if (fundBalance[0] >= fundBalance[1])
{

remaining = amount - fundBalance[0];
fundBalance[0] = 0;
fundBalance[1] = remaining;
}
else if (fundBalance[0] <= fundBalance[1])
{

remaining = amount - fundBalance[1];
//account.setAccountID();
fundBalance[1] = 0;
fundBalance[0] = remaining;

}

Balance -= amount;
return true;
}
}

else if (fundType == 2 || fundType == 3)
{
int bal = fundBalance[2] + fundBalance[3];
int remaining = 0;

if ((fundBalance[2] < amount && fundBalance[3] < amount) && bal >= amount)
{

if (fundBalance[2] >= fundBalance[3])
{

remaining = amount - fundBalance[2];
fundBalance[2] = 0;
fundBalance[3] = remaining;
Balance -= amount;

}
else if (fundBalance[2] <= fundBalance[3])
{
remaining = amount - fundBalance[3];
fundBalance[3] = 0;
fundBalance[2] = remaining;
Balance -= amount;

}

if (fundType == 2)
{

historyLog[2] = historyLog[2] + "   " + to_string(withdrawAmount->getAccountID()) + " " + to_string(fundBalance[2]) + "\n";
historyLog[2] = historyLog[2] + "   " + to_string(withdrawAmount->getAccountID()) + " " + to_string(withdrawAmount->getAmount()) + "\n";
}
else if (fundType == 3)
{

}


Balance -= amount;
return true;
}
}*/