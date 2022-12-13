#include <iostream>
#include "CSong.hpp"

CSong::CSong(std::string author, std::string title) : author(author), title(title) {}

CSong::~CSong() = default;

std::string CSong::show() {
    return "CSong('" + author + "', '" + title + "')";
}