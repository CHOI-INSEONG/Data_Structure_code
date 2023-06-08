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

void BubbleSort(Data* list, int n){
    int temp;
    for (int i = n-1; i > 0; i--){
        for (int j = 0; j < i; j++){
            if(lsit[j] > list[j+1]){
                SWAP(list[j], list[j + 1], temp);
            }
        }
    }
}

void InsertionSort(Data* list, int n){
    int j, key;
    for (int i = 1; i < n; i++){
        key = list[i];
        for (j = i - 1; j >= 0; j--){
            if(key < list[j]){
                list[j + 1] = list[j];
            }
            else{
                break;
            }
        }
        list[j + 1] = key;
    }
}