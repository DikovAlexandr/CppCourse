#pragma once

#include "CStructure.h"
#include <vector>

template<typename T>
class CStructureWithContainer : virtual public CStructure<T> {
public:
    // Конструктор
    CStructureWithContainer();

    // Set
    void setVector(std::vector<T> input);

    // Get
    std::vector<T> getVector();

    // Вывод вектора
    void print();

    // Деструктор
    ~CStructureWithContainer();

    // Поле вектор
    std::vector<T> a;
};
