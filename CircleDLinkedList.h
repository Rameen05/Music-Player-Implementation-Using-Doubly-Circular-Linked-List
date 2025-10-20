//CircleDLinkedList.h

#include "DNode.h"
#include <iostream>

class CircleDLinkedList {
private:
    DNode* cursor;  // current song
    int n;          // number of songs

public:
    CircleDLinkedList();
    ~CircleDLinkedList();

    bool empty() const;
    int size() const;

    void add(const Song&);  // adds after cursor
    void remove();          // removes current song
    void advance();
    void retreat();
    Song getCurrentSong() const;

    void print(bool forward = true) const;
};
