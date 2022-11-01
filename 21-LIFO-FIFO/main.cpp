#include <iostream>
#include <fstream>
#include <vector>

#include "CStructure.h"
#include "CStructureWithContainer.h"
#include "LIFO.h"
#include "FIFO.h"

using namespace std;

void addValues(CStructureWithContainer &storage, int n) {
    fstream data;
    data.open("data.txt");
    int x = 0;
    for (int i = 0; i < n; ++i) {
        data >> x;
        storage.push(x);
        storage.print();
    }
    data.close();
};

void removeValues(CStructureWithContainer &storage, int n) {
    for (int i = 0; i < n; ++i) {
        storage.print();
        storage.pop();
    }
};

int main() {
    int n = 4;
    vector<int> a;
    LIFO stack(a);
    FIFO queue(a);
    // Stack
    cout << "Adding values in stack (last in - first out):" << endl;
    addValues(stack, n);
    cout << "Deleting values form stack (last in - first out):" << endl;
    removeValues(stack, n);
    // Queue
    cout << "Adding values in queue (first in - first out):" << endl;
    addValues(queue, n);
    cout << "Deleting values form queue (first in - first out):" << endl;
    removeValues(queue, n);
    return 0;
}
