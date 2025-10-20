//CircleDLinkedList.cpp

#include "CircleDLinkedList.h"

CircleDLinkedList::CircleDLinkedList() : cursor(nullptr), n(0) {}

CircleDLinkedList::~CircleDLinkedList() {
    while (!empty()) {
        remove();
    }
}

bool CircleDLinkedList::empty() const {
    return cursor == nullptr;
}

int CircleDLinkedList::size() const {
    return n;
}

void CircleDLinkedList::add(const Song& song) {
    DNode* newNode = new DNode(song);
    if (empty()) {
        newNode->next = newNode;
        newNode->prev = newNode;
        cursor = newNode;
    } else {
        DNode* nextNode = cursor->next;
        cursor->next = newNode;
        newNode->prev = cursor;
        newNode->next = nextNode;
        nextNode->prev = newNode;
        cursor = newNode; // update cursor to new song
    }
    n++;
}

void CircleDLinkedList::remove() {
    if (empty()) return;

    DNode* old = cursor;
    if (old->next == old) {
        cursor = nullptr;
    } else {
        old->prev->next = old->next;
        old->next->prev = old->prev;
        cursor = old->next;
    }
    delete old;
    n--;
}

void CircleDLinkedList::advance() {
    if (!empty())
        cursor = cursor->next;
}

void CircleDLinkedList::retreat() {
    if (!empty())
        cursor = cursor->prev;
}

Song CircleDLinkedList::getCurrentSong() const {
    if (empty()) throw std::runtime_error("Playlist is empty.");
    return cursor->elem;
}

void CircleDLinkedList::print(bool forward) const {
    if (empty()) {
        std::cout << "Playlist is empty.\n";
        return;
    }

    DNode* start = cursor;
    DNode* temp = cursor;

    do {
        std::cout << temp->elem << " ";
        temp = forward ? temp->next : temp->prev;
    } while (temp != start);

    std::cout << std::endl;
}
