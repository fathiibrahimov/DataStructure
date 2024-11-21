#include "tp7.h"

int main(){
	queue Q;
	createEmpty(&Q);
	
	//tampungan untuk scanf isi queue
	char temp1[50];
	char temp2[10];
	int temp3;
	
	//atur prioritas yang di variabel global sebagai nol semua
	a=0;
	b=0;
	c=0;
	
	scanf("%s", temp1);//cari tau dulu namanya siapa
	
	while(strcmp(temp1, "selesai") != 0){//muter sampai ketemu nama selesai
		scanf("%s %d", temp2, &temp3);
		ganti(temp1, temp2, temp3, &Q);
		scanf("%s", temp1);
	}
	scanf("%s", carinama);
	
	printoutput(Q);//cetak
	//printQueue(Q);
	

	return 0;
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Tugas Praktikum 7 dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/