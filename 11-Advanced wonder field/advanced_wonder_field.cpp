#include <iostream>
#include <string>

using namespace std;

int main() {
    // объявление переменных
    string word, mask, pull, pred, clone;
    int k, pos, count = 1;
    bool f, lf, err = false;
    // считывание загадываемого слова
    cout << "Enter word:" << endl;
    cin >> word;
    cout << endl;
    // создание и вывод маски
    for (int i = 0; i < word.size(); i++) {
        mask += "-";
    }
    cout << mask << endl;
    // цикл отгадывания
    while (count <= word.length()) {
        // ввод нового числа
        cout << "Enter letter: ";
        cin >> pred;
        cout << endl;

        f = false; // флаг отвечающий за выбор
        pos = pull.find(pred); // поиск введенного слова в пуле уже введенных ранее
        // cout << "pos " << pos;
        if (pos >= 0) {
            if (pred.size() == 1) cout << "This letter has already been, please try again" << endl;
            else {
                cout << "Unfortunately, you didn't guess the word. Game over" << endl;
                err = true;
                break;
            }
        }
            // если введенное слово встретилось впервые
        else {
            pos = word.find(pred);
            if (pos >= 0) {
                f = true;
                k = 0;
                // цикл открывающий одинаковые части в слове
                clone = word;
                lf = true;
                while (lf) {
                    pos = clone.find(pred);
                    if (pos >= 0) {
                        k=0;
                        for (int i = pos; i < pos + pred.size(); ++i) {
                            mask[i] = pred[k];
                            clone[i] = '-';
                            count++;
                            k++;
                        }
                    } else lf = false;
                }

            }
        }
        if (f) {
            cout << "You're right" << endl;
            cout << mask << endl;
        } else {
            if (pred.size() > 1) {
                cout << "Unfortunately, you didn't guess the word. Game over" << endl;
                err = true;
                break;
            } else {
                cout << "You're wrong" << endl;
                cout << mask << endl;
            }

        }
        pull += pred;
    }
    if (!err) cout << "You guessed the word " << word << endl;
    return 0;
}