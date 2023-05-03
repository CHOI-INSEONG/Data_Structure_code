#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> // strtok함수를 이용하기 위해
#include "Stack.h"
// 추가로 헤더파일이 필요한 경우 자유롭게 추가해도 됩니다.

#define MAX_LEN	100

// 입력받은 문자열을 반대로 저장하기 위해 스택에 저장하는 함수
Stack Reverse(char* expression) {
    Stack temp;
    InitStack(&temp, MAX_LEN);
    char* ptr = strtok(expression, " "); // strtok 함수를 이용해 띄어쓰기를 기준으로 문자열을 나눔
    while (ptr != NULL) {
        // 입력에는 음수가 들어오지 않기 때문에 char형인 사칙연산을 double형인 stack에 저장하기 위해 음수로 표현
        if (*ptr == '+' || *ptr == '-' || *ptr == '*' || *ptr == '/') {
            if (*ptr == '+') Push(&temp, -1);
            if (*ptr == '-') Push(&temp, -2);
            if (*ptr == '*') Push(&temp, -3);
            if (*ptr == '/') Push(&temp, -4);
            ptr = strtok(NULL, " ");
        }
        else {
            double a = atof(ptr); // atof함수를 이용해 분리한 char형의 문자열을 double형으로 바꿈
            Push(&temp, a);
            ptr = strtok(NULL, " ");
           
        }
    }
    return temp;
}

//실제로 계산하는 함수
void calculate(Stack* temp,Stack* prefix, double expr) {
    double a = 0, b = 0;
    // 두 개의 스택 stack1과 stack2가 있을 때, stack1은[숫자, 부호], stack2는 [숫자]가 남는 상황을 계산하기 위해 들어가는 if문입니다.
    if (Peek(temp) > 0 && prefix->top == 0) { 
        b = Peek(temp);
        Pop(temp);
    }
    else {
        b = Peek(prefix);
        Pop(prefix);
    }
    a = Peek(prefix);
    Pop(prefix);
    // 사칙연산을 음수로 저장해놓았기 때문에 그것에 맞춰 계산을 진행합니다.
    if (expr == -1) {
        Push(prefix, a + b);
    }
    if (expr == -2) {
        Push(prefix, b - a);
    }
    if (expr == -3) {
        Push(prefix, a * b);
    }
    if (expr == -4) {
        Push(prefix, b / a);
    }
}

double prefix_calculate(char* expression) {
    Stack temp, prefix;

    InitStack(&temp, MAX_LEN);
    InitStack(&prefix, MAX_LEN);
    //입력받은 expression을 뒤집어 temp라는 스택에 저장합니다.
    temp = Reverse(expression);
    // temp의 값이 사라질 때 까지 반복합니다.
    while (temp.top != -1) {
        double peeker = Peek(&temp); //temp의 값을 가져옵니다.
        Pop(&temp);
        //가져온 temp의 값이 음수(부호)라면 계산을 하고, 음수가 아니라면 prefix스택에 저장합니다.
        if (peeker < 0) {
            calculate(&temp , &prefix, peeker);
        }
        else {
            Push(&prefix, peeker);
        }
    }
    //계산이 끝난 결과를 리턴합니다.
    return Peek(&prefix);

}

int main() {

    // 아래 main 함수는 수정하지 마세요. 
    char expression[MAX_LEN];
    // 개행문자를 제외한 모든 사용자 입력을 받는다는 의미입니다.
    scanf("%[^\n]", expression);

    double result = prefix_calculate(expression);
    printf("%.2lf\n", result);

    return 0;
}
