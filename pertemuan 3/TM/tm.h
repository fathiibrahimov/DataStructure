#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{//bungkusan untuk isi datanya
	char nama[100];
	char rumus[100];
	char konsentrasi[10];
}nilaiMatKul;

typedef struct elmt* alamatelmt;
typedef struct elmt{//bungkusan untuk linked listnya
	nilaiMatKul kontainer;
	alamatelmt next;
}elemen;

typedef struct{//untuk headnya
	elemen* first;
}list;

void createList (list *L);//prosedur untuk membuat list
int countElement(list L);//prosedur untuk menghitung jumlah element di list
void addFirst(char nama[], char rumus[], char konsentrasi[], list *L);//prosedur untuk menambahkan isi list di awal
void addAfter(elemen* prev, char nama[], char rumus[], char konsentrasi[], list *L);//prosedur untuk menambahkan isi list setelah
void addLast(char nama[], char rumus[], char konsentrasi[], list *L);//prosedur untuk menambahkan isi list di akhir
void delFirst(list *L);//prosedur untuk menghapus di awal
void delAfter(elemen* prev, list *L);//prosedur untuk menghapus list setelah
void delLast(list *L);//prosedur untuk menghapus list di akhir
void printElement(list L);//prosedur untuk mencetak isi list
void delAll(list *L);//prosedur untuk menghapus semua isi list
