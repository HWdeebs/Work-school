#include "classList.h"
#include <iostream>

// Item class constructor
Item::Item(const std::string& n, double p) : name(n), price(p) {}

// Getter and Setter for name
std::string Item::getName() const {
    return name;
}

void Item::setName(const std::string& n) { // set name of an Item
    name = n;
}


double Item::getPrice() const { // Getter and Setter for price
    return price;
}

void Item::setPrice(double p) {
    price = p;

    
}


Item::~Item() {}    // Virtual destructor

// Fruit class constructor
Fruit::Fruit(const std::string& name, double price, const std::string& color)
    : Item(name, price), color(color) {}

// Getter and Setter for color
std::string Fruit::getColor() const {
    return color;
}

void Fruit::setColor(const std::string& scolor) {
    color = scolor;
}
