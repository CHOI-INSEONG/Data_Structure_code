#include <stdio.h>
#include <stdlib.h>

typedef int Key;
typedef struct _BSTNode{
    Key key;
    struct _BSTNode* left_child;
    struct _BSTNode* right_child;
}BSTNode;

bool Verify(BSTNode* root, int min, int max){
    if(root != NULL){
        if(root->key <= min || root->key => max){
            return false;
        }
        else{
            return Verify(root->left_child, min, root->key) && Verify(root->right_child, root->key, max);
        }
    else{
        return ture;
    }
    }
}

//BST Search (Recursive Ver.)
BSTNode* Search(BSTNode* root, Key key){
    if(root == NULL || root->key == key) return root;
    else if(root->key > key){
        return Search(root->left_child, key);
    }
    else{
        return Search(root->right_child, key);
    }
}

//BST Search (Iterative Ver.)
BSTNode* Search(BSTNode* root, Key key){
    BSTNode* cur = root;
    whiel(cur != NULL){
        if(cur->key == key) break;
        else if(cur->key > key){
            cur = cur->left_child;
        }
        else{
            cur = cur->right_child;
        }
        return cur;
    }
}



































