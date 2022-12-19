#pragma once

#include "Milk.hpp"
#include <string>

class Yogurt : public Milk {
public:
    Yogurt(int id, std::string name, double price, double quantity, double volume, double fatness, bool bio,
           std::string taste, std::string brand);

    std::string getBio();

    std::string getTaste();

    std::string getBrand();

    friend std::ostream &operator<<(std::ostream &os, const Yogurt &yogurt) {
        os << yogurt.id << " " << yogurt.name << " " << yogurt.fatness << " " << yogurt.volume << ""
           << (yogurt.bio ? "bio" : "nonbio") << " " << yogurt.price << " " << yogurt.quantity;
        return os;
    }

    //std::string getItem() override;

    ~Yogurt();

protected:
    bool bio{}; // 1 - bio, 0 - nonbio
    std::string taste;
    std::string brand;
};

