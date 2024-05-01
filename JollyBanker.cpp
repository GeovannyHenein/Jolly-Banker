// JollyBanker.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Account.h"
#include "BSTree.h"
#include "Bank.h"
#include "Transaction.h"
#include <string.h>

int main()
{
	Bank jolly;
	jolly.CreateTransactionsFromFile();
	jolly.ProcessTransactionsInOrder();
	jolly.DisplayAccounts();
    return 0;
}

