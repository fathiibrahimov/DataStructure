#include <stdio.h>
#include <string.h>

int n;

typedef struct{
	char nama[100];
}nilaiMatKul;

typedef struct{
	nilaiMatKul kontainer;
	int prev;
	int next;
}elemen;

typedef struct{
	int first;
	int tail;
	elemen data[100];
}list;

void createList (list *L);//untuk membuat list
int countElement(list L);//menghitung elemen di list
int emptyElement(list L);//memuat elemen kosong
void addFirst(char nama[], list *L);//menambah elemen di awal
void addAfter(int before, char nama[], list *L);//menambah elemen setelah
void addLast(char nama[], list *L);//menambah elemen di akhir
void delFirst(list *L);//menghapus elemen di awal
void delAfter(int before, list *L);//menghapus elemen setelah
void delLast(list *L);//menghapus elemen di akhir
void printElement(list L);//mencetak elemen
void delAll(list *L);//menghapus semua elemen
void carisama(list L);//mencari palindromnya

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Quiz 1 dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/