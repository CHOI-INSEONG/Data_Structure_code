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

BSTNode* LLrotation(BSTNode* parent){
    BSTNode* child = parent->left_child;
    parent->left_child = child->right_child;
    child->right_child = parent;
    return child;
}

BSTNode* RRrotation(BSTNode* parent){
    BSTNode* child = parent->right_child;
    parent->right_child = child->left_child;
    child->left_child = parent;
    return child;
}

BSTNode* LRrotaiton(BSTNode* parent){
    BSTNode* child = parent->left_child;
    parent->left_child = RRrotation(child);
    return LLrotation(parent);
}

BSTNode* RLrotation(BSTNode* parent){
    BSTNode* child = parent->right_child;
    parent->right_child = LLrotation(child);
    return RRrotation(parent);
}

BSTNode* Remove(BSTNode* root, Key key){
    if(key < root->key){
        root->left_child = Remove(root->left_child, key);
    }
    else if(key > root->key){
        root->right_child = Remove(root->right_child, key);
    }
    else{
        if(root->left_child == NULL && root->right_child == NULL){

        }
        else if(root->left_child == NULL || root->right_child == NULL){

        }
        else{
            root->right_child = Remove(root->right_child, cur->key)
        }
    }
    return root;
}

























