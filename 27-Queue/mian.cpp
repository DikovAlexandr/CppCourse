#include <iostream>
#include <fstream>

struct Node {
    int key;
    Node* next = nullptr;
};

struct Queue {
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;
};

void Push(Queue &Q, int value){
    Node* new_element = new Node;
    new_element->key = value;
    new_element->next = nullptr;
    
    if (Q.size == 0) {
        Q.head = new_element;
        Q.tail = new_element;
    } else {
        Q.tail->next = new_element;
        Q.tail = new_element;
    }

    Q.size++;
}

int Pop(Queue &Q){
    Node* del_element = Q.head;
    if (del_element != nullptr){
        int popped_value = del_element->key;
        Q.head = del_element->next;
        delete del_element;
        Q.size--;

        if (Q.size == 0) {
            Q.tail = nullptr;
        }

        return popped_value;
    }
    return -1;
}

int Front(const Queue &Q){
    if (Q.head != nullptr){
        return Q.head->key;
    }
    return -1;
}

int Size(const Queue &Q){
    return Q.size;
}

void Clear(Queue &Q){
    while (Q.head != nullptr) {
        Node* del_element = Q.head;
        Q.head = del_element->next;
        delete del_element;
    }
    Q.tail = nullptr;
    Q.size = 0;
}

int main() {
    std::ifstream input("INPUT.txt");
    std::ofstream output("OUTPUT.txt");

    int N;
    input >> N;

    Queue queue;

    for (int i = 0; i < N; i++) {
        std::string command;
        input >> command;

        if (command == "push") {
            int n;
            input >> n;
            Push(queue, n);
            output << "ok" << std::endl;
        } else if (command == "pop") {
            int result = Pop(queue);
            if (result != -1) {
                output << result << std::endl;
            } else {
                output << "error" << std::endl;
            }
        } else if (command == "front") {
            int result = Front(queue);
            if (result != -1) {
                output << result << std::endl;
            } else {
                output << "error" << std::endl;
            }
        } else if (command == "size") {
            output << Size(queue) << std::endl;
        } else if (command == "clear") {
            Clear(queue);
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