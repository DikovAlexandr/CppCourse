#include <iostream>
#include <fstream>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to partition the array using Lomuto
int partitionLomuto(int arr[], int left, int right) {
    int pivot_value = arr[left]; // Choose the first element as the pivot
    int pivot_point = left;

    for (int i = left + 1; i <= right; i++) {
        // If the current element is less than or equal to the pivot
        if (arr[i] <= pivot_value) {
            pivot_point++;
            std::swap(arr[i], arr[pivot_point]);
        }
    }
    swap(arr[pivot_point], arr[left]);
    return pivot_point;
}

// Function to partition the array using Hoare
int partitionHoare(int arr[], int left, int right) {
    int pivot_value = arr[left]; // Choose the first element as the pivot
    int i = left - 1, j = right + 1;

    while (true) {
        // Find an element greater than or equal to the pivot on the left
        do { 
            i++; 
        } while (arr[i] < pivot_value);

        // Find an element less than or equal to the pivot on the right
        do { 
            j--; 
        } while (arr[j] > pivot_value); 

        // If the indices have not crossed, swap the elements
        if (i >= j) {
            return j;
        }
        swap(arr[i], arr[j]);
    }
}

// func Partition_Hoare(A, left, right)
//  pivot_value = A[(left+right)/2]
//  i = left
//  j = right
//  while (i <= j)
//      while (A[i] < pivot_value)
//         ++i;
//      while (A[j] > pivot_value)
//         --j;
//      if (i >= j) break;
//      swap(A[i], A[j]);
//      ++i;
//      --j;

// Main function for quicksort
void quickSort(int arr[], int low, int right, int partitionScheme) {
    if (low >= right) return;
    int pivot;

    if (partitionScheme == 0) {
        // Get the index of partition
        pivot = partitionHoare(arr, low, right);
        // Recursively sort elements before and after the pivot
        quickSort(arr, low, pivot, partitionScheme);
        quickSort(arr, pivot + 1, right, partitionScheme);
    } else if (partitionScheme == 1) {
        // Get the index of partition
        pivot = partitionLomuto(arr, low, right);
        // Recursively sort elements before and after the pivot
        quickSort(arr, low, pivot - 1, partitionScheme);
        quickSort(arr, pivot + 1, right, partitionScheme);
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

    // Call quickSort where last argument 0 is Lomuto and 1 is Hoare)
    quickSort(arr, 0, n - 1, 0);

    for (int i = 0; i < n; i++) {
        output << arr[i] << " ";
    }

    delete[] arr;
    input.close();
    output.close();

    return 0;
}