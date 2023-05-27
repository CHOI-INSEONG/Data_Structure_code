#include <stdio.h>
#include <stdlib.h>
#include Te

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

//BST Inserting (Recursive Ver.)
void Insert(BSTNode* root, Key key){
    if(root->key == key) exit(1);
    else if(root->key > key){
        if(root->left_child == NULL){
            CreateLeftSubTree(root, key);
        }
        else{
            Insert(root->left_child, key);
        }
    }
    else{
        if(root->right_child == NULL){
            CreateRightSubtree(root, key);
        }
        else{
            Insert(root->right_child, key);
        }
    }
}

//BST Inserting (Iterative Ver.)
void Insert(BSTNode* root, Key key){
    BSTNode* cur = root;
    while(cur != NULL){
        if(cur->key == key) exit(1);
        else if(cur-> key > key){
            if(cur-.left_child == NULL){
                CreateLeftSubtree(cur, key);
                break;
            }
            else{
                cur = cur->left_child
            }
        }
        else{
            if(cur->right_child == NULL){
                CreateRightSubtree(cur, key);
                break;
            }
            else{
                cur = cur->right_child;
            }
        }
    }
    
}

//BST Removing (Recursive Ver.)
BSTNode* remove(BSTNode* root, Key key){
    if(root == NULL) return NULL;

    if(key < root->key){
        root->left_child = remove(root->left_child, key);
    }
    else if(key > root->key){
        root->right_child = remove(root->right_child, key);
    }
    else{
        BSTNode* cur = root;
        if(root->left_child == NULL && root->right_child == NULL){
            DestroyNode(cur);
            root = NULL;
        }
        else if(root->left_child == NULL || root->right_child == NULL){
            if(root->left_child != NULL){
                root = root->left_child;
                DestroyNode(cur);
            }
            else{
                root = root->right_child;
                DestroyNode(cur);
            }
        }
        else{
            cur = cur->right_child;
            while(cur->left_child != NULL){
                cur = cur->left_child;
            }
            root->key = cur->key;
            root->right_child = remove(root->right_child, cur->key);
        } 
    }
    return root;
}






























