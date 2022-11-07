//
// Created by dsash on 31.10.2022.
//
#pragma once

template<typename T>
class CStructure {
public:
    // Виртуальная функция push
    virtual void push(T x) = 0;

    // Виртуальная функция pop
    virtual T pop() = 0;
};
