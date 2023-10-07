#include <iostream>
#include <cstdint>
#include <cmath>

void Task1() {
    int target_value = 1073741824;
    unsigned char A[4];
    unsigned int *A_ptr = reinterpret_cast<unsigned int *>(A);
    *A_ptr = target_value;

    unsigned int result = *(reinterpret_cast<unsigned int *>(A));
    if (result == target_value) {
        for (int i = 0; i < 4; i++) {
            std::cout << static_cast<int>(A[i]) << " ";
        }
        std::cout << std::endl;
    }
}

void Task2() {
    double target_value = 9e99;
    unsigned char A[8];
    double* A_ptr = reinterpret_cast<double*>(A);
    *A_ptr = target_value;

    double result = *(reinterpret_cast<double *>(A));
    if (result == target_value) {
        for (int i = 0; i < 8; i++) {
            std::cout << static_cast<int>(A[i]) << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    Task1();
    Task2();
    return 0;
}