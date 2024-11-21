#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
	char nama[50];
	char nilai[10];
	int jam;
}nilaiMatKul;//ini menentukan isi dari queuenya apa aja

typedef struct elm *alamatelmt;
typedef struct elm{
	nilaiMatKul kontainer;
	alamatelmt next;
	int prioritas;
}elemen;//ini menentukan struktur dari queuenya

typedef struct{
	elemen *first;
	elemen *last;
}queue;//ini menentukan ujung ujung dari queuenya

//a b c untuk menentukan prioritasnya
int a;
int b;
int c;
char carinama[50];//tampungan untuk nama yang dicari

void createEmpty(queue *Q);//membuat queue kosong
int isEmpty(queue Q);//mengecek apakah queue kosong
int countElement(queue Q);//menghitung element dalam queue
void add(char nama[], char nilai[], int jam, queue *Q );//enqueue
void addpriority(char nama[], char nilai[], int jam, int prioritas, queue *Q );//enqueue dengan prioritas
void del(queue *Q);//dequeue
void printQueue(queue Q);//mencetak isi dari queue, tidak dipakai dalam soal ini
void ganti(char nama[], char nilai[], int jam, queue *Q);//untuk mengecek harus ditambah dengan prioritas keberapa berdasarkan tiketnya
void printoutput(queue Q);//mencetak sesuai dengan permintaan soal

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Tugas Praktikum 7 dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/