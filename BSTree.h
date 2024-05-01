#ifndef BSTREE_H // Header guard to prevent multiple inclusion
#define BSTREE_H

#include "Account.h" // Include the header file for the Account class

using namespace std;

// Declaration of the BSTree class
class BSTree
{
public:
    // Constructor and Destructor
    BSTree(); // Constructor
    ~BSTree(); // Destructor

    // Public member functions
    bool Insert(Account* account); // Insert an account into the tree
    bool Retrieve(const int&, Account * &) const; // Retrieve an account from the tree
    void Display() const; // Display all accounts in the tree
    void Empty(); // Delete all nodes and accounts in the tree
    bool isEmpty() const; // Check if the tree is empty

private:
    // Private nested Node structure
    struct Node
    {
        Node(); // Default constructor
        Node(Account* account); // Constructor with account parameter
        Account* pAcct; // Pointer to the account object
        Node* right; // Pointer to the right child node
        Node* left; // Pointer to the left child node
    };

    Node* root; // Pointer to the root node of the tree
    // Private member functions
    void Display(Node* rootNode) const; // Helper function to display the tree recursively
    Node* Insert(Account* account, Node* rootNode); // Helper function to insert an account recursively
    void Empty(Node* rootNode); // Helper function to delete all nodes and accounts recursively
    bool Retrieve(const int& accountID, Account*& pFoundObject, Node* rootNode) const; // Helper function to retrieve an account recursively
};

#endif // End of header guard
