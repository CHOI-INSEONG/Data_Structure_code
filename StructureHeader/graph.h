#include <stdio.h>
#include <stdlib.h>

typedef struct _GNode{
    int id;
    struct _GNode next;
}GNode;

typedef struct 
{
    int num;
    GNode** heads;
}Graph;


void CreateGraph(Graph* pgraph, int num);
void DestroyGraph(Graph* pgraph);
void AddEdge(Graph* pgraph, int src, int dest);
void PrintGraph(Graph* pgraph);

void DFS(Graph* pgraph);
void BFS(Graph* pgraph);

void CreateGraph(Graph* pgraph, int num){
    pgraph->num = num;
    pgraph->heads = (GNode **)malloc(sizeof(GNode *) * num);
    for (int i = 0; i < num; i++){
        pgraph->heads[i] = (GNode *)malloc(sizeof(GNode));
        pgraph->heads[i]->next = NULL;
    }
}

void DestroyGraph(Graph* pgraph){
    for (int i = 0; i < pgraph->num; i++){
        GNode* cur = pgraph->heads[i];
        while(cur != NULL){
            GNode* temp = cur;
            cur = cur->next;
            free(temp);
        }
    }
    free(pgraph->heads);
}




void AddEdge(Graph* pgraph, int src, int dest){
    GNode* newNode1, *newNode2, *cur;

    newNode1 = (GNode* )malloc(sizeof(GNode));
    newNode1->id = dest;
    newNode1->next = NULL;

    cur = pgraph->heads[src];
    
}



























