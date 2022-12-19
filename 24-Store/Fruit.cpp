#include <iostream>
#include "Fruit.hpp"

Fruit::Fruit(int id, std::string name, double price, double quantity, std::string country) :
        Item(id, name, price, quantity), country(country) {};

Fruit::~Fruit() = default;

std::string Fruit::getCountry() {
    return country;
}

//std::string Fruit::getItem() {
//    std::string s = "Vendor code: " + std::to_string(id) + " Name: " + name + " Country: " + country + " Price: " +
//                    std::to_string(price) + " Quantity: " + std::to_string(quantity);
//    //std::cout << s << std::endl;
//    return s;
//}