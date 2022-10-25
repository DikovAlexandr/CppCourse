#include <iostream>
#include <random>
#include <algorithm>
#include <cstdlib>
#include <locale>
#include <utility>
#include <vector>
#include "Neuron.h"
using namespace std;

//Класс - некий новый тип данных
//Класс не возвращает никакие значения, в отличии от функций

// Функция рандомного заполнения массива типа vector рандомными дробными значенями от 0 до 1
vector<double> randomVector(int size)
{
    vector<double> a(size);

    for (double & i : a) {
        i = (double)(rand())/RAND_MAX;
    }
    return a;
}

int main() {
    // Создадим объект класса
    int n = 5;
    Neuron axon(n, randomVector(n), randomVector(n+1), false);
    // Результат работы нейрона
    cout << axon.calculate() << endl;
    return 0;
}
