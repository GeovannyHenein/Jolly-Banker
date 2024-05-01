
#include "stdafx.h"
#include "Bank.h"
#include "Transaction.h"
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
Bank::Bank()
{
}

Bank::~Bank()
{
	while (!transactions.empty())
	{
		Transaction* save = transactions.front();
		delete save;
		save = NULL;
		transactions.pop();
	}
}

const BSTree Bank::getAccounts() const
{
	return accounts;
}

const queue<Transaction*> Bank::getTransactions() const
{
	return transactions;
}


void Bank::ProcessTransactionsInOrder()
{
	while (!transactions.empty())
	{

		if (transactions.front() != NULL)
		{
			
			PerformTransaction(transactions.front()); //perform transactions in order from the queue 
		}
		transactions.pop();
	}
	cout << "\nProcessing Done.";
}

Transaction* Bank::CreateTransaction(string file)
{
	stringstream fileStream(file); //convert to an istream
	Transaction* retVal = NULL;
	char type;
	fileStream >> type; // read the first char to determine 
	if (type == OPEN)	// which child class to dynamically allocate 
	{
		retVal = new OpenAccountTransaction(fileStream);
		retVal->setTransactionType(type);
	}
	else if (type == DEPOSIT)
	{
		retVal = new DepositTransaction(fileStream);
		retVal->setTransactionType(type);
	}
	else if (type == WITHDRAW)
	{
		retVal = new WithdrawTransaction(fileStream);
		retVal->setTransactionType(type);
	}
	else if (type == TRANSFER)
	{
		retVal = new TransferTransaction(fileStream);
		retVal->setTransactionType(type);
	}
	else if (type == HISTORY)
	{
		retVal = new HistoryTransaction(fileStream);
		retVal->setTransactionType(type);
	}

	return retVal;
}

bool Bank::CreateTransactionsFromFile()
{
	
	ifstream file;
	file.open(FILE_TO_READ);
	string readLine;
	if (!file)			// unable to find the file
	{
		return false;
	}

	while (!file.eof())				//read until the file is empty
	{
		getline(file, readLine);
		Transaction* transaction;					// creates a dynamically alloacted 
		transaction = CreateTransaction(readLine); // Transaction pointer of the proper type

		if (readLine == "")
			break;
		if (transaction->IsValid())
		{
			transactions.push(transaction);
		}

	}
	
	file.close();
	return true;

}

void Bank::DisplayAccounts() const
{
	if (!accounts.isEmpty())
	{
		cout << " Final Balances" << endl;
		accounts.Display();
	}
	else
	{
		cout << "Accounts are Empty." << endl;
	}
}

bool Bank::PerformTransaction(Transaction *& const trans)
{
	
	char Type = trans->getTransactionType();
	if (Type == OPEN)
	{
		OpenAccount(trans);
	}
	else if (Type == DEPOSIT)
	{
		Deposit(trans);
	}
	else if (Type == WITHDRAW)
	{
		Withdraw(trans);
	}
	else if (Type == TRANSFER)
	{
		Transfer(trans);
	}
	else if (Type == HISTORY)
	{
		DisplayHistory(trans);
	}
	else
	{
		cerr << "Invalid input" << endl;
		return false;
	}
	return true;
}
void Bank::Deposit(Transaction *& const trans)
{
	//dynamically cast to child class
	DepositTransaction* deposit = dynamic_cast<DepositTransaction*>(trans); 
	Account* accountToDeposit;
	if (accounts.Retrieve(deposit->getAccountID(), accountToDeposit)) // validate if account exists 
	{
		accountToDeposit->Deposit(trans);
	}
	else
	{
		cerr << "ERROR: Account " << deposit->getAccountID() << " not found.Deposit refused" << endl;
	}
	delete trans;
	trans = NULL;

}
void Bank::Withdraw(Transaction *& const trans)
{
\
	//dynamically casts to child class
	WithdrawTransaction* withdraw = dynamic_cast<WithdrawTransaction*>(trans);
	Account* accountToWithdraw;
	if (accounts.Retrieve(withdraw->getAccountID(), accountToWithdraw)) // verifying funds 
	{
		bool sufficientFunds = accountToWithdraw->Withdraw(withdraw->getAmount(), withdraw->getFundType(), trans);
		if(!sufficientFunds) //print error message if there are insufficientFunds
		{
			cerr << "ERROR: Not enough funds to withdraw " << withdraw->getAmount() << " from " <<
				accountToWithdraw->getFirstName() + " " + 
					accountToWithdraw->getLastName() << + " " + FUNDS[trans->getFundType()] << endl;
		}
	}
	else
	{
		cerr << "ERROR: Account " << to_string(trans->getAccountID()) << " not found. Withdraw refused" << endl;
	}
	
	delete trans;
	trans = NULL;

}

void Bank::Transfer(Transaction *& const trans)
{
	TransferTransaction* transfer = dynamic_cast<TransferTransaction*>(trans);
	Account* accountToTransFrom;
	Account* ToAccount;

	string accountNumber = to_string(trans->getAccountID());

	bool AccountExists = accounts.Retrieve(trans->getAccountID(), accountToTransFrom);
	bool OtherAccountExists = accounts.Retrieve(transfer->getSecondaryID(), ToAccount);
	if (AccountExists && OtherAccountExists)
	{
		accountToTransFrom->Transfer(trans, *ToAccount);	
	}
	else
	{
		accountNumber = trans->getAccountID() + " and " + transfer->getSecondaryID();
		if (AccountExists && !OtherAccountExists)
		{
			accountNumber = to_string(transfer->getSecondaryID());
		}
		else if (!AccountExists && OtherAccountExists)
		{
			accountNumber = to_string(trans->getAccountID());
		}
		
	
			cerr << "ERROR: Account " << accountNumber << " not found. Transferral refused" << endl;
		
	}
	delete trans;
	trans = NULL;

}
void Bank::OpenAccount(Transaction *& const trans)
{
	
	Account* pAccount;
	accounts.Retrieve(trans->getAccountID(), pAccount);
	if (pAccount == NULL) // verifyiing doesn't exit 
	{
		OpenAccountTransaction* open = dynamic_cast<OpenAccountTransaction*>(trans);
		pAccount = new Account(open->getFirstName(), open->getLastName(), open->getAccountID());
		accounts.Insert(pAccount);
	}
	else
	{
		cerr << "ERROR: Account " << trans->getAccountID() << " is already open. Transaction refused." << endl;
	}
	
	delete trans;
	trans = NULL;
}
void Bank::DisplayHistory(Transaction *& const trans) const
{
	Account* history;
	if (accounts.Retrieve(trans->getAccountID(), history))
	{
		if (trans->getFundType() == -1)
		{
			history->displayHistory();
		}
		else
		{
			history->displayHistoryBySpecifiedFund(trans->getFundType());
		}
	}
	else
	{
		cerr << "ERROR: Account " << trans->getAccountID() << " not found. History refused" << endl;
	}
	delete trans;
	trans = NULL;
}

