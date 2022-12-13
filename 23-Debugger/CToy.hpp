#pragma once

#include <string>
#include "CShowable.hpp"

class CToy : public CShowable {
private:
    std::string animal, color;
public:
    CToy(std::string color = "black", std::string animal = "void");

    ~CToy();

    std::string show() final;
};
