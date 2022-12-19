#pragma once

#include <iostream>
#include <string>

class Item {
public:
    Item(int id, std::string name, double price, double quantity);

    std::string getName();

    double getPrice();

    double getQuantity();

    void quantityIncrease(double q);

    void quantityDecrease(double q);

    void setZeroQuantity();

    int getId();

    bool operator==(const Item &right) {
        if (right.id == this->id)
            return true;
        return false;
    }

    //std::string getItem();

    friend std::ostream &operator<<(std::ostream &os, const Item &item);

    ~Item();

protected:
    int id;
    std::string name;
    double price;
    double quantity;
};
