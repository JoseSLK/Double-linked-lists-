//
// Created by josel on 25/11/2023.
//

#ifndef LISTASDOBLES_BACKPACK_H
#define LISTASDOBLES_BACKPACK_H

#include <ostream>
#include "Type.h"
#include <iomanip>

class BackPack {
private:
    std::string id;
    std::string name;
    std::string price;
    Type type;
    std::string brand;
    std::string color;
    std::string description;

public:
    BackPack();

    BackPack(const std::string &id, const std::string &name, const std::string &price, Type type, const std::string &brand,
             const std::string &color, const std::string &description);

    const std::string &getId() const;

    void setId(const std::string &id);

    const std::string &getName() const;

    void setName(const std::string &name);

    Type getType() const;

    void setType(Type type);

    const std::string &getPrice() const;

    void setPrice(const std::string &price);

    const std::string &getBrand() const;

    void setBrand(const std::string &brand);

    const std::string &getColor() const;

    void setColor(const std::string &color);

    const std::string &getDescription() const;

    void setDescription(const std::string &description);

    friend std::ostream &operator<<(std::ostream &os, const BackPack &pack);

    virtual ~BackPack();
};


#endif //LISTASDOBLES_BACKPACK_H
