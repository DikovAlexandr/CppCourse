#include <iostream>
#include <limits>
#include <vector>

using namespace std;
// вывод действия
void move(int a, int b) {
    cout << a << " --> " << b << endl;
}
// реккурентная функция перемещений

/* чтобы передвинуть n дисков из 1 в 3
 * надо передвинуть n-1 дисков из 1 в 2
 * после этого можем передвинуть n-нный диск
 * и все оставшиеся диски передвигаем в 3
 *
*/
void recmove(int n, int a, int b, int c) {
    if (n == 0) return;
    recmove(n - 1, a, c, b);
    move(a, b);
    recmove(n - 1, c, b, a);
}

int main() {
    int n, a, b, c;
    cout << "Enter the number of rings" << endl;
    cin >> n;
    a = 1;
    b = 3;
    c = 2;
    recmove(n, a, b, c);
}