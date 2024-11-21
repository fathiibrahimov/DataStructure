#include <stdio.h>
#include <string.h>

typedef struct{
  char tanda;
  int nomor;
}nilaiMatkul;//isi stack

typedef struct{
  int top;
  nilaiMatkul data[60];
}stack;//struktur stacknya

void createEmpty(stack *S);//membuat stack kosong
int isEmpty(stack S);//mengecek apakah stack kosong
int isFull(stack S);//mengecek apakah stack penuh
void push(char tanda, int nomor, stack *S);//push data ke stack
void pop(stack *S);//pop dari dari stack
void printStack(stack S);//mencetak isi stack
void pisah(stack *S, stack *T, stack *U, int n);//memisahkan yang berpasangan
void popTo(stack *S, stack *T);//pop ke stack lain
int sama(char c1, char c2);//mengecek pasangan

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Quiz 2 dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
