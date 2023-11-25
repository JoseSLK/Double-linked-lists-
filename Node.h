//
// Created by josel on 23/11/2023.
//

#ifndef LISTASDOBLES_NODE_H
#define LISTASDOBLES_NODE_H

#include <cstdlib>

template<class T> class LinkedDouble;
template<class T>

class Node {
    friend class LinkedDouble<T>;
private:
    T info;
    Node<T> *next;
    Node<T> *previous;
public:
    Node() {
        Node::next = NULL;
        Node::previous = NULL;
    }

    explicit Node(T info) : info(info) {
        Node::next = NULL;
        Node::previous = NULL;
    }

    virtual ~Node() {
        delete(next);
    }
};


#endif //LISTASDOBLES_NODE_H
