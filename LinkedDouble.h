//
// Created by josel on 23/11/2023.
//

#ifndef LISTASDOBLES_LINKEDDOUBLE_H
#define LISTASDOBLES_LINKEDDOUBLE_H

#include "Node.h"
#include <vector>
#include <string>

template <class T>

class LinkedDouble {
public:

    LinkedDouble();

    bool isEmpty();

    void addNodeFirst(T info);

    void addNodeLast(T info);

    void addNodeSorted(T info);

    Node<T>* findNode(std::string );

    T* findInfo(std::string );

    T *deleteNode(Node<T>*);

    T* getObject(int);

    T getFirst();

    T getLast();

    std::vector<T> getLinkedList(bool );

    virtual ~LinkedDouble();

private:

    Node<T> *head;
    Node<T> *last;

};




#endif //LISTASDOBLES_LINKEDDOUBLE_H
