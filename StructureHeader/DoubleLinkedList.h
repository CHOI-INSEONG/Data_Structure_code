#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct _Node{
    Data item;
    struct _Node* next;
    struct _Node* prev;
}Node;

typedef struct{
    Node* head;
    int len;
}DoubleLinkedList;

void InitList(DoubleLinkedList* plist){
    Node* dummy1, *dummy2;
    dummy1 = (Node*)malloc(sizeof(Node));
    dummy2 = (Node*)malloc(sizeof(Node));
    dummy1->prev = NULL;
    dummy1->next = dummy2;
    dummy2->prev = dummy1;
    dummy2->next = NULL;

    plist->head = dummy1;
    plist->len = 0;
}

bool IsEmpty(DoubleLinkedList* plist){
    return plist->len == 0;
}

void InsertMiddle(DoubleLinkedList* plist,int pos, Data item){
    Node* cur = plist->head;
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->item = item;
    newnode->prev = NULL;
    newnode->next = NULL;
    for(int i = 0; i < pos; i++){
        cur = cur->next;
    }

    newnode->item = item;
    newnode->prev = cur;
    newnode->next = cur->next;
    cur->next->prev = newnode;
    cur->next = newnode;
    plist->len++;
}

void RemoveItem(DoubleLinkedList* plist, int pos){
    Node* cur, *temp;
    if(IsEmpty(plist) || pos < 0 || pos >= plist->len){
        exit(1);
    }
    cur = plist->head;
    for(int i = 0;i < pos; i++){
        cur = cur->next;
    }
    temp = cur->next;
    temp->next->prev = cur;
    cur->next = temp->next;
    
    plist->len--;
    free(temp);
}

Data ReadItem(DoubleLinkedList* plist, int pos){
    Node* cur = plist->head;
    for(int i = 0; i < pos; i++){
        cur = cur->next;
    }
    return cur->item;
}


