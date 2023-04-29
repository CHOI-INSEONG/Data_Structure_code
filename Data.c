#include <stdio.h>
#define MAX_QUEUE 10
typedef int BData;

// Binary트리를 만들기 위한 구조체 선언
typedef struct _bTreeNode{
    BData item;
    struct _bTreeNode* left_child;
    struct _bTreenode* right_child;
}BTreeNode;

typedef struct {
    int rear;
    int front;
    Data items[MAX_QUEUE];
}Queue;

void InitQueue(Queue* queue) {
    queue->front = queue->rear = 0;
}

bool IsFull(Queue* queue) {
    return queue->front == (queue->rear + 1) % MAX_QUEUE;
}

bool IsEmpty(Queue* queue) {
    return queue->front == queue->rear;
}

Data peek(Queue* queue) {
    if (IsEmpty(queue)) {
        exit(1);
    }
    else {
        return queue->items[queue->front];
    }
}

void EnQueue(Queue* queue, Data item){
    if (IsFull(queue)) {
        exit(1);
    }
    else {
        queue->items[queue->rear] = item;
        queue->rear = (queue->rear + 1) % MAX_QUEUE;
    }
}

void DeQueue(Queue* queue) {
    if (IsEmpty(queue)) {
        exit(1);
    }
    else {
        queue->front = (queue->front + 1) % MAX_QUEUE;
    }
}
//Inorder방식(LCR)
void Inorder(BTreeNode* root){
    if (root != NULL){ 
        Inorder(root->left_child); //먼저 트리의 left subtree부터 탐색함.(L)
        printf("%d ", root->item);  //(C)
        Inorder(root->right_child); // 트리의 left subtree 탐색이 끝나면, right subtree를 탐색함.(R)
    }
}

//Preorder방식(CLR)
void Preorder(BTreenode* root){
    if(root != NULL){
        printf("%d ", root->item); //(C)
        Preorder(root->left_child); //트리의 left subtree를 탐색함
        Preorder(root->right_child); // 트리의 right subrtree를 탐색함
    }
}

//Postorder방식(LRC)
void Postorder(BTreeNode* root){
    if(root != NULL){
        Postorder(root->left_child); //트리의 left subtree를 탐색함(L)
        Postorder(root->right_child); //트리의 right subtree를 탐색함(R)
        printf("%d ", root->item); // (C)
    }
}

void LevelOrder(BTreeNode* root){
    Queue queue;
    if(root == NULL) return;
    
    InitQueue(&queue);
    EnQueue(&Queue, root);
    while(!IsEmpty(&queue)){
        root = Peek(&queue);
        DeQueue(&queue);

        printf("%d ", root->item);
        if(root->left_child != NULL) Enqueue(&queue, root->left_child);
        if(root->right_child != NULL) EnQueue(&queue, root->right_child);
    }
}



int main(){

}