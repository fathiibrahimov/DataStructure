#include <stdio.h>
#include <string.h>

int n;//buat panjang list seinget saya ini tuh
int tampungan[20];//buat nampung skala buat di sort
int mark[20];//buat nampung index yang bener

typedef struct{//bungkusan buat isi dari kontainer
	char nama[100];
	int skala;
}daftarMaha;

typedef struct{//bungkusan buat listnya
	daftarMaha kontainer;
	int next;
}elemen;

typedef struct{//ini bungkusan buat listnya juga, tapi saya bingung jelasinnya
	int first;
	elemen data[100];
}list;

void createList (list *L);//prosedur buat list
int countElement(list L);//prosedur menghitung jumlah elemen
int emptyElement(list L);//prosedur mencari elemen kosong
void addFirst(char nama[], int skala, list *L);//prosedur menambahkan di awal
void addAfter(int prev, char nama[], int skala, list *L);//prosedur menambahkan setelah
void addLast(char nama[], int skala, list *L);//prosedur menambahkan di akhir
void delFirst(list *L);//prosedur menghapus di awal
void delAfter(int prev, list *L);//prosedur menghapus setelah
void delLast(list *L);//prosedur menghapus di akhir
void printElement(list L);//prosedur buat print
void delAll(list *L);//prosedur buat menghapus semua
void pilah(list *L);//prosedur buat ngurutin skalanya secara asc
void pilahdesc(list *L);//prosedur buat ngurutin skalanya secara desc
void tandain(list L);//prosedur buat ngambil nilai index
void printsort(list L);//prosedur buat print secara urut

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Tugas Praktikum 1 dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/