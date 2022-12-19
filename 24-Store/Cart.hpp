#pragma once

#include "Item.hpp"
#include <vector>

class Cart {
public:
    Cart();

    std::vector<Item> cartVector;

    double totalPrice = 0;

    void addToCart(Item &obj, double quantity);

    void removeFromCart(int id);

    void printCart();

    ~Cart();
};
