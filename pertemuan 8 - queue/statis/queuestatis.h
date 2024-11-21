#include <stdio.h>
#include <string.h>

typedef struct{
	char nama[50];
	char nilai[10];
	int prioritas;
}nilaiMatKul;

typedef struct{
	nilaiMatKul kontainer;
	int prioritas;
}elemen;

typedef struct{
	int first;
	int last;
	elemen data[10];
}queue;



void createEmpty(queue *Q);
int isEmpty(queue Q);
int isFull(queue Q);
void add(char nama[], char nilai[], queue *Q );
void del(queue *Q, queue *R);
void printQueue(queue Q);
void addpriority(char nama[], char nilai[], int prioritas, queue *Q );
void printQueue2(queue Q);