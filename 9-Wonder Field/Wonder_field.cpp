#include <iostream>
#include <string>

using namespace std;
int main(){
    string word, mask;
    char x;
    bool f;
    cout << "Enter word:" << endl;
    cin >> word;
    cout << endl;
    for (int i=0; i<word.size(); i++)
    {
        mask+="-";
    }
    cout << mask << endl;
    int count = word.size();
    while (count>0){
        cout << "Enter letter: ";
        cin >> x;
        cout << endl;
        f=false;
        for (int i = 0; i <= word.size(); ++i) {
            if (word[i]==x) {
                f=true;
                count--;
                mask[i]=x;
            }
        }
        if (f) {
            cout << "You're right" << endl;
            cout << mask << endl;
        }
        else {
            cout << "You're wrong" << endl;
            cout << mask << endl;
        }
    }
    cout << "You guessed the word " << word << endl;
    return 0;
}