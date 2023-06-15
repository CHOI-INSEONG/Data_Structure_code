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
        SWAP(list[i], list[min], te mp);
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

//Quick Sort: Partitioning
int Partition(Data* list, int left, int right){
    int pivot = list[left], temp;
    int low = left + 1, high = right;

    while(1){
        while (low < right && list[low] < pivot){
            low++;
        }
        while(high > left && list[high] >= pivot){
            high--;
        }
        if(low < high){
            SWAP(list[low], list[high], temp);
        }
        else break;
    } 
    SWAP(list[left], list[high], temp);
    return high;
}

void QuickSort(Data* list, int left, int right){
    if (left < right){
        int mid = partition(list, left, right);

        QuickSort(list, left, mid - 1);

        QuickSort(list, mid + 1, right);
    }
}

void Merge(Data* list, int left, int mid, int right){
    int sorted[MAX_SIZE];
    int first = left, second = mid + 1, i = left;

    while(first <= mid && second <= right){
        if(list[first] <= list[second]){
            sorted[i++] = list[first++];
        }
        else{
            sorted[i++] = list[second++];
        }
    }
    if (first > mid){
        for (int j = second; j <= right; j++){
            sorted[i++] = list[j];
        }
    }
    else{
        for (int j = first j <= mid; j++){
            sorted[i++] = list[j];
        }
    }
    for(int j = left; j <= right; j++){
        list[j] = sorted[j];
    }

}

void MergeSort(Data* list, int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        MergeSort(list, left, mid);
        MergeSort(list, mid + 1, right);
        Merge(list, left, mid, right);
    }
}

//MergeSort: Iterative

void IterMergeSort(Data* list, int n){
    for(int size = 1; size <= n - 1; size = 2 * size){
        for(int left_start = 0; left_start < n - 1; left_start += 2 * size){
            int mid = left_satrt + size - 1;
            int right_end = MIN(left_start + 2 * size - 1, n - 1);

            Merge(list, left_start, mid, rigth_end);
        }
    }
}