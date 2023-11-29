//
// Created by josel on 25/11/2023.
//

#ifndef LISTASDOBLES_LISTHANDLER_H
#define LISTASDOBLES_LISTHANDLER_H

#include "ListValidator.h"
#include "BackPack.h"
#include "iostream"

class ListHandler {
private:
    ListValidator *listValidator;
public:
    ListHandler() {
        listValidator = new ListValidator();
    }

    void mainMenu();

    void addItem();

    void deleteItem();

    void editItem();

    void readItems();


    virtual ~ListHandler(){};
};




#endif //LISTASDOBLES_LISTHANDLER_H
