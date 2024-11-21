#include <stdio.h>
#include <string.h>

typedef struct{
  char nama[50];
}nilaiMatkul;

typedef struct{
  int top;
  nilaiMatkul data[10];
}stack;

void createEmpty(stack *S);
int isEmpty(stack S);
int isFull(stack S);
void push(char nama[], stack *S);
void pop(stack *S);
void printStack(stack S, int tanda);
void popTo(stack *S, stack *T);