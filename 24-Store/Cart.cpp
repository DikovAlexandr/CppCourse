#include <iostream>
#include <algorithm>
#include "Cart.hpp"

Cart::Cart() = default;

void Cart::addToCart(Item &obj, double quantity) {
    cartVector.push_back(obj);
    cartVector.back().setZeroQuantity();
    cartVector.back().quantityIncrease(quantity);
    totalPrice += obj.getPrice();
}

//void Cart::removeFromCart(Item &obj) {
//    std::vector<Item>::iterator it;
//    it = std::find(cartVector.begin(), cartVector.end(), obj);
//    cartVector.erase(it);
//    totalPrice -= obj.getPrice();
//}

void Cart::removeFromCart(int id) {
    for (int i = 0; i < cartVector.size(); ++i) {
        if (cartVector[i].getId() == id) {
            cartVector.erase(cartVector.begin() + i - 1);
            totalPrice -= cartVector[i].getPrice();
            break;
        }
    }
}

void Cart::printCart() {
    if (cartVector.empty()) std::cout << "Cart is empty" << std::endl;
    else {
        for (auto &i: cartVector) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
}

Cart::~Cart() = default;