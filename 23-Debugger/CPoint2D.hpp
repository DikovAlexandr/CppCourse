#pragma once

#include "CShowable.hpp"

class CPoint2D : public CShowable {
private:
    double x, y;
public:
    CPoint2D(double x = 0, double y = 0);

    ~CPoint2D();

    std::string show() final;
};
