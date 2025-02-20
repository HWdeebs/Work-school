#ifndef ITEM_H
#define ITEM_H

#include <string>

// Base class Item
class Item {
private:
    std::string name;
    double price;

public:
    Item(const std::string& n, double p);    // Constructor


    virtual std::string getName() const;            // Getter and Setter for name
    virtual void setName(const std::string& n);


    virtual double getPrice() const;                   // Getter and Setter for price
    virtual void setPrice(double p);


    virtual ~Item();  // Virtual destructor 
    
};

// Derived class Fruit which inherits from Item
class Fruit : public Item {
private:
    std::string color;

public:
    Fruit(const std::string& name, double price, const std::string& color); // Constructor

  
    std::string getColor() const;    // Getter and Setter for color
    void setColor(const std::string& c);

};

#endif // ITEM_H