#include <iostream>
#include "CToy.hpp"

CToy::CToy(std::string color, std::string animal) : color(color), animal(animal) {}

CToy::~CToy() = default;

std::string CToy::show() {
    return "CToy('" + color + "', '" + animal + "')";
}
