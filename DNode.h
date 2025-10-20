//DNode.h
#include "Song.h"

class DNode {
private:
    Song elem;
    DNode* prev;
    DNode* next;

    // Constructor increments activeNodes
    DNode(const Song& e, DNode* p = nullptr, DNode* n = nullptr);

public:
    static int activeNodes;  // Track number of active nodes
    ~DNode();

    friend class CircleDLinkedList; // Allow list access
};
