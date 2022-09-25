#include <iostream>
#include <string>
using namespace std;

int task3() {
    int n;
    cout << "Think of a number N from 1 to 100, and I'll guess!" <<endl;
    int l = 1;
    int r = 100;
    int mid, mark=0, k=0;

    while ((l <= r) && (mark != 3)) {
        mid = (l + r) / 2;
        cout << "N bigger " << mid << " (1 yes, 2 no, 3 equals)?" <<endl;
        cin >> mark;
        if (mark==1) {l=mid;}
        if (mark==2) {r=mid;}
        k++;
    }
    cout << "You thought " << mid << "! And I'm great! Number of attempts: " << k <<endl;
    return 0;
}
