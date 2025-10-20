//DNode.cpp

#include "DNode.h"

// Initialize static variable
int DNode::activeNodes = 0;

// Constructor
DNode::DNode(const Song& e, DNode* p, DNode* n)
    : elem(e), prev(p), next(n) {   // correct initializer list syntax
    activeNodes++;
}

// Destructor
DNode::~DNode() {
    activeNodes--;
}
