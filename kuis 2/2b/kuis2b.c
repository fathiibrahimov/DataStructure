#include "kuis2b.h"

void createEmpty(queue *Q){//atur null semua dulu ujung ujungnya
	(*Q).first = NULL;
	(*Q).last = NULL;
}

int isEmpty(queue Q){//mengecek apakah queue kosong
	int hasil = 0;
	if(Q.first == NULL){
		hasil = 1;
	}
	return hasil;
}

int countElement(queue Q){//menghitung jumlah elemen
	int hasil = 0;
	if(Q.first != NULL){
		/* queue tidak kosong */
		elemen* bantu;
		/* inisialisasi */
		bantu = Q.first;
		while(bantu != NULL){
			/* proses */
			hasil= hasil + 1;

			/* iterasi */
			bantu = bantu->next;
		}
	}
	return hasil;
}

void add(char nama[], char nilai[], int banyak, queue *Q ){//enqueue, tapi disini tidak dipakai
	elemen* baru;
	baru = (elemen *) malloc (sizeof (elemen));
	strcpy(baru->kontainer.nama, nama);
	strcpy(baru->kontainer.nilai, nilai);
	baru->kontainer.banyak = banyak;
	baru->next = NULL;
	
	if((*Q).first == NULL){
		(*Q).first = baru;
	}else{
		(*Q).last->next = baru;
	}
	(*Q).last = baru;
	baru = NULL;
}

void addpriority(char nama[], char nilai[], int banyak, int prioritas, queue *Q ){//enqueue versi prioritas
	int i;
	
	elemen* baru;
	baru = (elemen *) malloc (sizeof (elemen));
	strcpy(baru->kontainer.nama, nama);
	strcpy(baru->kontainer.nilai, nilai);
	baru->kontainer.banyak = banyak;
	baru->next = NULL;

	if(countElement(*Q) < prioritas){//kalau prioritas melebihi slot yang ada di queue
 		if((*Q).first == NULL){//kalau kosong
 			(*Q).first = baru;
 		}else{ //kalau tidak kosong
 			(*Q).last->next = baru;
 		}
 		(*Q).last = baru;
 		baru = NULL;
 	}else{//kalau ada slotnya
		elemen* bantu = (*Q).first;//alat bantu buat menentukan posisi
		elemen* bantu2 = NULL;//sama kaya diatas, beda posisi saja, ini ada di belakang
		i=1;
		
		while(bantu != NULL && i < prioritas){
			
			bantu2 = bantu;
			bantu = bantu->next;
			i = i+1;
		}
		
		baru->next = bantu;
		if(bantu2 == NULL){
			(*Q).first = baru;
		}else{
			bantu2->next = baru;
		}
		
	}
}

void del(queue *Q, queue *R){//dequeue
	if((*Q).first != NULL){
		/* jika queue bukan queue kosong */
		elemen *hapus = (*Q).first;
		
		if(countElement(*Q) == 1){
			(*Q).first = NULL;
			(*Q).last = NULL;
		}else{
			(*Q).first = (*Q).first->next; hapus->next = NULL;
		}

	free(hapus);
	}
}

void printQueue(queue Q){//cetak

	if(Q.first != NULL){
		

		elemen* bantu = Q.first;
		int i = 1;
		int j;
		
		for(i=1;i<=m;i++){//cetak yang masuk gelombang
			printf("gelombang %d:\n", i);
			for(j=0;j<gelombang[i-1];j++){
				printf("%s ", bantu->kontainer.nama);
				printf("%s ", bantu->kontainer.nilai);
				printf("%d\n", bantu->kontainer.banyak);
				/* iterasi */
				bantu = bantu->next;
				
			}
			printf("\n");
		}
		
		printf("sisa antrian:\n");//cetak sisa antrian
		while(bantu != NULL){
			
			printf("%s ", bantu->kontainer.nama);
			printf("%s ", bantu->kontainer.nilai);
			printf("%d\n", bantu->kontainer.banyak);
			/* iterasi */
			bantu = bantu->next;
		}
	}else{
		/* proses jika queue kosong */
		printf("queue kosong\n");
	}
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Quiz 2 dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
