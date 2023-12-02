//
// Created by josel on 25/11/2023.
//
#include "ListHandler.h"

using namespace std;

void ListHandler::addItem() {
    bool question = false;
    Type typeEnum = INVALIDTYPE;
    AddPosition possitionEnum = INVALIDPOSITION;
    bool positionAux = false, typeAux = false, idAux = false;
    std::string id, name, brand, color, description, position, type, price, idPosition;
    bool priceAux = false;
    int opt;

    cout<<"/////////////////////////////////////////////////\n"
          "Haz seleccionado la opcion adicionar un producto\n"
          "/////////////////////////////////////////////////\n";

    while ( !idAux ){
        cout<<"Digita el ID del producto(El Id debe ser unico de tipo numerico): ";
        getline(cin, id);
        try {
            if(listValidator->validateNodeExistence(id)){
                throw MessageException("Ya existe un producto con este id");
            }else{
                idAux = listValidator->isDigit(id);
            }
        } catch (MessageException &e ){
            cout << e.what() << endl;
        }
    }

    cout<<"¿\nQue tipo de mochila vas a incluir\n?"
          "1-Bolso de mano\n2-Maletin\n3-Riñonera\n"<<endl;

    while(!typeAux && typeEnum == INVALIDTYPE){
        cout<<"Digita una opcion valida: ";
        getline(cin, type);
        try {
            if(type != "1" && type != "2" && type != "3"){
                throw MessageException("Opcion invalida :(");
            }else{
                typeAux = listValidator->isDigit(type);
                typeEnum = listValidator->verifyType(typeAux);
            }
        } catch (MessageException &e ) {
            cout << e.what() << endl;
        }

    }

    while(!question){
        cout<<"\nDigita un nombre(Valido) para el producto: ";
        getline(cin, name);
        question = listValidator->checkStringContent(name);
        try {
            if(!question){
                throw MessageException("Recuerda no dejar espacios en blanco :)");
            }
        } catch (MessageException &e ) {
            cout << e.what() << endl;
        }

    }
    question = false;

    while (!question){
        cout<<"\nDigita la marca(Valida) del producto: ";
        getline(cin, brand);
        question = listValidator->checkStringContent(brand);
        try {
            if(!question){
                throw MessageException("Recuerda no dejar espacios en blanco :)");
            }
        } catch (MessageException &e ) {
            cout << e.what() << endl;
        }

    }
    question = false;

    while(!question){
        cout<<"\nDigita el color del producto: ";
        getline(cin, color);
        question = listValidator->checkStringContent(color);
        try {
            if(!question){
                throw MessageException("Recuerda no dejar espacios en blanco :)");
            }
        } catch (MessageException &e ) {
            cout << e.what() << endl;
        }

    }
    question = false;

    while(!question){
        cout<<"\nDigita la descripcion del producto: ";
        getline(cin, description);
        question = listValidator->checkStringContent(description);
        try {
            if(!question){
                throw MessageException("Recuerda no dejar espacios en blanco :)");
            }
        } catch (MessageException &e ) {
            cout << e.what() << endl;
        }

    }

    while(!priceAux){
        cout<<"\nDigita el precio del producto: ";
        getline(cin, price);
        priceAux = listValidator->isDigit(price);
        try {
            if(!priceAux){
                throw MessageException("Recuerda digitar solo numeros y no dejar la casilla vacia");
            }
        } catch (MessageException &e ) {
            cout << e.what() << endl;
        }

    }

    cout<<"¿En que posicion quieres guardarlo?\n"<<
        "1-Primero\n2-Ultimo\n3-Despues de un producto en especifico\n4-Antes de un producto en especifico\n5-Ordenado por id\n"<<endl;

    while (!positionAux && possitionEnum == INVALIDPOSITION) {
        int positionValue;

        cout << "Digita una opcion valida: ";
        getline(cin, position);
        if(listValidator->isDigit(position)){
            positionValue = std::stoi(position);
            if(positionValue <=5 && positionValue >=1){
                positionAux = true;
            }
        }

        if ( positionAux ) {
            possitionEnum = listValidator->verifyPosition(positionValue);

            if (possitionEnum == AFTER || possitionEnum == BEFORE) {
                cout << "Digita el id del producto que quieres que ";
                cout << (possitionEnum == AFTER ? "anteponga" : "le siga a") << " el nuevo" << endl;

                while (!listValidator->isDigit(idPosition) && !listValidator->validateNodeExistence(idPosition)) {
                    cout << "Digita: ";
                    getline(cin, idPosition);
                    try {
                        if (!listValidator->isDigit(idPosition) && !listValidator->validateNodeExistence(idPosition)) {
                            throw MessageException("Id invalido");
                        }
                    } catch (MessageException &e) {
                        cout << e.what() << endl;
                    }
                }

                listValidator->addNewProduct(possitionEnum, id, name, price, typeEnum, brand, color, description, idPosition);
            } else {
                listValidator->addNewProduct(possitionEnum, id, name, price, typeEnum, brand, color, description);
            }
        }
    }
}

void ListHandler::deleteItem() {

    string id;
    bool idAux = false;

    while(!idAux && !listValidator->validateNodeExistence(id)){

        cout<<"Digita el ID del producto a eliminar(El Id debe pertenecer a un producto existente): ";
        getline(cin, id);
        try {
            if(!listValidator->validateNodeExistence(id)){
                throw MessageException("NO existe un producto con este id");
            }else{
                idAux = listValidator->isDigit(id);
            }
        } catch (MessageException &e) {
            cout << e.what() << endl;
        }

    }

    if(listValidator->deleteProduct(id)){
        cout<<"Producto borrado satisfactoriamente";
    }else{
        throw MessageException("Hay un problema con la eliminacion, intentalo una vez mas");
    }

}

void ListHandler::readItems() {
    string opt;
    std::vector<BackPack> items;
    cout<<"¿Quieres mostrar en orden?\n"
          "1-Ascendente\n"
          "2-Descendente\n"<<endl;

    while (opt != "1" && opt != "2"){
        cout<<"Digita: ";
        getline(cin, opt);
        items = (opt == "1" ? listValidator->readItems(true) : listValidator->readItems(false));
    }
    cout << "A continucion una lista de los productos registrados: "<<endl;
    cout<< "  id   |  Nombre  |  Precio  | Tipo  |  Marca   |  Color   |   Descripcion\n";
    for(BackPack backPack: items){
        cout<<backPack<<endl;
    }
}

void ListHandler::editItem() {
    bool question = false, idAux = false;
    Type typeEnum = INVALIDTYPE;
    bool typeAux = false;
    std::string id, name, brand, color, description, position, type, price, idPosition;
    bool priceAux = false;

    while(!idAux){
        cout << "Digita el ID del producto que quieres editar: ";
        getline(cin, id);
        if(listValidator->validateNodeExistence(id)){
            idAux = listValidator->isDigit(id);
        }
        try {
            if( !idAux ) {
                throw MessageException("Recuerda que el id solo debe contener numeros");
            }
        } catch (MessageException &e) {
            cout << e.what() << endl;
        }

    }

    cout << "Llena las siguiente informacion(Esta reemplazara la antigua): "<< endl;

    cout << "¿\nQue tipo de mochila vas a incluir\n?"
          "1-Bolso de mano\n2-Maletin\n3-Riñonera\n" << endl;

    while(!typeAux && typeEnum == INVALIDTYPE){
        cout << "Digita una opcion valida: ";
        getline(cin, type);
        typeAux = listValidator->isDigit(type);
        typeEnum = listValidator->verifyType(typeAux);
    }

    while(!question){
        cout <<"\nDigita un nombre(Valido) para el producto: ";
        getline(cin, name);
        question = listValidator->checkStringContent(name);
    }
    question = false;

    while (!question){
        cout << "\nDigita la marca(Valida) del producto: ";
        getline(cin, brand);
        question = listValidator->checkStringContent(brand);
    }
    question = false;

    while(!question){
        cout << "\nDigita el color del producto: ";
        getline(cin, color);
        question = listValidator->checkStringContent(color);
    }
    question = false;

    while(!question){
        cout << "\nDigita la descripcion del producto: ";
        getline(cin, description);
        question = listValidator->checkStringContent(description);
        try {
            if( !question ) {
                throw MessageException("La descripcion no puede estar vacia");
            }
        } catch (MessageException &e) {
            cout << e.what() << endl;
        }

    }

    while(!priceAux){
        cout << "\nDigita el precio del producto: ";
        getline(cin, price);
        priceAux = listValidator->isDigit(price);

        try {
            if( !priceAux ) {
                throw MessageException("Recuerda digitar unicamente numeros");
            }
        } catch (MessageException &e ) {
            cout << e.what() << endl;
        }

    }

    if(listValidator->editItem(id, name, price, typeEnum, brand, color, description)){
        cout << "Objeto actualizado :)" << endl;
    }
}

void ListHandler::mainMenu() {

    string opt = "";

    cout << "!Hola¡ Bienvenido a Maletas Don Libardo" << endl;
    cout << "Este es un pequeño aplicativo de registro de productos, en este caso Mochilas de distintos tipos :)\n";

    while (opt != "x"){
        cout << "=======================================\n"
                "Ahora mismo contamos con las siguientes opciones: \n"
                "1- Agregar un producto(Mochila)\n"
                "2- Editar un producto\n"
                "3- Eliminar un producto\n"
                "4- Mostrar todos los productos\n"
                "x- Salir\n"
                "Digita: ";
        getline(cin, opt);

        try {
            if (opt == "1") {
                addItem();
            }else if(opt == "2"){
                editItem();
            }else if(opt == "3"){
                deleteItem();
            }else if (opt == "4"){
                readItems();
            }else{
                throw MessageException("Digita una opcion valida");
            }
        } catch (MessageException &e){
            cout << e.what() << endl;
        }

    }

}





