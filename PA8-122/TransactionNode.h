#pragma once
#include "Node.h"

class TransactionNode :
    public Node
{
public:
    TransactionNode(const string& newData = "", const int newUnits = 0) : Node(newData) {
        this->mUnits = newUnits;
    }
    ~TransactionNode();

    //setters
    void setUnits(const int newUnits);
   
    
    //getters
    int getUnits() const;

    void printData();

private:
    int mUnits;
};

