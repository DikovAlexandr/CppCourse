#include <iostream>

///////////////////////////
// Структуры в языке C++ //
///////////////////////////

struct Complex {
    double Re = 1.0; // Значение по умолчанию
    double Im = 3.0;
} c, d; // Можно сразу создавать переменные

// Стек (LIFO)
// Реализуют на списках и массивах (количество элементов фиксировано)
struct Node {
    int kay;
    Node* prev = NULL;
}

struct Stack {
    Node* head = NULL;
    int size = 0;
} 

// Push = {address = header; headed = adderss_of_new_element}
void Push(Stack &S, int value){
    Node* new_element = new Node;
    new_element->kay = value;
    new_element->prev = S.head;
    S.head = new_element;
    S.size++;
    return 0;
}

// Pop = {headed = address_of_previous_element; detete last element}
void Pop(Stack &S){
    Node* del_element = S.head;
    del_element = S.head;
    if (del_element != NULL){
        S.head = del_element->prev;
        S.size--;
        delete del_element;
    }
    return 0;
}

void PrintStack(Steck* S){
    print_element = S.head;
    if (S.size > 0){       
        for (int size = S.size; size>0, size--){
            std::cout << print_element->kay << std::endl;
            print_element = print_element->prev;
        }
    }
    return
}

void Func(int &y){
    y = 10;
}

int main() {
    Complex a, *b, e{6.0}; // Можно задавать переменные сразу, остальные заполнятся нулями
    a.Re = 5.0;
    a.Im = 7.8;
    b -> Re = 10.0; // Доступ к полям структуры по указателю осуществляется следующими образами
    (*b).Im = 8.5;
    
    d = c; // Операция равно определена по умолчанию, остальные операции надо описывать отдельно
    
    std::cout << "a.Re =" << a.Re << "; a.Im =" << a.Im  << std::endl;
    std::cout << "b.Re =" << b->Re << "; b.Im =" << (*b).Im << std::endl;
    
    // Односвязный список - элемент хранит свое значение и указатель на последующий или предыдущий элемент
    // Таким образом элемент образуют цепь по которой обязательно пройти по (n-1) элементы чтобы дойти до n
    // Недостатком является то, что элементы зранятся непоследовательно
    //
    // Список            | Массив
    // -------------------------------------
    // Доступ за O(n)    | Доступ за O(1) 
    // Вставка за O(1)   | Вставка за O(n)
    // Удаление за O(1)  | Удаление за O(n)
    // Поиск за O(n)     | Поиск за O(n)
    //
    // Teta(g(n)): {f(n): ∃ c_1, c_2 > 0; ∃ n_0 ∈ N; ∀ n > n_0: 0 < c_1 * g(n) < f(n) < c_2 * g(n)}
    // Опеределение O(n): {∃ c > 0; ∃ n_0 ∈ N; ∀ n > n_0: 0 <= f(n) < c * g(n)}
    // Teta(g(n)): {f(x): ∃ c > 0; ∃ n_0 ∈ N; ∀ n > n_0: 0 <= c * g(n) < f(n)}
    
    Stack S;
    Push(S, 5);
    Push(S, 2);
    Push(S, 3);
    Pop(S);
    PrintStack(S);
    
    int b = 5;
    int a = b; // int* a = &b; 
    // int &a = b; // Так мы связываем a и b, теперь они один и тот же объект (a это синоним b)
    std::cout << "Before" << std::endl;
    std::cout << "a = " <<  a << std::endl;
    std::cout << "b = " <<  b << std::endl;
    
    a = 7
    std::cout << "After" << std::endl;
    std::cout << "a = " <<  a << std::endl;
    std::cout << "b = " <<  b << std::endl;
    
    // Ссылки используются в функциях
    int x = 7;
    Func(x)
    std::cout << "x = " << x << std::endl;
    return 0;
}