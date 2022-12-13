#include <iostream>
#include <type_traits>
#include <vector>
#include "CShowable.hpp"
#include "CPoint2D.hpp"
#include "CSong.hpp"
#include "CToy.hpp"

template<typename T>
void display(T obj) {
//    static_assert(std::is_base_of<CShowable, T>::value, "Type of argument must be CPoint, CSong or CToy");
    std::cout << obj.show() << " Size: " << sizeof(T) << " bytes" << std::endl;
}

int main() {

    CPoint2D point = {1.0, 5.4};
    CSong song = {"Queen", "Brighton Rock"};
    CToy toy;
    display(song);
    std::cout << typeid(point).name();
//    std::vector<CShowable> list = {point, song, toy};
//    for (int i = 0; i < list.size(); ++i) {
//        display(list[i]);
//    }

    return 0;
}