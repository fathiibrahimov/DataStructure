#include <stdio.h>
#include <string.h>

typedef struct{
	char nim[10];
	char nama[50];
	char nilai[2];
}nilaiMatKul;

typedef struct{
	nilaiMatKul kontainer;
	int next;
}elemen;

typedef struct{
	int first;
	elemen data[10];
}list;

void createList (list *L){
	
	(*L).first = -1;
	int i;
	
	for(i=0;i<10;i++){
		//proses menginisialisasi isi array
		(*L).data[i].next = -2;
	}
}

int countElement(list L){
	int hasil = 0;
	if(L.first != -1){
		//list tidak kosong
		int hitung;
		
		//inisialisasi
		hitung = L.first;
		
		while(hitung != -1){
			//proses
			hasil = hasil+1;
			
			//iterasi
			hitung = L.data[hitung].next;
		}
	}
	
	return hasil;
}