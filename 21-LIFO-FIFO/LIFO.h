#pragma once

#include "CStructureWithContainer.h"
#include <vector>

template<typename T>
class LIFO : public CStructureWithContainer<T> {
public:
    // Конструктор
    LIFO();

    // Добавление элмента
    void push(T x);

    // Удаление элемента
    T pop();

    // Деструктор
    ~LIFO();
};
