//
// Created by josel on 23/11/2023.
//

#ifndef LISTASDOBLES_LINKEDDOUBLE_H
#define LISTASDOBLES_LINKEDDOUBLE_H

#include "Node.h"
#include "Type.h"
#include <vector>
#include <string>

template <class T>

class LinkedDouble {
public:

    LinkedDouble();

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

    std::vector<T> getLinkedList(bool );

    void modifyNodeContent(const std::string &id, const std::string &name, double price, Type type, const std::string &brand,
                           const std::string &color, const std::string &description);

    virtual ~LinkedDouble();

private:

    Node<T> *head;
    Node<T> *last;

};



#endif //LISTASDOBLES_LINKEDDOUBLE_H
