#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST 10


typedef int Data;

void SelectionSort(Data* list, int n){
    int min, temp;
    for (int i = 0; i < n; i++){
        min = i;
        for (int j = i + 1; j < n; j++){
            if(list[j] < list[min])
        }
        SWAP(list[i], list[min], temp);
    }
}