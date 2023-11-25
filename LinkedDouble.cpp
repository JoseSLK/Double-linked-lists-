//
// Created by josel on 23/11/2023.
//

#include "LinkedDouble.h"

template<class T>
LinkedDouble<T>::LinkedDouble() {
    head = NULL;
    last = NULL;
}

template<class T>
T LinkedDouble<T>::getLast() {
    return nullptr;
}

template<class T>
T LinkedDouble<T>::getFirst() {
    return nullptr;
}

template<class T>
T *LinkedDouble<T>::getObject(int) {
    return nullptr;
}

template<class T>
T *LinkedDouble<T>::deleteNode(Node<T> *) {
    return nullptr;
}

template<class T>
T *LinkedDouble<T>::findInfo(std::string) {
    return nullptr;
}

template<class T>
Node<T> *LinkedDouble<T>::findNode(std::string) {
    return nullptr;
}

template<class T>
void LinkedDouble<T>::addNodeSorted(T info) {

}

template<class T>
void LinkedDouble<T>::addNodeLast(T info) {
    Node<T> *newNode = new Node<T>(info);
    if(isEmpty()){
        head = newNode;
        last = newNode;
    }else {
        last->next = newNode;
        newNode->previous = last;
        last = newNode;
    }
}

template<class T>
void LinkedDouble<T>::addNodeFirst(T info) {

    Node<T> *newNode = new Node<T>(info);
    if(isEmpty()){
        head = newNode;
        last = newNode;
    }else {
        head->previous = newNode;
        newNode->next = head;
        head = newNode;
    }

}

template<class T>
bool LinkedDouble<T>::isEmpty() {
    return head == NULL && last == NULL;
}

template<class T>
std::vector<T> LinkedDouble<T>::getLinkedList(bool forward) {
    std::vector<T> out;
    Node<T> *aux = forward ? head: last;
    while (aux != NULL){
        out.push_back(aux->info);
        aux = forward ? aux->next : aux->previous;
    }

    return out;
}

template<class T>
LinkedDouble<T>::~LinkedDouble() {

}
#include "LinkedDouble.h"
