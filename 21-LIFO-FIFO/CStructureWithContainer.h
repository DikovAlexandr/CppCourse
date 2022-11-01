//
// Created by dsash on 31.10.2022.
//
#pragma once

#include "CStructure.h"
#include <vector>
#include <iostream>

class CStructureWithContainer : virtual public CStructure {
public:
    // Поле вектор
    std::vector<int> a;

    // Конструктор
    explicit CStructureWithContainer(std::vector<int> a);

    // Вывод вектора
    void print();

    // Деструктор
    ~CStructureWithContainer();
};
