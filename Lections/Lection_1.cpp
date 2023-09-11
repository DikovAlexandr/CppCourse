#include<iostream>

class Lecture {
public:
    //////////////////////////
    // Классификаторы в C++ //
    //////////////////////////

    // Const - это квалификатор переменной, который указывает на то, что значение переменной не может быть изменено после инициализации.
    void DemonstrateConst() {
        int a = 10;
        {
            int a = 5;
            std::cout << "Local" << a << std::endl;
            std::cout << "Global" << ::a << std::endl; // ::a выводит глобальную переменную a
        }
        std::cout << a << std::endl;
    }

    // Volatile используется для указания того, что переменная может изменяться вне программы 
    // (например, аппаратно) и не должна быть оптимизирована компилятором.
    void DemonstrateVolatile() {
        volatile int value = 0;
        std::cout << "Volatile variable value: " << value << std::endl;
    }

    // // Квалификатор mutable используется только с членами класса, указывая, что они могут 
    // // быть изменены внутри константных методов класса.
    // class MyClass {
    // public:
    //     int getValue() const {
    //         // data = 20; // Ошибка: нельзя изменить внутри константного метода
    //         return data;
    //     }
    // private:
    //     mutable int data = 10;
    // };

    // Квалификатор inline используется для предложения компилятору вставить код функции 
    // непосредственно в месте её вызова, что может увеличить производительность.
    inline int add(int a, int b) {
        return a + b;
    }

    // Квалификатор static может использоваться с переменными и функциями. Статическая переменная 
    // существует в течение всего времени выполнения программы, а статическая функция ограничена 
    // областью видимости в пределах текущего файла.
    static void DemonstrateStatic() {
        static int counter = 0; // Статическая переменная
        counter++;
        std::cout << "Static counter: " << counter << std::endl;
    }


    // Если нет фигурных скобок, то else относится к ближайшему оператору if. Задача Хокко.
    // Условия в операторе if используют короткую логику, при которой проверка останавливается 
    // при первом ложном условии (если остальные связаны с ним оператором "и") и при первом 
    // истинном условии (если остальные связаны с ним оператором "или").
    void Hokko() {
        if (true)
            if (false) std::cout << "A" << std::endl;
        else std::cout << "B" << std::endl;
        // Code print B
    }


    // Строки в языках программирования C и C++ хранят не только символы строки, но и символ окончания 
    // строки ('\n'), который обозначает конец строки.
    void String() {
        std::cout << sizeof('a') << std::endl;
        std::cout << sizeof("a") << std::endl;
    }

    // Как записываются числа в память компьютера
    void Memory() {
        int a = 3;
        std::cout << "Value a = " << std::bitset(a) << std::endl; // Младшие разряды занимают старшие ячейки
    }

    /////////////////////
    // Указатели в C++ //
    /////////////////////


    // Виды памяти используемые программами: стек, статическая память, динамическая память (куча) и потоковая память.
    // 1) Стек представляет собой область памяти, используемую для хранения локальных переменных и данных функций. 
    // Он управляется по принципу Last-In-First-Out (LIFO).
    // 2) Глобальные переменные хранятся в статической памяти и имеют глобальную область видимости по всей программе.
    // 3) Динамическая память (куча) выделяется и освобождается во время выполнения программы. 
    // Это место, где хранятся данные, созданные с использованием операторов new и delete (или malloc и free в языке C).
    // 4) Потоковая память: Потоковая память используется для ввода и вывода данных. Она обеспечивает связь программы с 
    // внешними устройствами ввода/вывода.

    
    // Указатели должны быть инициализированы, чтобы избежать ошибок при доступе к памяти.
    void PointerInitialization() {
        int* ptr = NULL; 
        std::cout << "Pointer = " << ptr << std::endl;
    }


    // Связь стека и динамической памяти реализуется через указатели. Указатели хранятся в стеке и могут указывать 
    // на объекты в динамической памяти, что позволяет управлять памятью.
    void PointerAccess() {
        int a = 10;
        int b = 2;
        int* ptr_a = &a;
        int* ptr_b = &b; 
        std::cout << "Pointer A = " << ptr_a << std::endl;
        std::cout << "Pointer B = " << ptr_b << std::endl;
    }

    
    // Изменение константного указателя невозможно, даже если он ссылается не на константу
    void PointerConst() {
        int a = 10;
        double b = 2.0;
        int* ptr_a = &a;
        const int* ptr_to_const = &a; // Указатель на константу
        int* const const_ptr = &a; // Указатель, значение(адрес) которого константа
        double* ptr_b = &b; 

        a = 10; // Можно поменять
        *ptr_to_const = 1000; // Нелья поменять, так как указатель счиатет что ссылвается на константу
        std::cout << "Pointer A = " << *ptr_a << std::endl;
        std::cout << "Pointer B = " << *ptr_b << std::endl;
    }


    // Изменение указателя
    void PointerEdit() {
        int a = 10;
        int* ptr_a_block = NULL;
        {
            int a = 5;
            ptr_a_block = &a;
            std::cout << "Value of a = " << *ptr_a_block << std::endl;
            std::cout << "Pointer a = " << ptr_a_block << std::endl;
        }
        std::cout << "Value a = " << *ptr_a_block << std::endl; // Значение в общем случае помняется
        std::cout << "Pointer a = " << ptr_a_block << std::endl; // Адрес сохранится
    }


    // Арифметические операции с указателями
    void PointerSubtraction() {
        int a = 10;
        int b = 5;
        int* ptr_a = &a;
        int* ptr_b = &b;

        std::cout << ptr_b - ptr_a << std::endl; // Резульатат показывается не в байтах, а в том, сколько переменых такого типа вместится
        // Арифметические операции с указателями доступны только для указателей на одинакове типы данных
    }

    // Объявление статического массива
    void PointerToStaticArray() {
        int A[5] = {1, 2, 3, 4, 5}; // Статический массив, хранится в стеке
        int* ptr_a = A;
        std::cout << ptr_a << A << std::endl; // Имя массива это синоним указателя на первый элемент
    }


    // Объявление динамического массива
    void PointerToDinamicArray() {
        int A[5] = {1, 2, 3, 4, 5};
        int* B = new int[10];
        
        for (int i=0; i > 10; i++){
            B[i] = i;
            std::cout << B[i] << std::endl; // Младшие разряды занимают старшие ячейки
        }
        delete[]B;
        // Delete освобождает память, но не удаляет указатель
    }

    // Объявление двумерного динамического массива
    void PointerTo2DimArray() {
        int** A = new int*[5]; // Массив из указателей
        for (int i=0; i > 5; i++){
            A[i] = new int(1);
        }

        std::cout << A[0] << std::endl;
        std::cout << A[1] << std::endl;
        // Разница в 16
        // В стеке элементы массива идет друг а другом
        // D динамической памяти строчки кладутся не непрерывным образом, а даже случайны. Поэтому адресная арифметика не доступна
        delete[]A;
    }
};

int main() {
    Lecture lecture;    
    return 0;
}
