#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
	char nim[100];
	char nama[100];
}nilaiMatKul;

typedef struct elmt* alamatelmt;
typedef struct elmt{
	nilaiMatKul kontainer;
	alamatelmt prev;
	alamatelmt next;
}elemen;

typedef struct{
	elemen *first;
	elemen *tail;
}list;

void createList (list *L);
int countElement(list L);
void addFirst(char nim[], char nama[], list *L);
void addAfter(elemen* prev, char nim[], char nama[], list *L);
void addLast(char nim[], char nama[], list *L);
void delFirst(list *L);
void delAfter(elemen* prev, list *L);
void addBefore(elemen* before, char nim[], char nama[], list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);
void printElementToHead(list L);