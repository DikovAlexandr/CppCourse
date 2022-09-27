#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

void printMatrix(int ***arr){
    int xIndex = 3, yIndex = 3, zIndex = 3;
    for(int z=0;z<zIndex;z++) {
        for(int y=0;y<yIndex;y++) {
            for(int x=0;x<xIndex;x++)
                if (arr[z][y][x]<10) cout << " " << arr[z][y][x] << " ";
                else cout << arr[z][y][x] << " ";
            cout << endl;
        }
        cout << "--------" << endl;
    }
}

int main(){
    // Введем размарность матрицы
    int xIndex = 3, yIndex = 3, zIndex = 3;

    int ***arr = new int**[xIndex];
    for(int i=0; i<xIndex; i++){
        arr[i] = new int*[yIndex];

        for(int j=0; j<yIndex;j++){
            arr[i][j] = new int[zIndex];
        }
    }
    // Заполняем массив в прямом направлении
    int value=1;
    for(int z=0;z<zIndex;z++)
        for(int y=0;y<yIndex;y++)
            for(int x=0;x<xIndex;x++){
                arr[z][y][x] = value;
                value++;
            }
    printMatrix(arr);
    cout << "Alternative index order" << endl
        << "--------" << endl;
    value=1;
    // Заполняем массив в обратном направлении
    for(int z=zIndex-1;z>=0;z--)
        for(int y=yIndex-1;y>=0;y--)
            for(int x=xIndex-1;x>=0;x--){
                arr[z][y][x] = value;
                value++;
            }
    printMatrix(arr);
    free(arr);
    return 0;
}