#include <vector>
#include <iostream>

#include "CStructureWithContainer.h"

template<typename T>
CStructureWithContainer<T>::CStructureWithContainer() = default;

template<typename T>
void CStructureWithContainer<T>::print() {
    for (int i: a) {
        std::cout << i << "\t";
    }
    std::cout << std::endl;
}

template<typename T>
void CStructureWithContainer<T>::setVector(std::vector<T> input) {
    a = input;
}

template<typename T>
std::vector<T> CStructureWithContainer<T>::getVector() {
    return a;
}

template<typename T>
CStructureWithContainer<T>::~CStructureWithContainer() = default;

