#include <stdio.h>
#include <string.h>

int n;//panjang list
int tampungan[100];//buat nampung skala buat di sort
int mark[100];//buat nampung index yang bener

typedef struct{
	char judul[100];
	char nama[100];
	int nilai;
	char genre[50];
}nilaiMatKul;

typedef struct{
	nilaiMatKul kontainer;
	int prev;
	int next;
}elemen;

typedef struct{
	int first;
	int tail;
	elemen data[10];
}list;

void createList (list *L);//buat list
int countElement(list L);//hitung elemen di list
int emptyElement(list L);//buat elemen kosong
void addFirst(char judul[], char nama[], int nilai, char genre[], list *L);//tambah di awal
void addAfter(int before, char judul[], char nama[], int nilai, char genre[], list *L);//tambah setelah
void addLast(char judul[], char nama[], int nilai, char genre[], list *L);//tambah di akhir
void delFirst(list *L);//hapus di awal
void delAfter(int before, list *L);//hapus setelah
void delLast(list *L);//hapus di akhir
void printElement(list L);//print elemen dari awal
void delAll(list *L);//hapus semua, kecuali kenangan bersama mantan
void sorting(list *L);//urutin
void caritanggal(int tawal, list *L);//pangkas listnya berdasarkan tanggal
void printElementToHead(list L);//print elemen dari akhir
void printernya(list L);//print sesuai permintaan

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Tugas Praktikum 3 dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/