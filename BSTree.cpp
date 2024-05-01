#include "stdafx.h"
#include "BSTree.h"
#include <iostream>

using namespace std;

BSTree::BSTree()
{
	root = NULL;
}

BSTree::Node::Node()
{
	pAcct = NULL;
	left = NULL;
	right = NULL;
}

BSTree::Node::Node(Account* account)
{
	pAcct = account;
	left = NULL;
	right = NULL;
}

BSTree::~BSTree()
{
	Empty();
}

bool BSTree::Insert(Account* account)
{
	if (root == NULL)
	{
		Node* temp = new Node(account);
		root = temp;
		return true;
	}
	else
	{
		Insert(account, root);
	}

	return false;
}


BSTree::Node* BSTree::Insert(Account* account, Node* rootNode)
{
	if (rootNode == NULL)
	{
		Node* temp = new Node;
		temp->pAcct = account;
		temp->left = NULL;
		temp->right = NULL;
		rootNode = temp;
		return temp;
	}
	else
	{
		if (account->getID() < rootNode->pAcct->getID())
		{
			rootNode->left = Insert(account, rootNode->left);
		}
		else
		{
			rootNode->right = Insert(account, rootNode->right);
		}


	}

	return rootNode;
}

bool BSTree::Retrieve(const int& accountID, Account*& pFoundObject) const
{
	Node* temp = root;
	return Retrieve(accountID, pFoundObject, temp);
}


bool BSTree::Retrieve(const int& accountID, Account*& pFoundObject, Node* rootNode) const
{

	if (rootNode != NULL)
	{
		if (accountID == rootNode->pAcct->getID())
		{
			pFoundObject = rootNode->pAcct;
			return true;
		}
		else if (accountID < rootNode->pAcct->getID())
		{

			return Retrieve(accountID, pFoundObject, rootNode->left);
		}
		else
		{

			return Retrieve(accountID, pFoundObject, rootNode->right);
		}
	}

	pFoundObject = NULL;
	return false;
}
void BSTree::Display() const
{

	Display(root);
}

void BSTree::Display(Node* rootNode) const
{
	if (rootNode != NULL)
	{
		Display(rootNode->left);
		cout << *rootNode->pAcct << endl;
		Display(rootNode->right);
	}
}
void BSTree::Empty()
{
	Empty(root);
}

void BSTree::Empty(Node* rootNode)
{
	if (rootNode != NULL)
	{
		Empty(rootNode->left);
		Empty(rootNode->right);
		delete rootNode->pAcct;
		delete rootNode;
	}
}

bool BSTree::isEmpty() const
{
	return root == NULL;
}
