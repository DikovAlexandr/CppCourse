//
// Created by dsash on 31.10.2022.
//
#pragma once

class CStructure {
public:
    // Виртуальная функция push
    virtual void push(int x = 0) = 0;

    // Виртуальная функция pop
    virtual void pop() = 0;
};
