#include "Yogurt.hpp"

Yogurt::Yogurt(int id, std::string name, double price, double quantity, double volume, double fatness, bool bio,
               std::string taste, std::string brand) :
        Milk(id, name, price, quantity, volume, fatness), bio(bio), taste(taste), brand(brand) {}

Yogurt::~Yogurt() = default;

std::string Yogurt::getBio() {
    if (bio == 1)
        return "bio";
    else return "nonbio";
}

std::string Yogurt::getBrand() {
    return brand;
}

std::string Yogurt::getTaste() {
    return taste;
}

//std::string Yogurt::getItem() {
//    std::string s = "Vendor code: " + std::to_string(id) + " Name: " + name + " Fatness: " + std::to_string(fatness) +
//                    " Volume: " + std::to_string(volume) + " Brand: " + brand + " Taste: " + taste + " Bio: " +
//                    (bio ? "bio" : "nonbio") + " Price: " + std::to_string(price) + " Quantity: " +
//                    std::to_string(quantity);
//    std::cout << s << std::endl;
//}