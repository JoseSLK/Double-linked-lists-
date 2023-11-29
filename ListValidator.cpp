//
// Created by josel on 25/11/2023.
//
#include <stdexcept>
#include "ListValidator.h"


ListValidator::ListValidator(){
    linkedList = new LinkedListDouble<BackPack>();
    linkedList->addNodeFirst(BackPack("123", "hjkasd", "hduisod", HANDBAG, ",asf", "jiofsaf", "hjfhsaduif"));
    linkedList->addNodeFirst(BackPack("1234", "hjkasd", "hduisod", HANDBAG, ",asf", "jiofsaf", "hjfhsaduif"));
    linkedList->addNodeFirst(BackPack("12345", "hjkasd", "hduisod", HANDBAG, ",asf", "jiofsaf", "hjfhsaduif"));
    linkedList->addNodeFirst(BackPack("123456", "hjkasd", "hduisod", HANDBAG, ",asf", "jiofsaf", "hjfhsaduif"));
}

bool ListValidator::isDigit(const std::string &id) {
    try {
        size_t pos;

        std::stod(id, &pos);

        return pos == id.length();

    }catch (const std::invalid_argument& ex){
        return false;
    } catch (const std::out_of_range& ex){
        return false;
    }
    return true;
}


bool ListValidator::validateNodeExistence(const std::string &id) {
    if(linkedList->findNode(id) != NULL){
        return true;
    }
    return false;
}


bool ListValidator::checkStringContent(const std::string &str) {
    if(str.find_first_not_of(' ') == std::string::npos || std::isspace(str.front())){
        return false;
    }
    return true;
}



Type ListValidator::verifyType(const int &type) {

    Type type1 = INVALIDTYPE;
    if(type == 1){
        type1 = HANDBAG;
    } else if (type == 2){
        type1 = SUITCASE;
    }else if (type == 3){
        type1 = FANNY_PACK;
    }
    return type1;
}


AddPosition ListValidator::verifyPosition(const int &position) {

    AddPosition position1 = INVALIDPOSITION;

    if (position == 1){
        position1 = FIRST;
    }else if(position == 2){
        position1 = LAST;
    }else if(position == 3){
        position1 = AFTER;
    }else if(position == 4){
        position1 = BEFORE;
    }else if(position == 5){
        position1 = SORTED;
    }

    return position1;
}


bool ListValidator::addNewProduct(const AddPosition &possition, const std::string &id, const std::string &name,
                                     const std::string &price, const Type &type, const std::string &brand,
                                     const std::string &color, const std::string &description) {
    switch (possition) {
        case FIRST:
            linkedList->addNodeFirst(BackPack(id, name, price, type, brand, color, description));
            break;
        case LAST:
            linkedList->addNodeLast(BackPack(id, name, price, type, brand, color, description));
            break;
        case AFTER:
            //linkedList->addNodeAfterTo(BackPack(id, name, price, type, brand, color, description));
            break;
        case BEFORE:
           // linkedList->addNodeBeforeTo(BackPack(id, name, price, type, brand, color, description));
            break;
        case SORTED:
            linkedList->addNodeSorted(BackPack(id, name, price, type, brand, color, description));
            break;
    }

    return false;
}

bool ListValidator::addNewProduct(const AddPosition &possition, const std::string &id, const std::string &name,
                                  const std::string &price, const Type &type, const std::string &brand,
                                  const std::string &color, const std::string &description, const std::string &idPosition) {
    switch (possition) {
        case AFTER:
            linkedList->addNodeAfterTo(linkedList->findNode(idPosition), BackPack(id, name, price, type, brand, color, description));
            break;
        case BEFORE:
            linkedList->addNodeBeforeTo(linkedList->findNode(idPosition), BackPack(id, name, price, type, brand, color, description));
            break;
    }

    return false;
}


bool ListValidator::deleteProduct(const std::string &id) {
    Node<BackPack> *deleteBackPack = linkedList->findNode(id);
    if(linkedList->deleteNode(deleteBackPack) == NULL){
     return true;
    }
    return false;
}

std::vector<BackPack> ListValidator::readItems(bool forward) {
    return linkedList->getLinkedList(forward);
}

bool ListValidator::editItem(const std::string &id, const std::string &name, const std::string &price, Type type,
                             const std::string &brand, const std::string &color, const std::string &description) {
    linkedList->modifyNodeContent(id, name, price, type, brand, color, description);
    return true;
}


ListValidator::~ListValidator() {

}





