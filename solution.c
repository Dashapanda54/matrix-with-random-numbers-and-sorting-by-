#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 100

int prov(int lim,int mas[],int digit);
 
int main() {
    int n, i, j;
    printf("Введите количество массивов: ");
    scanf("%d", &n);
    int AllMas[size][size] = {};
    int mas[size] = {}; 
    srand(time(NULL));
    for (i = 0; i < n; i++){
        do {
            mas[i] = 1 + rand() % n + 10;
        } while(prov(i, mas, mas[i]));
        
        for (j = 0; j < mas[i]; j++) {
            AllMas[i][j] = rand() % 100 + 1;
        }
        if (i % 2 == 0){
            for (j = 0; j < mas[i]; j++) {
                int imin = j;
                for (int k = j + 1; k < mas[i]; ++k) {
                    if (AllMas[i][k] > AllMas[i][imin])
                        imin = k;
                }
                if (imin != j) {
                    int tmp = AllMas[i][j];
                    AllMas[i][j] = AllMas[i][imin];
                    AllMas[i][imin] = tmp;
                }
                printf("%d ", AllMas[i][j]);
            }
        } else {
             for (j = 0; j < mas[i]; j++) {
                int imin = j;
                for (int k = j + 1; k < mas[i]; ++k) {
                    if (AllMas[i][k] < AllMas[i][imin])
                        imin = k;
                }
                if (imin != j) {
                    int tmp = AllMas[i][j];
                    AllMas[i][j] = AllMas[i][imin];
                    AllMas[i][imin] = tmp;
                }
                printf("%d ", AllMas[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}

int prov(int lim,int mas[],int digit){
    int i;
    for(i = 0; i < lim; i++)
        if(mas[i] == digit)
            return 1;
    return 0;
}