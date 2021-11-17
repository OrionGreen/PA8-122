#pragma once
#include "BST.h"
class DataAnalysis
{
public:
	DataAnalysis();
	~DataAnalysis();

	void runAnalysis();

private:
	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCsvStream;
	void buildTrees();
	void insertion(int& amount, string& item, string& BorS);
	void parser(int& amount, string& item, string& BorS);
	void printTrees();
};

