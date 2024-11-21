#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

typedef struct smp *alamatsimpul; 

typedef struct smp{
	char nama[100];//nama simpul
	int jam;
	int menit;
	int detik;
	alamatsimpul right;
	alamatsimpul left;
}simpul;

typedef struct{
	simpul* root;
}tree;

int waktu1;//waktu simpul kiri
int waktu2;//waktu simpul kanan
int waktu3;//waktu total
int cek;//mengetahui berada di simpul kanan atau kiri

void makeTree(char mnama[], int mjam, int mmenit, int mdetik, tree *T);//membuat pohon
void addRight(char mnama[], int mjam, int mmenit, int mdetik, simpul *root);//menambahkan sebelah kanan
void addLeft(char mnama[], int mjam, int mmenit, int mdetik, simpul *root);//menambahkan sebelah kiri
void delAll(simpul *root);//menghapus semua
void delRight(simpul *root);//menghapus simpul kanan
void delLeft(simpul *root);//menghapus simpul kiri
void addLeftCari(char dicari[], char mnama[], int mjam, int mmenit, int mdetik, simpul *root);//menambahkan sebelah kanan tapi parentnya bukan root
void addRightCari(char dicari[], char mnama[], int mjam, int mmenit, int mdetik, simpul *root);//menambahkan sebelah kiri tapi parentnya bukan root
void printDaun(simpul *root);//mencetak daunnya dan jumlah detiknya

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Remedial dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/