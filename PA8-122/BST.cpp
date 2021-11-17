#include "BST.h"

BST::BST() {
	this->mpRoot = nullptr;
}
BST::~BST() {
	chopTree(this->mpRoot);
}
void BST::setmpRoot(Node* const newRoot) {
	this->mpRoot = newRoot;
}
Node* BST::getmpRoot() const {
	return this->mpRoot;
}
void BST::insert(const int units, const string& name) {
	insert(this->mpRoot, units, name);
}
void BST::inOrderTraversal() {
	inOrderTraversal(this->mpRoot);
}
TransactionNode& BST::findSmallest() {
	TransactionNode* smallest = dynamic_cast<TransactionNode*>(this->getmpRoot());
	while (smallest->getpLeft() != nullptr) {
		smallest = dynamic_cast<TransactionNode*>(smallest->getpLeft());
	}
	return *smallest;
}
TransactionNode& BST::findLargest() {
	TransactionNode* biggest = dynamic_cast<TransactionNode*>(this->getmpRoot());
	while (biggest->getpRight() != nullptr) {
		biggest = dynamic_cast<TransactionNode*>(biggest->getpRight());
	}
	return *biggest;
}

//private
void BST::chopTree(Node* pTree) {
	
	if (pTree != nullptr) {
		chopTree(pTree->getpLeft());
		chopTree(pTree->getpRight());
		delete pTree;
	}
}
void BST::insert(Node*& pTree, const int units, const string& name) {
	if (pTree == nullptr)
	{
		Node* pMem = new TransactionNode(name, units);
		pTree = pMem;
		
	}
	else
	{
		if (dynamic_cast<TransactionNode*>(pTree)->getUnits() > units)
		{
			if (pTree->getpLeft() == nullptr)
			{
				pTree->setpLeft(new TransactionNode(name, units));
			}
			else
			{

				insert(pTree->getpLeft(), units, name);
			}
		}

		else if (dynamic_cast<TransactionNode*>(pTree)->getUnits() < units)
		{

			if (pTree->getpRight() == nullptr)
			{
				pTree->setpRight(new TransactionNode(name, units));
			}
			else
			{
				insert(pTree->getpRight(), units, name);
			}
		}
	}
}
void BST::inOrderTraversal(Node* pTree) {
	if (pTree != nullptr)
	{
		inOrderTraversal(pTree->getpLeft());
		dynamic_cast<TransactionNode*>(pTree)->printData();
		inOrderTraversal(pTree->getpRight());
	}
}
