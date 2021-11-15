#include "Node.h"
Node::Node(const string& newData) {
	this->mData = newData;
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
}

Node::~Node() {
}

//setters
void Node::setData(string& const newData) {
	this->mData = newData;
}

void Node::setpLeft(Node* const newPtr) {
	this->mpLeft = newPtr;
}

void Node::setpRight(Node* const newPtr) {
	this->mpRight = newPtr;
}

//getters
string Node::getData() const {
	return this->mData;
}

Node* Node::getpLeft() const {
	return this->mpLeft;
}

Node* Node::getpRight() const {
	return this->mpRight;
}

