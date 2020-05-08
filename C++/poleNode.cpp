// Stuart Barclay 07/01/2019

#include "poleNode.h"

int poleNode::getValue()
{
    return this->value;
}

poleNode::poleNode()
{
    this->nextNode = nullptr;
    this->value = -1;
}

void poleNode::setValue(int value)
{
    this->value = value;
}