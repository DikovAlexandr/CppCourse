#include "FIFO.h"

// Конструктор
template<typename T>
FIFO<T>::FIFO() = default;

// Добавление элемента
template<typename T>
void FIFO<T>::push(T x) {
    FIFO<T>::a.push_back(x);
}

// Удаление элемента
template<typename T>
T FIFO<T>::pop() {
    T temp = FIFO<T>::a.front();
    FIFO<T>::a.erase(FIFO<T>::a.begin());
    return temp;
}

// Деструктор
template<typename T>
FIFO<T>::~FIFO() = default;
