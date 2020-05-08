// Stuart Barclay 07/01/2019
#ifndef poleNode_h
#define poleNode_h

struct poleNode
{
private:
    int value;

public:
    poleNode();
    // ~poleNode();
    poleNode *nextNode;
    int getValue();
    void setValue(int value);
};

#endif