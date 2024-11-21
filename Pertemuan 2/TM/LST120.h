#include <stdio.h>
#include <string.h>

int n;

typedef struct{
	char nama[100];
	char gender;
	int umur;
}daftarMaha;

typedef struct{
	daftarMaha kontainer;
	int next;
}elemen;

typedef struct{
	int first;
	elemen data[100];
}list;

void createList (list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(char nama[], char gender, int umur, list *L);
void addAfter(int prev, char nama[], char gender, int umur, list *L);
void addLast(char nama[], char gender, int umur, list *L);
void delFirst(list *L);
void delAfter(int prev, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);
