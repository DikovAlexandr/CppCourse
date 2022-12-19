#include "Milk.hpp"

Milk::Milk(int id, std::string name, double price, double quantity, double volume, double fatness) :
        Item(id, name, price, quantity), volume(volume), fatness(fatness) {};

Milk::~Milk() = default;

double Milk::getVolume() {
    return volume;
}

double Milk::getFatness() {
    return fatness;
}

//std::string Milk::getItem() {
//    std::string s = "Vendor code: " + std::to_string(id) + " Name: " + name + " Fatness: " + std::to_string(fatness) +
//                    " Volume: " + std::to_string(volume) + " Price: " + std::to_string(price) + " Quantity: " +
//                    std::to_string(quantity);
//    std::cout << s << std::endl;
//}