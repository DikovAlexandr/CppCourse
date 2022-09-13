#include <iostream>
#include <limits>
#include <vector>

using namespace std;

void Fibbonachi(int x) {
    unsigned  long  a = 1, b = 1;
    vector<unsigned long> fibb(x + 1);
    fibb[0] = 1;
    fibb[1] = 1;
    for (int i = 2; i <= x + 1; ++i) {
        fibb[i] = fibb[i - 1] + fibb[i - 2];
    }
    for (int i = 0; i < x; i++) {
        cout << fibb[i] << " ";
    }
}

int GetInt() {
    int a = 0;
    cout << "Enter a integer value: ";
    string s;
    char c;
    cin >> s;
    if (s.length() > 4) { return -1; }
    else {
        for (char i: s) {
            if (i >= '0' && i <= '9') {
                c = i;
                a = a * 10 + int(c) - 48;
            } else { return -1; }
        }
    }
    return a;
}

int main() {
    int x = GetInt();
    if ((x != -1) && (1 <= x) && (x <= 100))
    Fibbonachi(x);
    else cout << "Your enter is incorrect" << endl;
    return 0;
}