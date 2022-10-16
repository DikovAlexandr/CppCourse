#include <iostream>

using namespace std;

// By references
void swap1(int& a, int& b){
    a = a + b;
    b = a - b;
    a = a - b;
}

// By ratio
void swap2(int& a, int& b){
    a = a * b;
    b = a / b;
    a = a / b;
}

// By XOR
void swap3(int& a, int& b){
    a = a xor b;
    b = b xor a;
    a = a xor b;
}

// By sigle line expressions
void swap4(int& a, int& b)
{
    // a = a ^ b ^ (b = a);
    // a = a + b - (b = a);
    a = (a * b) / (b = a);
}

// By stricture
struct swap5
{
    int a;
    int b;
};

int main() {
    int a, b;
    cout << "Enter two numbers" << endl;
    cin >> a >> b;
    swap1(a, b);
    cout << a << " " << b << endl;
    swap2(a, b);
    cout << a << " " << b << endl;
    swap3(a, b);
    cout << a << " " << b << endl;
    swap4(a, b);
    cout << a << " " << b << endl;
    swap5 swap{};
    swap.a = b;
    swap.b = a;
    cout << swap.a << " " << swap.b << endl;
    return 0;
}
