#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
	char nama[50];
	char nilai[10];
}nilaiMatKul;

typedef struct elm *alamatelmt;
typedef struct elm{
	nilaiMatKul kontainer;
	alamatelmt next;
	int prioritas;
}elemen;

typedef struct{
	elemen *first;
	elemen *last;
}queue;

void createEmpty(queue *Q);
int isEmpty(queue Q);
int countElement(queue Q);
void add(char nama[], char nilai[], queue *Q );
void addpriority(char nama[], char nilai[], int prioritas, queue *Q );
void del(queue *Q, queue *R);
void printQueue(queue Q);
void printQueue2(queue Q);