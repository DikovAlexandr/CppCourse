#include "Item.hpp"

Item::Item(int id, std::string name, double price, double quantity) : id(id), name(name), price(price),
                                                                      quantity(quantity) {}

Item::~Item() = default;

std::string Item::getName() {
    return name;
}

double Item::getPrice() {
    return price;
}

double Item::getQuantity() {
    return quantity;
}

int Item::getId() {
    return id;
}

void Item::quantityIncrease(double q) {
    quantity += q;
}

void Item::quantityDecrease(double q) {
    if (quantity > q) quantity -= q;
    else quantity = 0;
}

void Item::setZeroQuantity() {
    quantity = 0;
}

std::ostream &operator<<(std::ostream &os, const Item &item) {
    os << "Vendor code: " << item.id << " | Name: " << item.name << " | Price: " << item.price << " | Quantity: "
       << item.quantity << std::endl;
    return os;
}

//std::string Item::getItem() {
//    std::string s = "Vendor code: " + std::to_string(id) + " Name: " + name + " Price: " +
//                    std::to_string(price) + " Quantity: " + std::to_string(quantity);
//    //std::cout << s << std::endl;
//    return s;
//}

