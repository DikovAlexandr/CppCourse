#include <iostream>
#include <fstream>

#include "Rectangle.h"

using namespace std;

int main() {
    fstream data;
    data.open("data.txt");
    double a[4];
    for (int i = 0; i < 4; ++i) {
        data >> a[i];
    }
    cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << endl;

    Rectangle rec1(a[0], a[1], a[2], a[3]);
    for (int i = 0; i < 4; ++i) {
        data >> a[i];
    }
    Rectangle rec2(a[0], a[1], a[2], a[3]);
    cout << rec1.isIntersected(rec1, rec2) << endl;
    data.close();
    return 0;
}
