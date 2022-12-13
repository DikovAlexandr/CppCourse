#include <iostream>
#include "CPoint2D.hpp"

CPoint2D::CPoint2D(double x, double y) : x(x), y(y) {}

CPoint2D::~CPoint2D() = default;

std::string CPoint2D::show() {
    return "CPoint2D(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}
