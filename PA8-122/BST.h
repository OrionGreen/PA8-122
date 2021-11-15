#pragma once
#include "TransactionNode.h"

class BST
{
public:
	BST();
	~BST();
	void setmpRoot(Node* const newRoot);
	Node* getmpRoot() const;
	void insert(const int units, const string& name);
	void inOrderTraversal();
	TransactionNode& findSmallest();
	TransactionNode& findLargest();

private:
	void chopTree(Node* pTree);
	void insert(Node* pTree, const int units, const string& name);
	void inOrderTraversal(Node*pTree);
	

	Node* mpRoot;
};

