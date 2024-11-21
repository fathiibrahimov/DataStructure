#include <stdio.h>
#include <malloc.h>
#include <string.h>

int n;
int m;
char temp4[100][100];//tampungan nama
int temp5[100];//tampungan tahun

typedef struct{
	char jenis[100];
	int tahun;
}besar;

typedef struct{
	char nama[100];
}kecil;

typedef struct eklm *alamatekolom;
typedef struct eklm{
	kecil kontainer_kol;
	alamatekolom next_kol;
}eKolom;

typedef struct ebr *alamatebaris;
typedef struct ebr{
	besar kontainer;
	eKolom *col;
	alamatebaris next;
}eBaris;

typedef struct{
	eBaris *first;
}list;

void createList(list *L);
int countElementB(list L);
int countElemenK(eBaris L);
void addFirstB(char jenis[], int tahun, list *L);
void addFirstK(char nama[], eBaris *L);
void addAfterB(eBaris* prev, char jenis[], int tahun);
void addAfterK(eKolom* prev, char nama[]);
void addLastB(char jenis[], int tahun, list *L);
void addLastK(char nama[], eBaris *L);
void delFirstK(eBaris *L);
void delAfterK(eKolom* prev);
void delLastK(eBaris *L);
void delAllK(eBaris *L);
void delFirstB(list *L);
void delAfterB(eBaris* prev);
void delLastB(list *L);
void delAllB(list *L);
void printElement(list L);
void pindah(list *L);//untuk update listnya
void sorting(list *L);//untuk sorting sesuai jenis
void sorting2(list *L);//untuk sorting sesuai tahun
void print(list L);

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi UTS dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/