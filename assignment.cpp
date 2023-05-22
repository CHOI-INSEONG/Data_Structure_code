#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_URL_LENGTH	21

// DO NOT MODIFY //
struct Node {
    char url[MAX_URL_LENGTH];
    struct Node* prev;
    struct Node* next;
};

typedef struct {
    struct Node* head;
    struct Node* cursor;
} BrowserHistory;
// DO NOT MODIFY //


BrowserHistory* browserHistoryCreate(char* homepage) {
    BrowserHistory* root = (BrowserHistory*)malloc(sizeof(BrowserHistory));
    struct Node* history = (struct Node*)malloc(sizeof(struct Node));
    root->cursor = history;
    root->head = history;
    history->next = NULL;
    history->prev = NULL;
    strcpy(history->url, homepage);
    return root;
}

void browserHistoryVisit(BrowserHistory* obj, char* url) {
    struct Node* newhistory = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newhistory->url, url);//�� ����
    obj->cursor->next = newhistory;
    newhistory->prev = obj->cursor;
    newhistory->next == NULL;
    obj->cursor = newhistory;
}

char* browserHistoryBack(BrowserHistory* obj, int steps) {
    while (steps != 0) {
        if (obj->cursor->prev == NULL) {
            return obj->cursor->url;
        }
        obj->cursor = obj->cursor->prev;
        steps--;
    }
    return obj->cursor->url;
}

char* browserHistoryForward(BrowserHistory* obj, int steps) {
    while (steps != 0) {
        if (obj->cursor->next == NULL) {
            return obj->cursor->url;
        }
        obj->cursor = obj->cursor->next;
        steps--;
    }
    return obj->cursor->url;
}


void browserHistoryFree(BrowserHistory* obj) {
    struct Node* temp;
    temp = obj->head;
    free(temp);
}

// DO NOT MODIFY //
int main() {
    int i = 0, count = 0;
    char arg1[500];
    char arg2[500];
    char cmd[100][500];
    char parm[100][500];
    char output[100][500];

    fgets(arg1, 500, stdin);
    fgets(arg2, 500, stdin);
    if (arg1[strlen(arg1) - 1] == '\n') {
        arg1[strlen(arg1) - 1] = '\0';
    }
    if (arg2[strlen(arg2) - 1] == '\n') {
        arg2[strlen(arg2) - 1] = '\0';
    }
    char* token = strtok(arg1, " "); // �������� ���ڿ� ������

    while (token != NULL) {
        strcpy(cmd[i], token); // ���� ���ڿ��� �迭�� �����ϱ�
        token = strtok(NULL, " ");
        i++;
    }

    count = i;

    i = 0;
    token = strtok(arg2, " "); // �������� ���ڿ� ������
    while (token != NULL) {
        strcpy(parm[i], token); // ���� ���ڿ��� �迭�� �����ϱ�
        token = strtok(NULL, " ");
        i++;
    }


    BrowserHistory* obj;

    obj = browserHistoryCreate(parm[1]);
    for (i = 0; i < count; i++) {
        if (strcmp(cmd[i], "BrowserHistory") == 0) {
            obj = browserHistoryCreate(parm[i]);
        }
        else if (strcmp(cmd[i], "visit") == 0) {
            browserHistoryVisit(obj, parm[i]);
        }
        else if (strcmp(cmd[i], "back") == 0) {
            printf("%s ", browserHistoryBack(obj, atoi(parm[i])));
        }
        else if (strcmp(cmd[i], "forward") == 0) {
            printf("%s ", browserHistoryForward(obj, atoi(parm[i])));
        }
    }
    browserHistoryFree(obj);
    return 0;
}
// DO NOT MODIFY //