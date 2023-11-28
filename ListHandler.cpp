//
// Created by josel on 25/11/2023.
//
#include "ListHandler.h"

using namespace std;

void ListHandler::addItem() {
    bool question = false;
    Type typeEnum = INVALIDTYPE;
    AddPosition possitionEnum = INVALIDPOSITION;
    int positionAux = -1, typeAux = -1, idAux = -1;
    std::string id, name, brand, color, description, position, type, price;
    double priceAux = -1;

    cout<<"Haz seleccionado la opcion adicionar un producto"<<endl;

    while(idAux == -1){
        cout<<"Digita el ID del producto(El Id debe ser unico de tipo numerico): ";
        getline(cin, id);
        if(listValidator->validateNodeExistence(id)){
            cout<<"Ya existe un producto con este id"<<endl;
        }else{
            idAux = listValidator->isDigit(id);
        }

    }

    while(!question){
        cout<<"\nDigita un nombre(Valido) para el producto: ";
        getline(cin, name);
        question = listValidator->checkStringContent(name);
    }
    question = false;

    while (!question){
        cout<<"\nDigita la marca(Valida) del producto: ";
        getline(cin, brand);
        question = listValidator->checkStringContent(brand);
    }
    question = false;

    while(!question){
        cout<<"Digita el color del producto: ";
        getline(cin, color);
        question = listValidator->checkStringContent(color);
    }
    question = false;

    while(!question){
        cout<<"Digita la descripcion del producto: ";
        getline(cin, description);
        question = listValidator->checkStringContent(description);
    }

    while(priceAux == -1){
        cout<<"Digita el precio del producto: ";
        getline(cin, price);
        priceAux = listValidator->isDigit(price);
    }

    cout<<"¿\nQue tipo de mochila vas a incluir\n?"
    "1-Bolso de mano\n2-Maletin\n3-Riñonera\n"<<endl;

    while(typeAux == -1 && typeEnum == INVALIDTYPE){
        cout<<"Digita una opcion valida: ";
        getline(cin, type);
        typeAux = listValidator->isDigit(type);
        typeEnum = listValidator->verifyType(typeAux);
    }

    cout<<"¿En que posicion quieres guardarlo?\n"<<
        "1-Primero\n2-Ultimo\n3-Despues de un producto en especifico\n4-Antes de un producto en especifico\n5-Ordenado por id\n"<<endl;

    while(positionAux == -1 && possitionEnum == INVALIDPOSITION){
        cout<<"Digita una opcion valida: ";
        getline(cin, position);
        positionAux = listValidator->isDigit(position);
        possitionEnum = listValidator->verifyPosition(positionAux);
    }

    listValidator->addNewProduct(possitionEnum, id, name, priceAux, typeEnum, brand, color, description);
}

//template<class T>
//ListHandler<T>::~ListHandler() {
//
//}



