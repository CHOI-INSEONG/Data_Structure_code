#include <stdio.h>

typedef int BData;

// Binary트리를 만들기 위한 구조체 선언
typedef struct _bTreeNode{
    BData item;
    struct _bTreeNode* left_child;
    struct _bTreenode* right_child;
}BTreeNode;
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
int main(){

}