#pragma once

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;
using std::vector;
using std::string;

class Node
{

public:
	Node(const string& newData);
	virtual ~Node();

	//setters
	void setData(string& const newData);
	void setpLeft(Node* const newPtr);
	void setpRight(Node* const newPtr);

	//getters
	string getData() const;
	Node* getpLeft() const;
	Node* getpRight() const;

	virtual void printData() = 0;

protected:
	string mData;
	Node* mpLeft;
	Node* mpRight;
};

