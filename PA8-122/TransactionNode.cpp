#include "TransactionNode.h"

TransactionNode::~TransactionNode() {
}
void TransactionNode::setUnits(const int newUnits) {
	this->mUnits = newUnits;
}
int TransactionNode::getUnits() const {
	return this->mUnits;
}
void TransactionNode::printData() {
	cout << "Product: " << this->getData() << " Amount: " << this->getUnits() << endl;
}
