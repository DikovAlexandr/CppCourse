#include <iostream>
#include <limits>

using namespace std;

unsigned long Fact(int a){
    unsigned long b=1, c=1;
    for (int i = 1; i <= a; ++i) {
        b=b*c;
        c++;
        cout << c-1 << " " << b << endl;
    }
    return b;
}

int GetInt() {
    int a = 0;
    cout << "Enter a integer value(it must be less than 13): ";
    string s;
    char c;
    cin >> s;
    if (s.length() > 6) { return -1; }
    else {
        for (char i : s) {
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
    if (x!=-1) cout << Fact(x) << endl;
    else cout << "Your enter is incorrect" << endl;
    return 0;
}