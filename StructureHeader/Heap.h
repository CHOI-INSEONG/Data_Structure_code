#include <stdio.h>
#include <stdlib.h>
#define MAX_HEAP 100

typedef char Data;

typedef struct{
    Data data;
    int priority;
}HNode;

typedef truct{
    HNode items[MAX_HEAP + 1];
    int item;
}Heap;

void InitHeap(Heap* pheap);
bool IsEmpty(Heap* pheap);
bool IsFull(Heap* pheap);

void Insert(Heap* pheap, Data data, int priority);
Data Delete(Heap* pheap);

int GetParent(int idx);
int GetLChild(int idx);
int GetRChild(int idx);
int GetHighPriorityChild(Heap* pheap, int idx);

void InitHeap(Heap* pheap){
    pheap->num = 0;
}

bool IsEmpty(Heap* pheap){
    return pheap->num == 0;
}

bool IsFull(Heap* pheap){
    return pheap->num == MAX_HEAP;
}

void Insert(Heap *pheap, Data data, int priority){
    HNode newNode;
    int idx = pheap->num + 1;
    if (ISFull(pheap)){
        exit(1);
    }
    while (idx > 1){
        int parent = GetParent(idx);
        if (priority > pheap->items[parent].priority){
            pheap->items[idx] = pheap->items[parent];
            idx = parent;
        }
        else{
            break;
        }
    }
    newNode.data = data;
    newNode.priority = priority;

    pheap->items[idx] = newNode;
    pheap->num++;
}

Data Delete(Heap* pheap){
    Data max = pheap->items[1].data;
    HNode last = pheap->items[pheap->num];
    int parent = 1, child;

    while(child = GetHighPriorityChild(pheap, parent)){
        if(last.priority < pheap->items[child].priority){
            pheap->items[parent] = pheap->items[child];
            parent = child;
        }
        else break;
    }
    pheap->items[parent] = last;
    pheap->num--;

    return max;
}

int GetHighPriorityChild(Heap* pheap, int idx){
    if(GetLChild(idx) > pheap->num){
        return 0;
    }
    else if (GetLChild(idx) == pheap->num){
        return GetLChild(idx);
    }
    else{
        int left = GetLChild(idx), right = GetRChild(idx);
        if(pheap->items[left].priority > pheap->items[right].priority){
            return left;
        }
        else{
            return right;
        }
    }
}

int Getparent(int idx){
    return idx / 2;
}

int GetLChild(int idx){
    return idx * 2;
}

int GetRChild(int idx){
    return idx * 2 + 1;
}




























