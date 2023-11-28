//
// Created by josel on 25/11/2023.
//
#include <stdexcept>
#include "ListValidator.h"


ListValidator::ListValidator(){
    linkedList = new LinkedListDouble<BackPack>();};

bool ListValidator::isDigit(const std::string &id) {
    try {
        return std::stod(id) == 0;
    }catch (const std::invalid_argument& ex){
        return false;
    } catch (const std::out_of_range& ex){
        return false;
    }
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
                                     const double &price, const Type &type, const std::string &brand,
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


ListValidator::~ListValidator() {

}
