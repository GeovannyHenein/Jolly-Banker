# JollyBanker Project Overview

## Project Structure

The JollyBanker project is organized into several files, each serving a specific purpose:

1. `Account.h`: Defines the `Account` class, representing bank accounts.
2. `BSTree.h`: Defines the `BSTree` class, representing a binary search tree for storing bank accounts.
3. `Bank.h`: Defines the `Bank` class, representing a bank with methods for processing transactions and managing accounts.
4. `Transaction.h`: Defines the `Transaction` class, representing generic banking transactions.
5. `Funds.h`: Defines the `Funds` class, representing funds within bank accounts.
6. `OpenAccountTransaction.h`: Defines the `OpenAccountTransaction` class, representing the opening of a new bank account transaction.
7. `DepositTransaction.h`: Defines the `DepositTransaction` class, representing a deposit transaction.
8. `WithdrawTransaction.h`: Defines the `WithdrawTransaction` class, representing a withdrawal transaction.
9. `TransferTransaction.h`: Defines the `TransferTransaction` class, representing a transfer transaction between accounts.
10. `HistoryTransaction.h`: Defines the `HistoryTransaction` class, representing a transaction to display transaction history.
11. `JollyBanker.cpp`: Main entry point for the application, where the `Bank` class is instantiated, transactions are processed, and accounts are displayed.
12. `stdafx.h`: Precompiled header file.
13. `stdafx.cpp`: Source file for precompiled header.
14. `Account.cpp`: Implementation file for the `Account` class.
15. `BSTree.cpp`: Implementation file for the `BSTree` class.
16. `Bank.cpp`: Implementation file for the `Bank` class.
17. `Transaction.cpp`: Implementation file for the `Transaction` class.
18. `Funds.cpp`: Implementation file for the `Funds` class.
19. `OpenAccountTransaction.cpp`: Implementation file for the `OpenAccountTransaction` class.
20. `DepositTransaction.cpp`: Implementation file for the `DepositTransaction` class.
21. `WithdrawTransaction.cpp`: Implementation file for the `WithdrawTransaction` class.
22. `TransferTransaction.cpp`: Implementation file for the `TransferTransaction` class.
23. `HistoryTransaction.cpp`: Implementation file for the `HistoryTransaction` class.

## File Descriptions

### Header Files
- **Account.h**: Defines the `Account` class for managing bank accounts.
- **BSTree.h**: Defines the `BSTree` class, a binary search tree for storing accounts.
- **Bank.h**: Defines the `Bank` class, representing a bank with account management and transaction processing.
- **Transaction.h**: Defines the `Transaction` class, a base class for all banking transactions.
- **Funds.h**: Defines the `Funds` class for managing funds within accounts.
- **OpenAccountTransaction.h**: Defines the `OpenAccountTransaction` class for opening new bank accounts.
- **DepositTransaction.h**: Defines the `DepositTransaction` class for depositing funds into accounts.
- **WithdrawTransaction.h**: Defines the `WithdrawTransaction` class for withdrawing funds from accounts.
- **TransferTransaction.h**: Defines the `TransferTransaction` class for transferring funds between accounts.
- **HistoryTransaction.h**: Defines the `HistoryTransaction` class for displaying transaction history.

### Source Files
- **JollyBanker.cpp**: Main entry point for the application.
- **stdafx.cpp**: Source file for precompiled header.
- **Account.cpp**: Implementation of the `Account` class methods.
- **BSTree.cpp**: Implementation of the `BSTree` class methods.
- **Bank.cpp**: Implementation of the `Bank` class methods.
- **Transaction.cpp**: Implementation of the `Transaction` class methods.
- **Funds.cpp**: Implementation of the `Funds` class methods.
- **OpenAccountTransaction.cpp**: Implementation of the `OpenAccountTransaction` class methods.
- **DepositTransaction.cpp**: Implementation of the `DepositTransaction` class methods.
- **WithdrawTransaction.cpp**: Implementation of the `WithdrawTransaction` class methods.
- **TransferTransaction.cpp**: Implementation of the `TransferTransaction` class methods.
- **HistoryTransaction.cpp**: Implementation of the `HistoryTransaction` class methods.

## Data Structures Used

The project utilizes the following data structures:

1. **Binary Search Tree (BST)**:
   - Used in the `BSTree` class to store and manage bank accounts efficiently. Provides fast lookup, insertion, and deletion operations.

2. **Vectors**:
   - Utilized in the `HistoryTransaction` class to store transaction history entries. Vectors offer dynamic resizing and efficient access to elements.

## Usage
- The `JollyBanker.cpp` file serves as the entry point for the application.
- It instantiates a `Bank` object, processes transactions, and displays account information.

## Conclusion
The JollyBanker project is a banking application implemented in C++. It provides functionality for managing bank accounts, processing various transactions, and displaying transaction history. Each class and file in the project serves a specific purpose in achieving these goals.
