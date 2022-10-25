//
// Created by dsash on 24.10.2022.
//
#include <iostream>
#include <fstream>
#include "Rectangle.h"

Rectangle::Rectangle(double x_1, double y_1, double x_2, double y_2) {
    x1 = std::min(x_1, x_2);
    x2 = std::max(x_1, x_2);
    y1 = std::max(y_1, y_2);
    y2 = std::min(y_1, y_2);
}

Rectangle::~Rectangle() = default;

bool Rectangle::isIntersected(const Rectangle& rec1, const Rectangle& rec2) {
    return !(rec1.y1 < rec2.y2 || rec1.y2 > rec2.y1 || rec1.x2 < rec2.x1 || rec1.x1 > rec2.x2);
}