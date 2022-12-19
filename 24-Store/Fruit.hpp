#pragma once

#include "Item.hpp"
#include <iostream>
#include <string>

class Fruit : public Item {
public:
    Fruit(int id, std::string name, double price, double quantity, std::string country);

    std::string getCountry();

    //std::string getItem();

    ~Fruit();

protected:
    std::string country;
};

