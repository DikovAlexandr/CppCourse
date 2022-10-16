#include <iostream>
#include <random>
#include <algorithm>
#include <cstdlib>
#include <locale>
#include <vector>

using namespace std;

// Функция вывода масссива
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Процедура для преобразования в двоичную кучу поддерева с корневым узлом i
void heapRoot(int arr[], int n, int i) {
    int largest = i;
    // Инициализируем наибольший элемент как корень
    int l = 2 * i + 1; // левый = 2*i + 1
    int r = 2 * i + 2; // правый = 2*i + 2

    // Если левый дочерний элемент больше корня
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // Если самый большой элемент не корень
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Преобразуем в двоичную кучу текщее поддерево
        heapRoot(arr, n, largest);
    }
}

// Функция выполняющая пирамидальную сортировку
void heapSort(int arr[], int n) {
    // Построение кучи (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapRoot(arr, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i >= 0; i--) {
        // Перемещаем текущий корень в конец
        swap(arr[0], arr[i]);

        // вызываем процедуру heapRoot на уменьшенной куче
        heapRoot(arr, i, 0);
    }
}

// Управляющая программа
int main() {
    int n = 10;
    int arr[n];
    for (auto &i: arr) {
        i = 1 + rand() % 9;
    }
    cout << "Unsorted array is \n";
    printArray(arr, n);
    heapSort(arr, n);
    cout << "Sorted array is \n";
    printArray(arr, n);
}