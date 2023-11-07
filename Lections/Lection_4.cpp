#include <iostream>

// Рассмотрим различные виды передачи переменных в функцию

// lvalue - объект, имеющий адрес
// rvalue - временный объект, не имеющий постоянного адреса, 
// нельзя передать его в функцию по ссылке
// && делает из временного объекта постоянный - ссылка на rvalue


// Функция test принимает lvalue как константную ссылку
int test(const int& a) {
    int b = 10;
    // a = b; // Ошибка компиляции, так как a - константная ссылка
    return ++a; // Возвращаем значение a, увеличенное на 1
}

int main() {
    // 1) int&
    int a = 1;
    std::cout << " a = " << test(a) << std::endl; // a может быть изменено и по выходу имеет другое значение
    std::cout << " a = " << test(1) << std::endl; // ошибка компиляции

    // 2) const int&
    int a = 1;
    std::cout << " a = " << test(a) << std::endl; // a не может быть изменено и по выходу имеет прежнее значение
    std::cout << " a = " << test(1) << std::endl; // OK

    // 3) int&&
    int a = 1;
    int b = 0;
    b = test(a);
    b = test(std::move(a));
    b = test(3);

    std::cout << " a = " << test(std::move(a)) << std::endl;

////////////////
// Сортировки //
////////////////

// O(N^2)      | Пузырек, 
//             | Вставками,
//             | Выбором
// -------------------------------------------------
// O(N*log(N)) | Быстрая (в неудачном случае O(N^2)) 
//             | Пирамидальная

// Идея - выбрать опорный элемент и сделать элементы слева меньшими, а элементы справа большими
// В качестве опорного выберается первый элемент - pivot, его положение - pivot point
//  
// func Quicksort (int* A, left, right)
//  if (left >= right)
//      return
//  pivot = Partition (A, left, right)
//  Quicksort (int* A, left, pivot-1)
//  Quicksort (int* A, pivot+1, right)
// 
// Возможны различне реализации в зависимости от разбиения
// 
// Разбиение Ломуто
// Выбираем опорный элемент (обычно первый элемент массива).
// Встретив при проходе по массиву элемент меньший опорного, смещаем и опорный элемент и вставляем туда меньший элемент
// Так слева от опорного элемента в конце его пути останутся только элементы меньше него
// Затем тоже самое для половин
// 
// func Partition_Lomuto (int* A, left, right)
//  pivot_value = A[left]
//  povit_point = left
//  for (int i = left+1; i <= right; i++)
//      if (pivot_value > A[i])
//        pivot_point++;
//      swap(A[i], A[pivot_point]);
//  swap(A[pivot_point], A[left]);
//  return pivot_point;

// Худший случай - когда массив отсортирован в обратную сторону
// Общее количестово S = (n-1)+(n-2)+(n-3)+(n-4)+...+1 = (n-1)(n-1+1)/2 = (n-1)n/2 = (n^2-n)/2 = O(n^2)
// 
// A(n) - количество действий
// A(1) = 1
// A(n) = n-1
// ...
// A(n) = A(n-1)/n + A(n-1)(n+1)/n - ркуррентная формула, ее решение A(n) = 1.44(n+1)log2(n)

// Разбиение Хоара
// По середине выбирается элемент. 
// Опорные элементы справа и слева идут на встречу друг другу
// Если левый указатель встречает элемент больше чем опроный он останавливается 
// Если правый встречает элемент меньший - он останавливается
// Когда оба встреили такие элементы они обмениваются местами.
// Затем тоже самое для половин
// 
// func Partition_Hoare(A, left, right)
//  pivot_value = A[(left+right)/2]
//  i = left
//  j = right
//  while (i <= j)
//      while (A[i] < pivot_value)
//         ++i;
//      while (A[j] > pivot_value)
//         --j;
//      if (i >= j) break;
//      swap(A[i], A[j]);
//      ++i;
//      --j;