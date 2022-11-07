#pragma once

#include "CStructureWithContainer.h"
#include <vector>

template<typename T>
class FIFO : public CStructureWithContainer<T> {
public:
    // Конструктор
    FIFO();

    // Добавление элмента
    void push(T x);

    // Удаление элемента
    T pop();

    // Деструктор
    ~FIFO();
};
