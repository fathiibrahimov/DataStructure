#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

typedef struct smp *alamatsimpul;

typedef struct smp{
	char kontainer[100];
	char bawaan[100][100];
	int jumlahbawaan;
	alamatsimpul sibling;
	alamatsimpul child;
}simpul;

typedef struct{
	simpul *root;
}tree;

char pohonsementara[100][100][100];//untuk mempermudah mencari parent dari suatu simpul maka saya tampung saja semua simpul beserta parentnya siapa disini
int ps;//panjang dari pohon sementara

char pohonpindah[100][100][100];//untuk menampung sementara yang mau pindah naungan dan menjadi mandiri
int ppp;//panjang dari pohon pindah

void makeTree(char c[], int jumlah, tree *T);//membuat pohon
void addChild(char c[], int jumlah, simpul *root);//menambah anak
void delAll(simpul *root);//menghapus semua
void delChild(char c[], simpul *root);//menghapus anak
simpul* findSimpul(char c[], simpul *root);//mencari simpul
void printTreePreOrder(simpul *root);//mencetak secara preorder
void printTreePostOrder(simpul *root);//mencetak secara postorder
void pindahnaungan(char child[], char parent[], simpul *root);//untuk pindah naungan
void cetak(simpul *root);//untuk mencetak sesuai pola

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi TMD dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/