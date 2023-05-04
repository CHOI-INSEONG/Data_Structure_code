#include "Queue.h"
#include "Stack.h"
typedef int BData;




typedef struct _bTreeNode{
    BData item;
    struct _bTreeNode* left_child;
    struct _bTreenode* right_child;
}BTreeNode;

//Inorder
void Inorder(BTreeNode* root){
    if (root != NULL){ 
        Inorder(root->left_child); 
        printf("%d ", root->item);  
        Inorder(root->right_child); 
    }
}

//Preorder
void Preorder(BTreeNode* root){
    if(root != NULL){
        printf("%d ", root->item); 
        Preorder(root->left_child); 
        Preorder(root->right_child); 
    }
}

//Postorder(LRC)
void Postorder(BTreeNode* root){
    if(root != NULL){
        Postorder(root->left_child); 
        Postorder(root->right_child); 
        printf("%d ", root->item); 
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


//Use Postorder Traversal
int CalDirectorySize(BTreeNode* root){
    int left_size, right_size;
    if(root == NULL) return 0;
    else{
        left_size = CalDirectorySize(root->left_child);
        right_size = CalDirectorySize(root->right_child);
        return (root->item + left_size + right_size);
    }
    
}





int main(){
    
}