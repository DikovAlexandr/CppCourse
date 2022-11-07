#include "LIFO.h"

// Конструктор
template<typename T>
LIFO<T>::LIFO() = default;

// Добавление элемента
template<typename T>
void LIFO<T>::push(T x) {
    LIFO<T>::a.push_back(x);
}

// Удаление элемента
template<typename T>
T LIFO<T>::pop() {
    T temp = LIFO<T>::a.back();
    LIFO<T>::a.pop_back();
    return temp;
}

// Деструктор
template<typename T>
LIFO<T>::~LIFO() = default;
