//
// Created by josel on 23/11/2023.
//

#ifndef LISTASDOBLES_LINKEDLISTDOUBLE_H
#define LISTASDOBLES_LINKEDLISTDOUBLE_H

#include "Node.h"
#include "Type.h"
#include <vector>
#include <string>

template <class T>

class LinkedListDouble {
public:

    LinkedListDouble();

    bool isEmpty();

    void addNodeFirst(T info);

    void addNodeLast(T info);

    void addNodeAfterTo( Node<T> *node, T info);

    void addNodeBeforeTo( Node<T> *node, T info);

    void addNodeSorted(T info);

    Node<T>* findNode(std::string );

    T* findInfo(const std::string &name);

    T *deleteNode(Node<T>*);

    T* getObject(int);

    T getFirst();

    T getLast();

    int getSize();

    std::vector<T> getLinkedList(const bool &forward );

    void modifyNodeContent(const std::string &id, const std::string &name, const std::string &, Type type, const std::string &brand,
                           const std::string &color, const std::string &description);

    virtual ~LinkedListDouble();

private:

    Node<T> *head;
    Node<T> *last;

};



#endif //LISTASDOBLES_LINKEDLISTDOUBLE_H
