
#ifndef BANK_H
#define BANK_H
#include "BSTree.h"
#include "Transaction.h"
#include "OpenAccountTransaction.h"
#include "DepositTransaction.h"
#include "WithdrawTransaction.h"
#include "TransferTransaction.h"
#include "HistoryTransaction.h"
#include <queue>
#include <string>
using namespace std;
const string FILE_TO_READ = "BankTransIn.txt";
class Bank
{
public:
	Bank();
	~Bank();
	const BSTree getAccounts() const;
	const queue<Transaction*> getTransactions() const;
	bool CreateTransactionsFromFile();
	void ProcessTransactionsInOrder();
	void DisplayAccounts() const;
	
private:
	//private helper functions to process transactions 
	Transaction* CreateTransaction(string file);
	bool PerformTransaction(Transaction *& const trans);
	void Deposit(Transaction*& trans);
	void Withdraw(Transaction *& const trans);
	void Transfer(Transaction *& const trans);
	void OpenAccount(Transaction *& const trans);
	void DisplayHistory(Transaction *& const trans) const;
	 
	BSTree accounts;
	queue<Transaction*> transactions;
};

#endif 