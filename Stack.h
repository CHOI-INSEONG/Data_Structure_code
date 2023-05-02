#include <stdio.h>
#include <iostream>
#define MAX_STACK 10
typedef int DATA;

typedef struct{
    DATA items[MAX_STACK];
    int top = -1;
}Stack;

void InitStack(Stack* pstack) {
    pstack->top = -1;
}

bool IsFull(Stack* pstack) {
    return pstack->top == MAX_STACK - 1;
}

bool IsEmpty(Stack* pstack) {
    return pstack->top == -1;
}
DATA Peek(Stack* pstack) {
    return pstack->items[pstack->top];
}
void Push(Stack* pstack, DATA item) {
    if (IsFull(pstack)) {
        exit(1);
    }
    else {
        pstack->top++;
        pstack->items[pstack->top] = item; //pstack->items[++(pstack->top)] = item;으로도 쓸 수 있음
    }
}
void Pop(Stack* pstack) {
    if (IsEmpty(pstack)) {
        exit(1);
    }
    else {
        pstack->top--; //--(pstack->top);으로도 쓸 수 있음
    }
}
