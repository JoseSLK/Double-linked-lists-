//
// Created by josel on 25/11/2023.
//

#include "BackPack.h"

BackPack::BackPack() {}

BackPack::BackPack(const std::string &id, const std::string &name, const std::string &price, Type type, const std::string &brand,
                   const std::string &color, const std::string &description) : id(id), name(name), price(price),
                                                                               type(type), brand(brand), color(color),
                                                                               description(description) {}

const std::string &BackPack::getName() const {
    return name;
}

void BackPack::setName(const std::string &name) {
    BackPack::name = name;
}

Type BackPack::getType() const {
    return type;
}

void BackPack::setType(Type type) {
    BackPack::type = type;
}

const std::string &BackPack::getBrand() const {
    return brand;
}

void BackPack::setBrand(const std::string &brand) {
    BackPack::brand = brand;
}

const std::string &BackPack::getColor() const {
    return color;
}

void BackPack::setColor(const std::string &color) {
    BackPack::color = color;
}

const std::string &BackPack::getDescription() const {
    return description;
}

void BackPack::setDescription(const std::string &description) {
    BackPack::description = description;
}

std::ostream &operator<<(std::ostream &os, const BackPack &pack) {
    os << std::setw(6) << pack.getId() << " | "
       << std::setw(8) << pack.getName() << " | "
       << std::setw(8) << pack.getPrice() << " | "
       << std::setw(5) << pack.getType() << " | "
       << std::setw(8) << pack.getBrand() << " | "
       << std::setw(8) << pack.getColor() << " | "
       << pack.getDescription();
    return os;
}

const std::string &BackPack::getId() const {
    return id;
}

void BackPack::setId(const std::string &id) {
    BackPack::id = id;
}

const std::string &BackPack::getPrice() const {
    return price;
}

void BackPack::setPrice(const std::string &price) {
    BackPack::price = price;
}

BackPack::~BackPack() {

}




