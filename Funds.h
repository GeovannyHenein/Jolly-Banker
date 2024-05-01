#pragma once
#include <iostream>
#include <string>
//#include "Transaction.h" // Transaction class not included in this file
#include <vector>
//#include "Account.h" // Account class not included in this file
using namespace std;

// Declaration of the Funds class
class Funds
{
	//friend ostream& operator<<(ostream& os, const Funds& rhs); // Declaration of a friend function

public:
	// Constructor
	Funds();
	
	// Destructor
	~Funds();
	
	/* Commented-out member function declarations
	   These member functions are currently commented out and likely represent 
	   potential functionality related to the Funds class. They include:
	   - Constructor(s) and Destructor
	   - Functions for depositing and withdrawing funds
	   - Functions for retrieving fund information
	   - Functions for updating history
	   - Function for getting the fund type
	*/
	/*
	Funds(int fundType);
	~Funds();
	bool deposit(const int amount, const int fundType);
	bool withdraw(const int amount, const int fundType, Transaction* trans);
	int getFundID() const;
	bool setFundType(const int fundType);
	int getFundBalance(int index) const;
	//bool updateHistory(Transaction update);
	string getFundType() const;
	*/
	
private:
	/* Commented-out data members
	   These data members are currently commented out and may represent 
	   potential attributes of the Funds class. They include:
	   - Type: Possibly the type of fund
	   - Balance: Possibly the total balance of the fund
	   - fundBalance: Possibly an array or vector to store balances of different funds
	   - fundType: Possibly an identifier for the type of fund
	*/
	/*
	string Type;
	int Balance;
	int fundBalance[MAX_FUND_SIZE];
	int fundType;
	*/
	
	/* Commented-out code block
	   This block contains conditional logic for handling fund deposits and withdrawals
	   based on fund type. It appears to be an incomplete or discarded implementation
	   of fund management logic. It includes if-else statements for different fund types
	   and their corresponding actions.
	*/
	/*
	else if (fundType == 0)
	{
		// Code block for fund type 0
	}
	else if (fundType == 2 || fundType == 3)
	{
		// Code block for fund types 2 and 3
	}
	*/
};
