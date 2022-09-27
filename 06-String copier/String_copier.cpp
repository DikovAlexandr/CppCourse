#include <iostream>
#include <string>
using namespace std;

int main() {
    string input, output;
    cin >> input;
    for (int i=0; i<=input.size(); i++)
        output+=input[i];
    cout << output <<endl;
    return 0;
}
