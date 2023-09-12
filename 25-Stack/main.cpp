#include <iostream>
#include <fstream>

struct Node {
    int key;
    Node* prev = nullptr;
};

struct Stack {
    Node* head = nullptr;
    int size = 0;
};

void Push(Stack &S, int value){
    Node* new_element = new Node;
    new_element->key = value;
    new_element->prev = S.head;
    S.head = new_element;
    S.size++;
}

int Pop(Stack &S){
    Node* del_element = S.head;
    if (del_element != nullptr){
        S.head = del_element->prev;
        int popped_value = del_element->key;
        delete del_element;
        S.size--;
        return popped_value;
    }
    return -1;
}

int Back(const Stack &S){
    if (S.head != nullptr){
        return S.head->key;
    }
    return -1;
}

int Size(const Stack &S){
    return S.size;
}

void Clear(Stack &S){
    while (S.head != nullptr) {
        Node* del_element = S.head;
        S.head = del_element->prev;
        delete del_element;
    }
    S.size = 0;
}

int main() {
    std::ifstream input("INPUT.txt");
    std::ofstream output("OUTPUT.txt");

    int N;
    input >> N;

    Stack stack;

    for (int i = 0; i < N; i++) {
        std::string command;
        input >> command;

        if (command == "push") {
            int n;
            input >> n;
            Push(stack, n);
            output << "ok" << std::endl;
        } else if (command == "pop") {
            int result = Pop(stack);
            if (result != -1) {
                output << result << std::endl;
            } else {
                output << "error" << std::endl;
            }
        } else if (command == "back") {
            int result = Back(stack);
            if (result != -1) {
                output << result << std::endl;
            } else {
                output << "error" << std::endl;
            }
        } else if (command == "size") {
            output << Size(stack) << std::endl;
        } else if (command == "clear") {
            Clear(stack);
            output << "ok" << std::endl;
        } else if (command == "exit") {
            output << "bye" << std::endl;
            break;
        }
    }

    input.close();
    output.close();

    return 0;
}
