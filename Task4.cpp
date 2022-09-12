#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <limits>

using namespace std;

int main() {
    int n;
    bool flag = true;
    do
    {
        cout << "Enter the number. I will determine if it is simple" <<endl;
        cin >> n ;
        if ( !(flag=cin.good()) )
            cout << "Input error!" << endl;
        cin.clear() ;
        cin.ignore( numeric_limits<streamsize>::max() , '\n') ;
    }while( !flag );

    //cout << "Enter: " << n << endl;

    if ((!cin) || (typeid(n) != typeid(int))) {
        cout << "Error" << endl;
    }
    else {
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                cout << "It is not simple" << endl;
                return 0;
            }
        }
        cout << "It is simple" << endl;
    }
    return 0;
}
