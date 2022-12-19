#include <iostream>
#include <ctype.h>
#include "StoreLib.hpp"

/*
 * Магазин класс item {price quantity}
 * Fruit {country}
 * Milk {volume fatness}
 * Yogurt {bio-nonbio taste brand}
 *
 * Заказ сумма и состав
 * вывести чек
 * показать цену
 * посмотреть заказы
 *
 */

//struct Cart {
//    int fruitQuantity;
//    int milkQuantity;
//    int yogurtQuantity;
//    double totalPrice;
//};

void printShop(const std::vector<Item> &shopAssortment) {
    for (const auto &i: shopAssortment) {
        std::cout << i;
    }
    std::cout << std::endl;
}

int main() {

    Yogurt item1(1, "Chudo", 129, 10, 690, 1.8, true, "charry", "Chudo");
    Yogurt item2(2, "Chudo", 129, 10, 690, 1.8, true, "strawberry", "Chudo");
    Yogurt item3(3, "Chudo", 129, 10, 690, 1.8, true, "mango", "Chudo");

    Fruit item4(4, "Mango", 450, 10, "Thailand");
    Fruit item5(5, "Mango", 260, 10, "Vietnam");

    Fruit item6(6, "Banana", 70, 10, "Equator");
    Fruit item7(7, "Banana", 80, 10, "Columbia");

    Fruit item8(8, "Apple", 99, 10, "Russia");
    Fruit item9(9, "Apple", 140, 10, "Russia");

    std::vector<Item> shopAssortment = {item1, item2, item3, item4, item5, item6, item7, item8, item9};

    Cart userCart;

    char a;
    while (true) {
        std::cout
                << "1 - print assortment, 2 - choose item -> choose quantity, 3 - print cart, 4 - erase from cart, 5 - exit"
                << std::endl;
        std::cin >> a;
        if (std::isdigit(a)) {
            switch (a) {
                case '1' : {
                    printShop(shopAssortment);
                    break;
                }
                case '2' : {
                    int id;
                    std::cout << "Choose item by id code" << std::endl;
                    std::cin >> id;
                    double quantity;
                    std::cout << "Choose item's quantity" << std::endl;
                    std::cin >> quantity;
                    for (auto &i: shopAssortment) {
                        if (i.getId() == id) {
                            userCart.addToCart(i, quantity);
                            i.quantityDecrease(quantity);
                        }
                    }
                    break;
                }
                case '3' : {
                    userCart.printCart();
                    break;
                }
                case '4' : { // working uncorrected
                    int id;
                    std::cout << "Choose item by id code" << std::endl;
                    std::cin >> id;
                    userCart.removeFromCart(id);
                    break;
                }
                case '5' : {
                    return 0;
                }
            }
        }
    }
}
