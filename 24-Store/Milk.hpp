#pragma once

#include "Item.hpp"

class Milk : public Item {
public:
    Milk(int id, std::string name, double price, double quantity, double volume, double fatness);

    double getVolume();

    double getFatness();

    friend std::ostream &operator<<(std::ostream &os, const Milk &milk) {
        os << milk.id << " " << milk.name << " " << milk.fatness << " " << milk.volume << " " << milk.price << " "
           << milk.quantity;
        return os;
    }

    //std::string getItem() override;

    ~Milk();

protected:
    double volume;
    double fatness;
};

