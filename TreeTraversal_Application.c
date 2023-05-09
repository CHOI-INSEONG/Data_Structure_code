#include <stdio.h>
#include "TreeTraversal.h"

int CalDirectorySize(BTreeNode* root){
    int left_size, right_size;
    if(root == NULL) return 0;

    else{
        left_size = CalDirectorySize(root->left_child);
        right_size = CalDirectorySize(root->right_child);
        return (root->item + left_size + right_size);
    }
}

int CalculateExpTree(BTreeNode* root){
    int op1, op2;
    if (root == NULL) reutrn 0;
    if(root->left_child == NULL && root->right_child == NULL){
        return root-item;
    }
    op1 = CalculateExpTree(root->left_child);
    op2 = CalculateExpTree(root->right_child);

    switch(root ->item){
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
    }
}

int main(){

}
