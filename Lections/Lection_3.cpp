#include <iostream>
#include <math.h>
#include <stdlib.h>

int binary_digit() {
    int8_t A[2] = {128, 255}; // Какие числа нужно поместить в массив
    int8_t* y = A;
    int16_t* z = (int16_t*)A; // Чтобы получить 32767 при чтении тех же байтов массива как единого числа
    std::cout << "y = " << *y << std::endl;
    std::cout << "z = " << *z << std::endl;

    return 0;
}

// Домашнее задание: сделать тоже самое с double

int links() {
    int x = 0;
    int y = 1;
    int &rx = x;
    // int &&rt = &rx; // Так он подумает, что мы берем адресс
    int z = 0;
    int&&z = 0; // && позволяют сделать ссылку на r-value
    // int &v = 0; // Так нельзя присваивать ссылку, справа должна быть переменная
    // int &w = x + y; // Так тоже нельзя
    int&& w = x + y; // А так можно

    int &rz = rx; // Распиширили список синонимов еще одной ссылкой

    return 0;
}

// Три разных варианта передачи переменных в функцию
// void Ref(int x) { // Передача копии
//     x *= 10;
// }

// void Ref(int &x) { // Передача ссылки
//     x *= 10;
// }

// void Ref(int *x) { // Передача указателя
//     *x *= 10;
// }

// Локальная переменная в своей области видносительно перебивает глобальную. 
// Чтобы получить доступ к глобальной переменной, надо написать ::имя_переменной

int Ticket() {
    // int ticket = 1;
    static int ticket = 1; // Создается один раз и используется во всех вызовах этой функции
    // То есть она видна только здесь, а действует везде
    return ticket++; // Сначала вывод, потом инкрементация
    // return ++ticket; // Теперь наоборот
}

// Рекурсия

int Fact(int n) {
    if (n == 0) return 1;
    return n * Fact(n - 1);
}

int Fib(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    return Fib(n - 1) + Fib(n - 2);
}

int main() {
    return 0;
}