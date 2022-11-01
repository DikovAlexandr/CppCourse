//
// Created by dsash on 31.10.2022.
//

#include <utility>
#include <vector>
#include "LIFO.h"

LIFO::LIFO(std::vector<int> a) : CStructureWithContainer(std::move(a)) {}

void LIFO::push(int x) {
    a.vector::push_back(x);
}

void LIFO::pop() {
    a.vector::erase(a.vector::begin());
}

LIFO::~LIFO() = default;
