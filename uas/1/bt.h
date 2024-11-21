#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct smp *alamatsimpul; 

typedef struct smp{
	char kontainer[100];
	alamatsimpul right;
	alamatsimpul left;
}simpul;

typedef struct{
	simpul* root;
}tree;

void makeTree(char c[], tree *T);
void addRight(char c[], simpul *root);
void addLeft(char c[], simpul *root);
void delAll(simpul *root);
void delRight(simpul *root);
void delLeft(simpul *root);
void printTreePreOrder(simpul *root);
void printTreeInOrder(simpul *root);
void printTreePostOrder(simpul *root);
void copyTree(simpul *root1, simpul **root2);
int isEqual(simpul *root1, simpul *root2);
void masuk(char parent[], char child[], char arah[], simpul *root);

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi UAS dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/