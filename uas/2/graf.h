#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct smp *alamatsimpul;
typedef struct jlr *alamatjalur;

typedef struct smp{
	char kontainer[100];
	alamatsimpul next;
	alamatjalur arc;
}simpul;

typedef struct jlr{
	int kontainer_jalur;
	alamatjalur next_jalur;
	simpul *tujuan;
}jalur;

typedef struct{
	simpul* first;
}graph;


void createEmpty(graph *G);
void addSimpul(char c[], graph *G);
void addJalur(simpul *awal, simpul *tujuan, int beban);
simpul* findSimpul(char c[], graph G);
void delJalur(char ctujuan[], simpul *awal);
void delAll(simpul *awal);
void delSimpul(char c[], graph *G);
void printGraph(graph G);

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi UAS dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/