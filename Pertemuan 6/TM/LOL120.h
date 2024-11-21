#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
	char nama;
}mahasiswa;

typedef struct{
	char satu[50];
}matKul;

typedef struct eklm *alamatekolom;
typedef struct eklm{
	matKul kontainer_kol;
	alamatekolom next_kol;
}eKolom;

typedef struct ebr *alamatebaris;
typedef struct ebr{
	mahasiswa kontainer;
	eKolom *col;
	alamatebaris next;
}eBaris;

typedef struct{
	eBaris *first;
}list;

void createList(list *L);
int countElementB(list L);
int countElemenK(eBaris L);
void addFirstB(char nama, list *L);
void addFirstK(char satu[], eBaris *L);
void addAfterB(eBaris* prev, char nama);
void addAfterK(eKolom* prev, char satu[]);
void addLastB(char nama, list *L);
void addLastK(char satu[], eBaris *L);
void delFirstK(eBaris *L);
void delAfterK(eKolom* prev);
void delLastK(eBaris *L);
void delAllK(eBaris *L);
void delFirstB(list *L);
void delAfterB(eBaris* prev);
void delLastB(list *L);
void delAllB(list *L);
void printElement(list L);