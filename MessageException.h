//
// Created by josel on 30/11/2023.
//

#ifndef LISTASDOBLES_MESSAGEEXCEPTION_H
#define LISTASDOBLES_MESSAGEEXCEPTION_H

#include <exception>
#include <string>

class MessageException : public std::exception {
private:
    std::string message = "Error: ";
public:
    MessageException(const std::string &message = ""){
        this->message += message;
    }

    const char *what() {
        return this->message.c_str();
    }

};


#endif //LISTASDOBLES_MESSAGEEXCEPTION_H
