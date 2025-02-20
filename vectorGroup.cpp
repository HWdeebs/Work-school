#include <iostream>
#include "classList.h"  // Include the header file
#include <memory>
#include <vector>

int main() {
 
    Item broom("broom", 6.99);      // Creating an Item object
    std::cout << "Item Name: " << broom.getName() << ", Price: $" << broom.getPrice() << std::endl;  // Using getter methods to print out initial values
      
    broom.setName("swiffer");   // Using setter methods to modify values
    broom.setPrice(10.99);

      
    std::cout << "Updated Item Name: " << broom.getName() << ", Price: $" << broom.getPrice() << std::endl; // Using getter methods again to print out updated values
    broom.setName("broom"); //change name of broom back for readablity
    std::cout << "Item Name is: " << broom.getName() << std::endl;

    Fruit apple("apple", 0.99, "red"); // Creating a Fruit object

    std::cout << "Fruit Name: " << apple.getName() << ", Price: $" << apple.getPrice() << ", Color: " << apple.getColor() << std::endl;     // Using getter methods to print out fruit details
    apple.setColor("Green");     // Using setter method to change fruit color

        
    std::cout << "Updated Fruit Color: " << apple.getColor() << std::endl; // Using getter method to check updated color

    std::vector<std::unique_ptr<Item>> items; // Create a vector w/ smart pointer to hold items/fruits
    items.push_back(std::unique_ptr<Item>(new Item(broom))); //add item
    items.push_back(std::unique_ptr<Fruit>(new Fruit(apple)));//add fruit
    items.push_back(std::unique_ptr<Fruit>(new Fruit("Orange", 4.99, "orange"))); //add fruit
    items.push_back(std::unique_ptr<Item>(new Item("Cleaner", 2.99))); // add item

    for (size_t i = 0; i < items.size(); i++) { // iterate vector w/ i
        std::cout << "Item Name: " << items[i]->getName() << ", Item Price: $" << items[i]->getPrice() << std::endl; 
    }

    items.pop_back(); //pop last element
    std::cout << std::endl;
    std::cout << std::endl;

    for (size_t i = 0; i < items.size(); i++) { // iterate vector w/ i again showing change after pop
        std::cout << "Item Name: " << items[i]->getName() << ", Item Price: $" << items[i]->getPrice() << std::endl; 
    }
    
    double totalPrice = 0.0;
    for (const auto& item : items) { // find the total cost of singular items
        totalPrice += item->getPrice();
    }
    std::cout << "Total price of all the items is: $" << totalPrice << std::endl;
    return 0;
}
