#include <iostream>
#include <fstream>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Procedure to transform a subtree with root at node i into a binary heap
void heapRoot(int arr[], int n, int i) {
    int largest = i;
    // Initialize the largest element as the root
    int l = 2 * i + 1; // Left child = 2*i + 1
    int r = 2 * i + 2; // Right child = 2*i + 2

    // If the left child is larger than the root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If the right child is larger than the current largest element
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If the largest element is not the root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the current subtree
        heapRoot(arr, n, largest);
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
    // Build a heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapRoot(arr, n, i);

    // One by one extract elements from the heap
    for (int i = n - 1; i >= 0; i--) {
        // Move the current root to the end
        swap(arr[0], arr[i]);

        // Call heapRoot on the reduced heap
        heapRoot(arr, i, 0);
    }
}

int main() {
    std::ifstream input("INPUT.txt");
    std::ofstream output("OUTPUT.txt");

    int n;
    input >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        input >> arr[i];
    }

    heapSort(arr, n);

    for (int i = 0; i < n; i++) {
        output << arr[i] << " ";
    }

    input.close();
    output.close();
    delete arr;
}