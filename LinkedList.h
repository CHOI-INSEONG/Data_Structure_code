#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct _Node{
    Data item;
    struct _Node* next;
}Node;

typedef struct{
    Node* head;
    int len;
}LinkedList;

void InitList(LinkedList* plist){
    plist->head = (Node*)malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->len = 0;
}

bool IsEmpty(LinkedList* plist){
    return plist->len == 0;
}

void InsertMiddle(LinkedList* plist,int pos, Data item){
    Node* cur = plist->head;
    Node* newnode = (Node*)malloc(sizeof(Node));
    for(int i = 0; i < pos; i++){
        cur = cur->next;
    }
    newnode->item = item;
    newnode->next = cur->next;
    cur->next = newnode;
    plist->len++;
}

void RemoveItem(LinkedList* plist, int pos){
    Node* cur, *temp;
    if(IsEmpty(plist) || pos < 0 || pos >= plist->len){
        exit(1);
    }
    cur = plist->head;
    for(int i = 0;i < pos; i++){
        cur = cur->next;
    }
    temp = cur->next;
    cur->next = temp->next;
    plist->len--;
    free(temp);
}

Data ReadItem(LinkedList* plist, int pos){
    Node* cur = plist->head;
    for(int i = 0; i < pos; i++){
        cur = cur->next;
    }
    return cur->item;
}


