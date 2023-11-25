//
// Created by josel on 24/11/2023.
//

#ifndef LISTASDOBLES_BACKPACK_H
#define LISTASDOBLES_BACKPACK_H


#include <ostream>

class BackPack {
public:
    BackPack(const std::string &id, const std::string &name, const std::string &type) : id(id), name(name),
                                                                                        type(type) {}

    BackPack() {}

    const std::string &getId() const {
        return id;
    }

    void setId(const std::string &id) {
        BackPack::id = id;
    }

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        BackPack::name = name;
    }

    const std::string &getType() const {
        return type;
    }

    void setType(const std::string &type) {
        BackPack::type = type;
    }

    friend std::ostream &operator<<(std::ostream &os, const BackPack &pack) {
        os << "id: " << pack.id << " name: " << pack.name << " type: " << pack.type;
        return os;
    }

    virtual ~BackPack() {

    }

private:
    std::string id;
    std::string name;
    std::string type;
};


#endif //LISTASDOBLES_BACKPACK_H
