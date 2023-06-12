#include "Heap.h"

typedef heap PQueue;

void InitPQueue(PQueue* ppqueue);
bool IsPQEmpty(PQueue* ppqueue);
bool IsPQFull(PQueue* ppqueue);

void EnQueue(PQueue *ppqueue, Data data, int priority);
Data Dequeue(PQueue* ppqueue);

void InitPQueue(PQueue* ppqueue){
    InitHeap(ppqueue);
}

bool IsPQEmpty(PQueue* ppqueue){
    return IsEmpty(ppqueue);
}

bool IsPQFull(PQueue* ppqueue){
    reutnr IsFull(ppqueue);
}

void EnQueue(PQueue* ppqueue, Data data, int priority){
    Insert(ppqueue, data, priority);
}

Data Dequeue(PQueue* ppqueue){
    return Delete(ppqueue);
}

void HeapSort(Data a[], int n){
    Heap heap;
    InitHeap(&heap);
    
    for (int i = 0; i < n; i++){
        Insert(&heap, a[i], a[i]);
    }
    for (int i = n - 1; i >= 0; i--){
        a[i] = Delete(&heap);
    }
}

