//
// Created by dsash on 31.10.2022.
//

#include <utility>
#include <vector>
#include <cassert>
#include "FIFO.h"

FIFO::FIFO(std::vector<int> a) : CStructureWithContainer(std::move(a)) {}

void FIFO::push(int x) {
    a.vector::insert(a.vector::begin(), x);
}

void FIFO::pop() {
    a.vector::erase(a.vector::begin());
}

FIFO::~FIFO() = default;
