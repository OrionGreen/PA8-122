#include "DataAnalysis.h"

DataAnalysis::DataAnalysis() {
	this->mCsvStream.open("data.csv", std::ios::in);
}
DataAnalysis::~DataAnalysis() {
	this->mCsvStream.close();
}

void DataAnalysis::parser(int& amount, string& item, string& BorS) {
	string line = "";
	getline(this->mCsvStream, line,',');
	amount = atoi(line.c_str());
	getline(this->mCsvStream, line, ',');
	item = line;
	getline(this->mCsvStream, line, '\n');
	BorS = line;

}

void DataAnalysis::buildTrees() {
	string garbage;
	getline(this->mCsvStream, garbage);
	while (!this->mCsvStream.eof()) {
		int amount = 0;
		string item = "";
		string BorS = ";";
		parser(amount, item, BorS);
		insertion(amount, item, BorS);
	}
}

void DataAnalysis::insertion(int& amount, string& item, string& BorS){
	if (BorS == "Sold") {
		this->mTreeSold.insert(amount, item);
	}
	else {
		this->mTreePurchased.insert(amount, item);
	}
}

void DataAnalysis::printTrees() {
	TransactionNode smallestBought;
	TransactionNode biggestBought;
	TransactionNode smallestSold;
	TransactionNode biggestSold;
	smallestBought = mTreePurchased.findSmallest();
	biggestBought = mTreePurchased.findLargest();
	smallestSold = mTreeSold.findSmallest();
	biggestSold = mTreeSold.findLargest();

	cout << "Purchases Tree" << endl;
	mTreePurchased.inOrderTraversal();

	cout << "Sales Tree" << endl;
	mTreeSold.inOrderTraversal();
	cout << endl;

	cout << "Largest Amount Bought" << endl;
	biggestBought.printData();
	cout << "Smallest Amount Bought" << endl;
	smallestBought.printData();
	cout << "Largest Amount Sold" << endl;
	biggestSold.printData();
	cout << "Smallest Amount Sold" << endl;
	smallestSold.printData();
}

void DataAnalysis::runAnalysis() {
	buildTrees();
	printTrees();
}
