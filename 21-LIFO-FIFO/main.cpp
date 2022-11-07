#include <iostream>
#include <fstream>
#include <vector>

#include "CStructure.h"
#include "CStructureWithContainer.h"
#include "LIFO.h"
#include "FIFO.h"

using namespace std;

// Функция заполнения хранилища
template<typename T>
void addValues(CStructureWithContainer<T> *storage, int n) {
    fstream data;
    data.open("data.txt");
    T x;
    vector<T> temp;
    for (int i = 0; i < n; ++i) {
        data >> x;
        temp.push_back(x);
    }
    storage->setVector(temp);
    storage->print();
    data.close();
};

// Функция очищения хранилища
template<typename T>
void removeValues(CStructureWithContainer<T> *storage, int n) {
    for (int i = 0; i < n; ++i) {
        storage->print();
        storage->pop();
    }
};

// Функция распознования типа
template<typename T>
void getCStructureType(CStructureWithContainer<T> *storage) {
    T temp = storage->getVector()[0];
    storage->pop();
    if (storage->getVector()[0] == temp) cout << "LIFO" << endl;
    else cout << "FIFO" << endl;
};

int main() {
    int n = 4;
    CStructureWithContainer<int> *stack = new LIFO<int>;
    CStructureWithContainer<int> *queue = new FIFO<int>;

    // Stack
    cout << "Adding values in stack (last in - first out):" << endl;
    addValues(stack, n);
    getCStructureType(stack);
    cout << "Deleting values form stack (last in - first out):" << endl;
    removeValues(stack, n);

    // Queue
    cout << "Adding values in queue (first in - first out):" << endl;
    addValues(queue, n);
    getCStructureType(queue);
    cout << "Deleting values form queue (first in - first out):" << endl;
    removeValues(queue, n);

    delete stack;
    delete queue;
    return 0;
}
