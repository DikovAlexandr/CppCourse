//
// Created by dsash on 24.10.2022.
//

#ifndef RECTANGLES_RECTANGLE_H
#define RECTANGLES_RECTANGLE_H


class Rectangle {
public:
    Rectangle(double x_1, double y_1, double x_2, double y_2);
    ~Rectangle();

    static bool isIntersected(const Rectangle& rec1, const Rectangle& rec2);
private:
    double x1{}, y1{}, x2{}, y2{};
};



#endif //RECTANGLES_RECTANGLE_H
