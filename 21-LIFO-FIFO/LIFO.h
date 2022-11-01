//
// Created by dsash on 31.10.2022.
//
#pragma once

#include "CStructureWithContainer.h"
#include <vector>

class LIFO : public CStructureWithContainer {
public:
    // Конструктор
    explicit LIFO(std::vector<int> a);

    void push(int x);

    void pop();

    // Деструктор
    ~LIFO();
};
