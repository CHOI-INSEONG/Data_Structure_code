#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

typedef int Key;

typedef struct _RBNode{
    Key key;
    int red;
    struct _BSTNode* left_child;
    struct _BSTNode* right_child;
}RBNode;

