#include <iostream>
#include <vector>

// Динамическое программирование - сведение сложной (оптимизационной) задачи к решению нескольких более простых
// Основано на двух вещах
//     перекрывающиеся подзадачи
//     оптимальность подзадачи
// Для решения требуется
//     понять состояние подзадачи, определить параметры ее задающие
//     определить начальное значение
//     определить формулу перехода между
//     определить порядок пересчета
//     определить положение конечного результата

// Яркий пример - числа Фибоначчи
// 0 1 1 2 3 5 8 
// f(n) = f(n-1) + f(n-2)

// Порядок пересчета
//     прямой порядок вычисляем текущее число на основе посчитанных
//     обратный порядок 
// Ленивая динамика

// const int n = 5;
// int f[n];

// int Fib(int i) {
//     if (i = 0) return 0;
//     if (i = 1) return 1;
//     f[i] = Fib(i-1);
//     f[i] += Fib(i-1);
// }

// int main() {
//     for (int i=0; i<n; i) {
//         f[i] = 0;
//     }

//     f[1] = 1;

//     Fib(n);

//     for (int i=0; i<n; i++) {
//         std::cout << f[i];
//     return 0;
// }

// Каждый раз мы перевычисляем элементы

// Поэтому когда мы посчитали подзадачу, ее можно запомнить

// int Fib(int i) {
//     if (i = 0) return 0;
//     if (i = 1) return 1;
//     if (f[i] != -1) return f[i];
//     else {
//         f[i] = Fib(i-1);
//         f[i] += Fib(i-1);
//     }
// }

// int main() {
//     for (int i=0; i<n; i) {
//         f[i] = -1;
//     }

//     f[0] = 0;
//     f[1] = 1;

//     Fib(n-1);

//     for (int i=0; i<n; i++) {
//         std::cout << f[i];
// }

// Рекрусивная меморищированная функция

// Задача с кузнечиком и лягушками

// Двумерная задача с черепахой количество вариантов маршрутов из врхнего левого в нижний правый 

// int func() {
//     for (int i=1; i<n; i++) {
//         for (int j=1; j<n; j++) {
//             f[i][j] = f[i-1][j] + f[i][j - 1];
//         }
//     }
//     return 0;
// }

// int main() {
//     const int n = 5;
//     int f[n][n];

//     for (int i=0; i<n; i++) {
//         f[i][0] = 1;
//         f[0][i] = 1;
//     }

//     for (int i=1; i<n; i++) {
//         for (int j=1; j<n; j++) {
//             f[i][j] = f[i-1][j] + f[i][j - 1];
//         }
//     }

//     for (int i=0; i<n; i++) {
//         for (int j=0; j<n; j++) {
//             std::cout << f[i][j] << " ";
//         }
//         std::cout << std::endl;
//     }
//     return 0;
// }

// Жадная черепашка - двумерная област заполненная монетами, нужно выбрать маршрут дающий больше всего монет

int f[5][4];
int path[5][4];

int max(int i, int j) {
  if (f[i - 1][j] > f[i][j - 1]) {
    path[i - 1][j] = 1;
    return f[i - 1][j];
  } else {
    path[i][j - 1] = 1;
    return f[i][j - 1];
  }
}

int main() {
  f[0][0] = 3;
  f[0][1] = 5;
  f[0][2] = 0;
  f[0][3] = 1;

  f[1][0] = 2;
  f[1][1] = 3;
  f[1][2] = 8;
  f[1][3] = 7;

  f[2][0] = 9;
  f[2][1] = 6;
  f[2][2] = 4;
  f[2][3] = 9;

  f[3][0] = 0;
  f[3][1] = 8;
  f[3][2] = 4;
  f[3][3] = 5;

  f[4][0] = 1;
  f[4][1] = 2;
  f[4][2] = 4;
  f[4][3] = 3;

  for (int i = 1; i < 5; i++)
    f[i][0] = f[i - 1][0] + f[i][0];

  for (int j = 1; j < 4; j++)
    f[0][j] = f[0][j - 1] + f[0][j];

  for (int i = 1; i < 5; i++) {
    for (int j = 1; j < 4; j++) {
      f[i][j] = f[i][j] + max(i, j);
    }
  }

  std::cout << f[4][3] << std::endl;

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      std::cout << path[i][j] << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}