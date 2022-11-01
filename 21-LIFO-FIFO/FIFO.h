//
// Created by dsash on 31.10.2022.
//
#pragma once

#include "CStructureWithContainer.h"
#include <vector>

class FIFO : public CStructureWithContainer {
public:
    // Конструктор
    explicit FIFO(std::vector<int> a);

    void push(int x);

    void pop();

    // Деструктор
    ~FIFO();
};
