#include "stdafx.h" // Precompiled header (if used)
#include "BSTree.h" // Include header file for BSTree class
#include <iostream> // Include header file for input/output operations

using namespace std;

// Constructor for BSTree class
BSTree::BSTree()
{
	root = NULL; // Initialize root pointer to null
}

// Default constructor for Node class
BSTree::Node::Node()
{
	pAcct = NULL; // Initialize account pointer to null
	left = NULL; // Initialize left child pointer to null
	right = NULL; // Initialize right child pointer to null
}

// Constructor for Node class with account parameter
BSTree::Node::Node(Account* account)
{
	pAcct = account; // Set account pointer
	left = NULL; // Initialize left child pointer to null
	right = NULL; // Initialize right child pointer to null
}

// Destructor for BSTree class
BSTree::~BSTree()
{
	Empty(); // Call Empty function to delete all nodes and accounts
}

// Function to insert an account into the BSTree
bool BSTree::Insert(Account* account)
{
	if (root == NULL) // If tree is empty
	{
		Node* temp = new Node(account); // Create a new node with the account
		root = temp; // Set root to the new node
		return true; // Insertion successful
	}
	else
	{
		Insert(account, root); // Call private insert function to insert into appropriate position
	}

	return false; // Insertion failed
}

// Private recursive function to insert an account into the BSTree
BSTree::Node* BSTree::Insert(Account* account, Node* rootNode)
{
	if (rootNode == NULL) // If current node is null
	{
		Node* temp = new Node; // Create a new node
		temp->pAcct = account; // Set account pointer
		temp->left = NULL; // Initialize left child pointer to null
		temp->right = NULL; // Initialize right child pointer to null
		rootNode = temp; // Set current node to the new node
		return temp; // Return the new node
	}
	else
	{
		if (account->getID() < rootNode->pAcct->getID()) // If account ID is less than current node's account ID
		{
			rootNode->left = Insert(account, rootNode->left); // Insert into left subtree
		}
		else
		{
			rootNode->right = Insert(account, rootNode->right); // Insert into right subtree
		}
	}

	return rootNode; // Return current node
}

// Function to retrieve an account from the BSTree
bool BSTree::Retrieve(const int& accountID, Account*& pFoundObject) const
{
	Node* temp = root; // Start from the root node
	return Retrieve(accountID, pFoundObject, temp); // Call private retrieve function
}

// Private recursive function to retrieve an account from the BSTree
bool BSTree::Retrieve(const int& accountID, Account*& pFoundObject, Node* rootNode) const
{
	if (rootNode != NULL) // If current node is not null
	{
		if (accountID == rootNode->pAcct->getID()) // If account ID matches current node's account ID
		{
			pFoundObject = rootNode->pAcct; // Set found object pointer to the current account
			return true; // Account found
		}
		else if (accountID < rootNode->pAcct->getID()) // If account ID is less than current node's account ID
		{
			return Retrieve(accountID, pFoundObject, rootNode->left); // Search in left subtree
		}
		else // If account ID is greater than current node's account ID
		{
			return Retrieve(accountID, pFoundObject, rootNode->right); // Search in right subtree
		}
	}

	pFoundObject = NULL; // Set found object pointer to null
	return false; // Account not found
}

// Function to display all accounts in the BSTree
void BSTree::Display() const
{
	Display(root); // Call private display function starting from the root
}

// Private recursive function to display all accounts in the BSTree
void BSTree::Display(Node* rootNode) const
{
	if (rootNode != NULL) // If current node is not null
	{
		Display(rootNode->left); // Display left subtree
		cout << *rootNode->pAcct << endl; // Display current account
		Display(rootNode->right); // Display right subtree
	}
}

// Function to delete all nodes and accounts in the BSTree
void BSTree::Empty()
{
	Empty(root); // Call private empty function starting from the root
}

// Private recursive function to delete all nodes and accounts in the BSTree
void BSTree::Empty(Node* rootNode)
{
	if (rootNode != NULL) // If current node is not null
	{
		Empty(rootNode->left); // Delete left subtree
		Empty(rootNode->right); // Delete right subtree
		delete rootNode->pAcct; // Delete current account
		delete rootNode; // Delete current node
	}
}

// Function to check if the BSTree is empty
bool BSTree::isEmpty() const
{
	return root == NULL; // Return true if root is null, false otherwise
}
