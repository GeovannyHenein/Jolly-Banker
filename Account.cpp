#include "stdafx.h" // Precompiled header
#include "Account.h" // Include header file for Account class
#include <iostream> // Input-output operations
#include "TransferTransaction.h" // Include header file for TransferTransaction class

using namespace std;

// Default constructor
Account::Account()
{
    firstName = ""; // Initialize firstName
    lastName = ""; // Initialize lastName
    Balance = 0; // Initialize Balance
    fundType = 0; // Initialize fundType
    ID = 0; // Initialize ID
}

// Constructor with parameters
Account::Account(string firstName, string lastName, int ID)
{
    // Initialize firstName, lastName, ID, and the array that holds the individual balances of the funds
    setName(firstName, lastName);
    setID(ID);
    fundBalance.resize(MAX_FUND_SIZE);
    historyLog.resize(MAX_FUND_SIZE);
    active.resize(MAX_FUND_SIZE);
    for (int i = 0; i < MAX_FUND_SIZE; i++)
    {
        fundBalance[i] = 0; // Initialize fund balance
        active[i] = false; // Initialize activity status of funds
    }
    Balance = 0; // Initialize total balance
}

// Destructor
Account::~Account()
{
    // Destructor does not require any action
}

// Set first name and last name
void Account::setName(string firstName, string lastName)
{
    this->firstName = firstName; // Set first name
    this->lastName = lastName; // Set last name
}

// Set account ID
void Account::setID(int ID)
{
    this->ID = ID; // Set account ID
}

// Get first name
string Account::getFirstName() const
{
    return firstName; // Return first name
}

// Get last name
string Account::getLastName() const
{
    return lastName; // Return last name
}

// Get account ID
int Account::getID() const
{
    return ID; // Return account ID
}

// Overloaded less than operator
bool Account::operator<(const Account& rhs) const
{
    return ID < rhs.ID; // Compare account IDs
}

// Overloaded greater than operator
bool Account::operator>(const Account& rhs) const
{
    return ID > rhs.ID; // Compare account IDs
}

// Overloaded less than or equal to operator
bool Account::operator<=(const Account& rhs) const
{
    return ID <= rhs.ID; // Compare account IDs
}

// Overloaded greater than or equal to operator
bool Account::operator>=(const Account& rhs) const
{
    return ID >= rhs.ID; // Compare account IDs
}

// Overloaded equality operator
bool Account::operator==(const Account& rhs) const
{
    return ID == rhs.ID; // Compare account IDs
}

// Overloaded inequality operator
bool Account::operator!=(const Account& rhs) const
{
    return ID != rhs.ID; // Compare account IDs
}

// Deposit funds into the account
bool Account::Deposit(Transaction *& const trans)
{
    DepositTransaction* depositAmount = dynamic_cast<DepositTransaction*>(trans); // Downcast to DepositTransaction pointer
    int amount = depositAmount->getAmount(); // Retrieve amount to deposit
    int fundType = depositAmount->getFundType(); // Retrieve fund type to deposit to
    if (amount < 0) // Verify valid amount to deposit
    {
        return false; // Invalid deposit amount
    }
    else
    {
        Balance += amount; // Update total balance
        fundBalance[fundType] += amount; // Update individual fund balance
        historyLog[fundType].updateHistory(trans, true); // Update transaction history
        active[fundType] = true; // Mark fund as active
        return true; // Deposit successful
    }
}

// Withdraw funds from the account
bool Account::Withdraw(int amount, int fundType, Transaction *& const trans)
{
    if (amount > Balance) // Verify valid amount to withdraw
    {
        historyLog[fundType].updateHistory(trans, false); // Update transaction history
        active[fundType] = true; // Mark fund as active
        return false; // Insufficient funds
    }
    else if (amount <= fundBalance[fundType]) // Sufficient funds in the specified fund
    {
        Balance -= amount; // Update total balance
        fundBalance[fundType] -= amount; // Update individual fund balance
        historyLog[fundType].updateHistory(trans, true); // Update transaction history
        active[fundType] = true; // Mark fund as active
        return true; // Withdrawal successful
    }
    else // Insufficient funds in the specified fund
    {
        if (fundType == MoneyMarket) // Check if withdrawing from Money Market fund
        {
            if (withdrawHelper(MoneyMarket, PrimeMoneyMarket, amount, trans)) // Attempt to withdraw from Prime Money Market fund
            {
                return true; // Withdrawal successful
            }
        }
        else if (fundType == PrimeMoneyMarket) // Check if withdrawing from Prime Money Market fund
        {
            if (withdrawHelper(PrimeMoneyMarket, MoneyMarket, amount, trans)) // Attempt to withdraw from Money Market fund
            {
                return true; // Withdrawal successful
            }
        }
        else if (fundType == LongTermBond) // Check if withdrawing from Long Term Bond fund
        {
            if (withdrawHelper(LongTermBond, ShortTermBond, amount, trans)) // Attempt to withdraw from Short Term Bond fund
            {
                return true; // Withdrawal successful
            }
        }
        else if (fundType == ShortTermBond) // Check if withdrawing from Short Term Bond fund
        {
            if (withdrawHelper(ShortTermBond, LongTermBond, amount, trans)) // Attempt to withdraw from Long Term Bond fund
            {
                return true; // Withdrawal successful
            }
        }
        else // Unsupported fund type
        {
            historyLog[fundType].updateHistory(trans, false); // Update transaction history
            return false; // Withdrawal unsuccessful
        }
    }
    return false; // Withdrawal unsuccessful
}

// Helper function for withdrawing from linked funds
bool Account::withdrawHelper(int firstFund, int secondFund, int amount, Transaction *& const trans)
{
    int combinedBalance = fundBalance[firstFund] + fundBalance[secondFund]; // Calculate combined balance of linked funds
    if (combinedBalance >= amount) // Verify combined balance is sufficient for withdrawal
    {
        trans->setAmount(fundBalance[firstFund]); // Set amount to withdraw from first fund
        historyLog[firstFund].updateHistory(trans, true); // Update transaction history for first fund
        int remaining = amount - fundBalance[firstFund]; // Calculate remaining amount to withdraw from second fund
        fundBalance[firstFund] = 0; // Empty first fund
        fundBalance[secondFund] -= remaining; // Update balance of second fund
        Balance -= amount; // Update total balance
        trans->setAmount(remaining); // Set amount to withdraw from second fund
        historyLog[secondFund].updateHistory(trans, true); // Update transaction history for second fund
        active[firstFund] = true; // Mark first fund as active
        active[secondFund] = true; // Mark second fund as active
        return true; // Withdrawal successful
    }
    historyLog[firstFund].updateHistory(trans, false); // Update transaction history for first fund
    return false; // Withdrawal unsuccessful
}

// Transfer funds to another account
bool Account::Transfer(Transaction *& const trans, Account& accountToTransfer)
{
    TransferTransaction* transferAmount = dynamic_cast<TransferTransaction*>(trans); // Downcast to TransferTransaction pointer
    int fundType = transferAmount->getFundType(); // Retrieve fund type to transfer from
    int toFund = transferAmount->getSecondFundType(); // Retrieve fund type to transfer to
    int amount = transferAmount->getAmount(); // Retrieve amount to transfer

    if (amount < 0) // Verify valid amount to transfer
    {
        return false; // Invalid transfer amount
    }
    else
    {
        Withdraw(amount, fundType, trans); // Withdraw funds from sender's account
        accountToTransfer.Balance += amount; // Update balance of recipient's account
        accountToTransfer.fundBalance[toFund] += amount; // Update balance of recipient's fund
        trans->setAmount(amount); // Set transfer amount
        accountToTransfer.historyLog[toFund].updateHistory(trans, true); // Update transaction history of recipient's fund
        active[toFund] = true; // Mark fund as active
        return true; // Transfer successful
    }
    return false; // Transfer unsuccessful
}

// Display transaction history of all funds
void Account::displayHistory() const
{
    cout << "Transaction History for " << firstName << " " << lastName << " by fund." << endl;
    for (int i = 0; i < MAX_FUND_SIZE; i++)
    {
        if (active[i] != false)
        {
            cout << FUNDS[i] << ": $" << fundBalance[i] << endl; // Display fund balance
            cout << historyLog[i]; // Display transaction history
        }
    }
}

// Display transaction history of a specified fund
void Account::displayHistoryBySpecifiedFund(int fundType) const
{
    cout << "Transaction History for " << firstName << " " << 
        lastName << " " << FUNDS[fundType] << ": $" << fundBalance[fundType] << endl;
    cout << historyLog[fundType];
}

// Overloaded stream insertion operator to display account information
ostream& operator<<(ostream& os, const Account& rhs)
{
    os << rhs.getFirstName() << " " << rhs.getLastName() << " Account ID: " << rhs.getID() << endl;
    for (int i = 0; i < MAX_FUND_SIZE; i++)
    {
        os << "\t" << FUNDS[i] << ": $" << rhs.fundBalance[i] << endl; // Display fund balances
    }
    return os;
}
