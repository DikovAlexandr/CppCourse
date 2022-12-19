cmake_minimum_required(VERSION 3.23)
project(Store)

set(CMAKE_CXX_STANDARD 17)

add_executable(Store "main.cpp"
        "StoreLib.hpp"
        "Item.hpp"
        "Item.cpp"
        "Fruit.hpp"
        "Fruit.cpp"
        "Milk.hpp"
        "Milk.cpp"
        "Yogurt.hpp"
        "Yogurt.cpp"
        "Cart.hpp"
        "Cart.cpp"
        )
