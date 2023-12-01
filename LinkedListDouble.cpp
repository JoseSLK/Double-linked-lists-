//
// Created by josel on 23/11/2023.
//

#include "LinkedListDouble.h"

template<class T>
LinkedListDouble<T>::LinkedListDouble() {
    head = NULL;
    last = NULL;
}

template<class T>
T LinkedListDouble<T>::getLast() {
    return last->info;
}

template<class T>
T LinkedListDouble<T>::getFirst() {
    return head->info;
}

template<class T>
T *LinkedListDouble<T>::getObject(int position) {
    Node<T> *aux = head;
    for(int i = 1; (aux != NULL);i++){
        if(i == position){
            return &(aux->info);
        }
        aux = aux->next;
    }
    return NULL;
}

template<class T>
T *LinkedListDouble<T>::deleteNode(Node<T> *auxNode) {
    if (auxNode != NULL) {
        Node<T> *nextNode = auxNode->next;
        Node<T> *previousNode = auxNode->previous;

        if (nextNode == NULL) {
            last = previousNode;
            if (last != NULL) {
                last->next = nullptr;
            } else {
                head = nullptr;
            }
        } else {
            nextNode->previous = previousNode;
        }

        if (previousNode == NULL) {
            head = nextNode;
        } else {
            previousNode->next = nextNode;
        }

        T *deletedContent = &(auxNode->info);
        delete auxNode;

        return NULL;
    }
    return nullptr;
}


//Buscara el nodo que contenga esa informacion, pero cual informacion?, ya tengo busqueda por id, podria buscar la maleta por nombre
template<class T>
T *LinkedListDouble<T>::findInfo(const std::string &name) {

    if(name != ""){

        Node<T> *aux = head;
        while(aux != NULL){
            if(aux->info.getName() == name){
                return &(aux->info);
            }
            aux = aux->next;
        }

    }
    return NULL;
}

template<class T>
Node<T> *LinkedListDouble<T>::findNode(std::string id) {
    Node<T> *auxHead = head;
    Node<T> *auxLast = last;
    while(auxHead != NULL && auxLast != NULL){

        if(auxHead->info.getId().compare(id) == 0){
            return auxHead;
        }
        if(auxLast->info.getId().compare(id) == 0){
            return auxLast;
        }

        auxHead = auxHead->next;
        auxLast = auxLast->previous;
    }
    return NULL;
}

template<class T>
void LinkedListDouble<T>::addNodeSorted(T info) {
    Node<T> *node = new Node<T>(info);

    if (isEmpty()) {
        head = node;
        last = node;
    } else {
        Node<T> *auxHead = head;
        Node<T> *aux = nullptr;

        while (auxHead != nullptr && node->info.getId().compare(auxHead->info.getId()) > 0) {
            aux = auxHead;
            auxHead = auxHead->next;
        }

        if (aux == nullptr) {
            node->next = head;
            head->previous = node;
            head = node;
        } else {
            aux->next = node;
            node->previous = aux;

            if (auxHead == nullptr) {
                last = node;
            } else {
                node->next = auxHead;
                auxHead->previous = node;
            }
        }
    }
}


template<class T>
void LinkedListDouble<T>::addNodeLast(T info) {
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
void LinkedListDouble<T>::addNodeFirst(T info) {

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
bool LinkedListDouble<T>::isEmpty() {
    return head == NULL && last == NULL;
}

template<class T>
std::vector<T> LinkedListDouble<T>::getLinkedList(const bool &forward) {
    std::vector<T> out;
    Node<T> *aux;

    if (forward) {
        aux = head;
    } else {
        aux = last;
    }

    while (aux != NULL) {
        out.push_back(aux->info);

        if (forward) {
            aux = aux->next;
        } else {
            aux = aux->previous;
        }
    }

    return out;
}

//Despues
template<class T>
void LinkedListDouble<T>::addNodeAfterTo(Node<T> *node, T info) {
    Node<T> *newNode = new Node<T>(info);

    if (isEmpty()) {
        head = newNode;
        last = newNode;
        return;
    }

    Node<T> *aux = head;

    while (aux != NULL) {
        if (aux->next == NULL) {
            aux->next = newNode;
            newNode->previous = aux;
            last = newNode;
            return;
        } else if (aux == node) {
            newNode->next = aux->next;
            newNode->previous = aux;
            aux->next->previous = newNode;
            aux->next = newNode;
            return;
        }
        aux = aux->next;
    }
}


template<class T>
void LinkedListDouble<T>::addNodeBeforeTo(Node<T> *node, T info) {
    Node<T> *newNode = new Node<T>(info);
    Node<T> *aux = head;

    while (aux != NULL) {
        if (aux == node) {
            head = newNode;
            newNode->next = aux;
            return;
        } else if (aux->next == node) {
            Node<T> *nextC = aux->next;
            aux->next = newNode;
            newNode->previous = aux;
            newNode->next = nextC;
            if (nextC != NULL) {
                nextC->previous = newNode;
            }
            return;
        }
        aux = aux->next;
    }
}


template<class T>
int LinkedListDouble<T>::getSize() {
    Node<T> *aux = head;
    int size = 0;
    for (int i = 1; (aux != NULL) ; ++i) {
        size++;
        aux = aux->next;
    }
    return size;
}

template<class T>
void LinkedListDouble<T>::modifyNodeContent(const std::string &id, const std::string &name, const std::string &price, Type type, const std::string &brand,
                                            const std::string &color, const std::string &description) {
    Node<T> *aux = findNode(id);

    if(aux != NULL){
        aux->info.setName(name);
        aux->info.setPrice(price);
        aux->info.setType(type);
        aux->info.setBrand(brand);
        aux->info.setColor(color);
        aux->info.setDescription(description);
    }

}
template<class T>
LinkedListDouble<T>::~LinkedListDouble() {

}
#include "LinkedListDouble.h"
