#include "queuedinamis.h"

void createEmpty(queue *Q){
	(*Q).first = NULL;
	(*Q).last = NULL;
}

int isEmpty(queue Q){
	int hasil = 0;
	if(Q.first == NULL){
		hasil = 1;
	}
	return hasil;
}

int countElement(queue Q){
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

void add(char nama[], char nilai[], queue *Q ){
	elemen* baru;
	baru = (elemen *) malloc (sizeof (elemen));
	strcpy(baru->kontainer.nama, nama);
	strcpy(baru->kontainer.nilai, nilai);
	baru->next = NULL;
	
	if((*Q).first == NULL){
		(*Q).first = baru;
	}else{
		(*Q).last->next = baru;
	}
	(*Q).last = baru;
	baru = NULL;
}

void addpriority(char nama[], char nilai[], int prioritas, queue *Q ){
	int i;
	
	elemen* baru;
	baru = (elemen *) malloc (sizeof (elemen));
	strcpy(baru->kontainer.nama, nama);
	strcpy(baru->kontainer.nilai, nilai);
	baru->next = NULL;

	if(countElement(*Q) < prioritas){
 		if((*Q).first == NULL){
 			(*Q).first = baru;
 		}else{ 
 			(*Q).last->next = baru;
 		}
 		(*Q).last = baru;
 		baru = NULL;
 	}else{
		elemen* bantu = (*Q).first;
		elemen* bantu2 = NULL;
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

void del(queue *Q, queue *R){
	if((*Q).first != NULL){
		/* jika queue bukan queue kosong */
		elemen *hapus = (*Q).first;
		add(hapus->kontainer.nama, hapus->kontainer.nilai, R);
		
		if(countElement(*Q) == 1){
			(*Q).first = NULL;
			(*Q).last = NULL;
		}else{
			(*Q).first = (*Q).first->next; hapus->next = NULL;
		}

	free(hapus);
	}
}

void printQueue(queue Q){

	if(Q.first != NULL){
		printf("******************\n");
		printf("Queue 1\n");

		elemen* bantu = Q.first;
		int i = 1;
		while(bantu != NULL){
			printf("%s ", bantu->kontainer.nama);
			printf("%s\n", bantu->kontainer.nilai);
			/* iterasi */
			bantu = bantu->next;
			i = i + 1;
		}
	}else{
		/* proses jika queue kosong */
		printf("queue kosong\n");
	}
}

void printQueue2(queue Q){

	if(Q.first != NULL){
		printf("******************\n");
		printf("Queue 2\n");

		elemen* bantu = Q.first;
		int i = 1;
		while(bantu != NULL){
			printf("%s ", bantu->kontainer.nama);
			printf("%s\n", bantu->kontainer.nilai);
			/* iterasi */
			bantu = bantu->next;
			i = i + 1;
		}
	}else{
		/* proses jika queue kosong */
		printf("queue kosong\n");
	}
}