#include "stdafx.h" // Precompiled header
#include "Bank.h" // Include header file for Bank class
#include "Transaction.h" // Include header file for Transaction class
#include <fstream> // File stream input/output operations
#include <string> // Standard string library
#include <sstream> // String stream for parsing

using namespace std;

// Default constructor
Bank::Bank()
{
}

// Destructor
Bank::~Bank()
{
    // Free memory allocated for transactions
    while (!transactions.empty())
    {
        Transaction* save = transactions.front();
        delete save;
        save = NULL;
        transactions.pop();
    }
}

// Getter function for accounts
const BSTree Bank::getAccounts() const
{
    return accounts;
}

// Getter function for transactions
const queue<Transaction*> Bank::getTransactions() const
{
    return transactions;
}

// Process transactions in the order they were received
void Bank::ProcessTransactionsInOrder()
{
    while (!transactions.empty())
    {
        if (transactions.front() != NULL)
        {
            PerformTransaction(transactions.front()); // Perform transactions in order from the queue
        }
        transactions.pop();
    }
    cout << "\nProcessing Done.";
}

// Create transaction object based on input file string
Transaction* Bank::CreateTransaction(string file)
{
    stringstream fileStream(file); // Convert to an istream
    Transaction* retVal = NULL;
    char type;
    fileStream >> type; // Read the first char to determine transaction type
    if (type == OPEN) // Determine transaction type and create corresponding object
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

// Create transactions from input file
bool Bank::CreateTransactionsFromFile()
{
    ifstream file;
    file.open(FILE_TO_READ); // Open input file
    string readLine;
    if (!file) // Check if file opened successfully
    {
        return false; // Return false if file not found
    }

    // Read lines from file and create transactions
    while (!file.eof())
    {
        getline(file, readLine);
        Transaction* transaction; // Dynamically allocate transaction pointer of the proper type
        transaction = CreateTransaction(readLine);
        if (readLine == "")
            break;
        if (transaction->IsValid())
        {
            transactions.push(transaction); // Push valid transactions into the queue
        }
    }

    file.close(); // Close input file
    return true; // Return true if transactions created successfully
}

// Display account balances
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

// Perform transaction based on its type
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

// Process deposit transaction
void Bank::Deposit(Transaction *& const trans)
{
    DepositTransaction* deposit = dynamic_cast<DepositTransaction*>(trans); // Dynamically cast to child class
    Account* accountToDeposit;
    if (accounts.Retrieve(deposit->getAccountID(), accountToDeposit)) // Validate if account exists
    {
        accountToDeposit->Deposit(trans); // Deposit funds into the account
    }
    else
    {
        cerr << "ERROR: Account " << deposit->getAccountID() << " not found. Deposit refused" << endl;
    }
    delete trans;
    trans = NULL;
}

// Process withdrawal transaction
void Bank::Withdraw(Transaction *& const trans)
{
    WithdrawTransaction* withdraw = dynamic_cast<WithdrawTransaction*>(trans); // Dynamically cast to child class
    Account* accountToWithdraw;
    if (accounts.Retrieve(withdraw->getAccountID(), accountToWithdraw)) // Verify if account exists
    {
        bool sufficientFunds = accountToWithdraw->Withdraw(withdraw->getAmount(), withdraw->getFundType(), trans);
        if (!sufficientFunds) // Print error message if there are insufficient funds
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

// Process transfer transaction
void Bank::Transfer(Transaction *& const trans)
{
    TransferTransaction* transfer = dynamic_cast<TransferTransaction*>(trans); // Dynamically cast to child class
    Account* accountToTransFrom;
    Account* ToAccount;

    string accountNumber = to_string(trans->getAccountID());

    bool AccountExists = accounts.Retrieve(trans->getAccountID(), accountToTransFrom);
    bool OtherAccountExists = accounts.Retrieve(transfer->getSecondaryID(), ToAccount);
    if (AccountExists && OtherAccountExists)
    {
        accountToTransFrom->Transfer(trans, *ToAccount); // Perform transfer between accounts
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

// Process account opening transaction
void Bank::OpenAccount(Transaction *& const trans)
{
    Account* pAccount;
    accounts.Retrieve(trans->getAccountID(), pAccount);
    if (pAccount == NULL) // Check if account doesn't exist
    {
        OpenAccountTransaction* open = dynamic_cast<OpenAccountTransaction*>(trans);
        pAccount = new Account(open->getFirstName(), open->getLastName(), open->getAccountID());
        accounts.Insert(pAccount); // Insert new account into the binary search tree
    }
    else
    {
        cerr << "ERROR: Account " << trans->getAccountID() << " is already open. Transaction refused." << endl;
    }
    delete trans;
    trans = NULL;
}

// Display transaction history
void Bank::DisplayHistory(Transaction *& const trans) const
{
    Account* history;
    if (accounts.Retrieve(trans->getAccountID(), history)) // Verify if account exists
    {
        if (trans->getFundType() == -1)
        {
            history->displayHistory(); // Display history of all funds
        }
        else
        {
            history->displayHistoryBySpecifiedFund(trans->getFundType()); // Display history of a specified fund
        }
    }
    else
    {
        cerr << "ERROR: Account " << trans->getAccountID() << " not found. History refused" << endl;
    }
    delete trans;
    trans = NULL;
}
