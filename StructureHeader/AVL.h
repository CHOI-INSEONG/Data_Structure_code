#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

int GetBalancingFactor(BSTNode* root){
    if(root == NULL) return 0;
    return GetHeight(root->right_child) - GetHeight(root->left_child)
}

BSTNode* Rebalance(BSTNode* root){
    int factor = GetBalancingFactor(root);
    if(factor < -1){
        if(GetBalancingFactor(root->left_child) < 0){
            root = LLrotation(root);
        }
        else{
            root = LRrotation(root);
        }
    }
    else if(factor > 1){
        if(GetBalancingFactor(root.right_child) > 0){
            root = RRrotation(root);
        }
        else{
            root = RLrotation(root);
        }
    }
    return root;
}

BSTNode* Insert(BSTNode* root, Key key){
    if(root == NULL){
        return CreateNode(key);
    }
    if(key < root->key){
        root->left_child = Insert(root->left_child, key);
        root = Rebalance(root);
        return root;
    }
    else if(key > root->key){
        root->right_child = Insert(root->right_child, key);
        root = Rebalance(root);
        return root;
    }
    else{
        exit(1);
    }
}