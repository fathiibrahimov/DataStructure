#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
	char nama[50];
	char nilai[50];
	char banyak;
}nilaiMatKul;//isi queue

typedef struct elm *alamatelmt;
typedef struct elm{
	nilaiMatKul kontainer;
	alamatelmt next;
	int prioritas;
}elemen;//prioritas beserta kontainer dan next

typedef struct{
	elemen *first;
	elemen *last;
}queue;//ujung ujungnya queue juga

int n, m;//menampung jumlah data
int gelombang[50];//menampung isi gelombangnya berapa orang

void createEmpty(queue *Q);//membuat queue kosong
int isEmpty(queue Q);//mengecek apakah queue kosong
int countElement(queue Q);//menghitung jumlah elemen
void add(char nama[], char nilai[], int banyak, queue *Q );//enqueue
void addpriority(char nama[], char nilai[], int banyak, int prioritas, queue *Q );//enqueue versi prioritas
void del(queue *Q, queue *R);//dequeue
void printQueue(queue Q);//mencetak hasil queue

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Quiz 2 dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/