//
// Created by dsash on 31.10.2022.
//

#include <utility>
#include <vector>
#include <iostream>

#include "CStructureWithContainer.h"

CStructureWithContainer::CStructureWithContainer(std::vector<int> a) : a(std::move(a)) {}

void CStructureWithContainer::print() {
    for (int i: a) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

CStructureWithContainer::~CStructureWithContainer() = default;

