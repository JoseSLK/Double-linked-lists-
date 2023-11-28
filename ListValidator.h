//
// Created by josel on 25/11/2023.
//

#ifndef LISTASDOBLES_LISTVALIDATOR_H
#define LISTASDOBLES_LISTVALIDATOR_H

#include "LinkedListDouble.cpp"
#include "AddPosition.h"
#include "BackPack.h"


class ListValidator {
private:
    LinkedListDouble<BackPack> *linkedList;
public:
    ListValidator();

    bool validateNodeExistence(const std::string &id);

    AddPosition verifyPosition(const int &position);

    Type verifyType(const int &type);

    bool addNewProduct(const AddPosition &possition, const std::string &id, const std::string &name, const double &price, const Type &type, const std::string &brand,
                       const std::string &color, const std::string &description);

    bool isDigit(const std::string &id);

    bool checkStringContent(const std::string &str);

    virtual ~ListValidator();

};




#endif //LISTASDOBLES_LISTVALIDATOR_H
