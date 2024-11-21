#include <stdio.h>
#include <malloc.h>
#include <string.h>

int n, m;//buat banyak elemen 2 list
char temp3[100][100];//buat nampung yang mau dipindah

typedef struct{
	char makan[100];
	int harga;
}nilaiMatKul;

typedef struct elmt* alamatelmt;
typedef struct elmt{
	nilaiMatKul kontainer;
	alamatelmt next;
}elemen;

typedef struct{
	elemen* first;
}list;

void createList (list *L);//buat membuat list
int countElement(list L);//buat menghitung jumlah elemen
void addFirst(char  makan[], int harga, list *L);//buat menambah elemen di awal
void addAfter(elemen* prev, char  makan[], int harga, list *L);//buat menambah elemen setelah
void addLast(char  makan[], int harga, list *L);//buat menambah elemen di akhir
void delFirst(list *L);//buat menghapus elemen di awal
void delAfter(elemen* prev, list *L);//buat menghapus elemen setelah
void delLast(list *L);//buat menghapus elemen terakhir
void printElement(list L);//buat print semua elemen
void delAll(list *L);//buat menghapus semua elemen
void pindahin(list *L, list *K);//buat pindahin

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Quiz 1 dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/