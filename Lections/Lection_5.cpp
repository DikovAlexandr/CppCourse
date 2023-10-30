// Перегрузка функций
// Это реализация функций с одинаковым именем, но различными параметрами
// Позволяет подавать на вход функциям с одинаковыми названиями разные типы параметров
// Компилятор сам проверяет какие данные мы передаем в функцию и вызывает нужный ее вариант
// Если список параметров одинаковый, но разный тип или количество выходных данных, то такая перегрузака заперщена
// Момент, когда компилятор выбирает нужную функцию называется разрешением перегрузки
// Порядок выбора функций компилятором
// - Полное соотвествие аргументов по типу и количеству
// - Если нет полного соответсвия то происходит неявное преобразование типов
//      char, unsigned char, short -> int
//      unsigned short -> int or unsigned int
//      float -> double
//      enum -> int
// - Если нет полного соответствия невозможно неявное преобразование компилятор будет искать соответсвие путем стандартного преобразования
//      Любой числовой тип будет преобразован к любому другому числовому типу
//      Ноль соответствует и чичсловому типу и типу указателя
//      enum соответсвует типу числовых данных
//      Любой указатель соответствует типу указатель на void
// - Пользомательское преобразование
// Если выбор неоднозначен, компилятор не будет его делать вовсе
// 
// Свойства сортировок
// - Inline - Без явного испрользования дополнительной памяти - то есть в алгоритме мы не выделяем дополнительной
//      быстрая сортировка так, как все результаты промежуточных вызывов рекурсии 
// - Без использования дополнительной памяти - больее сильное требование
//      квадратичне сортировки
// - Устойчивость (стабильность)
//      квадратичные сортировки стабильны
//      изначально быстрая сортировка не стабильна - ее можно сделать стабильной, добавиб индексы к элементам и сравнивать их дополнительно
// 
// Приомидальная сортировка
// Пирамида - объект массив, который может рассматриваться, как почти полное (заполнены все ряды, кроме, может быть, последнего, заполняющегося слева) бинарное дерево,
// Обладает следующими свойствами
// - для любого узла значение родителя больше или равно значению левого потомка
//   то есть для любого узла A[parent] >= A[left]
// - для любого узла значение родителя больше или равно значению парвого потомка
//   то есть для любого узла A[parent] >= A[right]
// При построении пирамиды плохое значение нужно поменять с большим из потомков - просеивание вниз
// SiftDown (A, i, size)
//  left = LeftChild(i)
//  right = LeftChild(i)
//  largest = i
//  if (left<size and A[left]>A[largest])
//      largest = left
//  if (left<size and A[right]>A[largest])
//      largest = right
//  if (largest != i)
//      swap(A[i], A[largest])
//      SiftDown(A, largest, size)
// SiftUp(A, i, size)
// ................
// 