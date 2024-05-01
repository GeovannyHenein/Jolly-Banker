
#ifndef BSTREE_H
#define BSTREE_H
#include "Account.h"

using namespace std;
class BSTree
{
public:
	BSTree();
	~BSTree();

	bool Insert(Account* account);
	bool Retrieve(const int &, Account * &) const;
	void Display() const;
	void Empty();
	bool isEmpty() const;


private:

	struct Node
	{
		Node();
		Node(Account* account);
		Account* pAcct;
		Node* right;
		Node* left;
	};

	Node* root;
	void Display(Node* rootNode) const;
	Node* Insert(Account* account, Node* rootNode);
	void Empty(Node* rootNode);
	bool Retrieve(const int& accountID, Account*& pFoundObject, Node* rootNode) const;
};

#endif