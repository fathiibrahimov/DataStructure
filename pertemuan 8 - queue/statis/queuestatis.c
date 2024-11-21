#include "queuestatis.h"

void createEmpty(queue *Q){
	int i;
	(*Q).first = -1;
	(*Q).last = -1;
	
	for(i=0;i<10;i++){
		//proses menginisialisasi isi array
		(*Q).data[i].prioritas = 100;
	}
}

int isEmpty(queue Q){
	int hasil = 0;
	if(Q.first == -1){
		hasil = 1;
	}
	return hasil;
}

int isFull(queue Q){
	int hasil = 0;
	if(Q.last == 9){
		hasil = 1;
	}
	return hasil;
}



void add(char nama[], char nilai[], queue *Q ){

	if(isEmpty(*Q) == 1){
		/* jika queue kosong */
		(*Q).first = 0;
		(*Q).last = 0;
		 
		strcpy((*Q).data[0].kontainer.nama, nama);
		strcpy((*Q).data[0].kontainer.nilai, nilai);
	}else{
		/* jika queue tidak kosong */
		if(isFull(*Q) != 1){
			(*Q).last = (*Q).last + 1;
			
			strcpy((*Q).data[(*Q).last].kontainer.nama, nama);
			strcpy((*Q).data[(*Q).last].kontainer.nilai, nilai);
		}
		else{
			printf("queue penuh\n");
		}
	}
}

void addpriority(char nama[], char nilai[], int prioritas, queue *Q ){
	int i;

	if(isEmpty(*Q) == 1){
		/* jika queue kosong */
		(*Q).first = 0;
		(*Q).last = 0;
		 
		strcpy((*Q).data[0].kontainer.nama, nama);
		strcpy((*Q).data[0].kontainer.nilai, nilai);
		(*Q).data[0].prioritas = prioritas;
		
	}else{
		/* jika queue tidak kosong */
		if(isFull(*Q) != 1){
			
			if(prioritas == 1){
				for(i=(*Q).last;i>=(*Q).first;i--){
					strcpy((*Q).data[i+1].kontainer.nama, (*Q).data[i].kontainer.nama);
					strcpy((*Q).data[i+1].kontainer.nilai, (*Q).data[i].kontainer.nilai);
					(*Q).data[i+1].prioritas = (*Q).data[i].kontainer.prioritas;
				}
				(*Q).last = (*Q).last + 1;
				strcpy((*Q).data[0].kontainer.nama, nama);
				strcpy((*Q).data[0].kontainer.nilai, nilai);
				(*Q).data[0].prioritas = prioritas;
			}else if(prioritas > 6){
				(*Q).last = (*Q).last + 1;
			
				strcpy((*Q).data[(*Q).last].kontainer.nama, nama);
				strcpy((*Q).data[(*Q).last].kontainer.nilai, nilai);
			}else{
				for(i=(*Q).last;i>=prioritas-1;i--){
					strcpy((*Q).data[i+1].kontainer.nama, (*Q).data[i].kontainer.nama);
					strcpy((*Q).data[i+1].kontainer.nilai, (*Q).data[i].kontainer.nilai);
					(*Q).data[i+1].prioritas = (*Q).data[i].kontainer.prioritas;
				}
				(*Q).last = (*Q).last + 1;
				strcpy((*Q).data[prioritas-1].kontainer.nama, nama);
				strcpy((*Q).data[prioritas-1].kontainer.nilai, nilai);
				(*Q).data[prioritas-1].prioritas = prioritas;
			}
			
		}
		else{
			printf("queue penuh\n");
		}
	}
}

void del(queue *Q, queue *R){
	add((*Q).data[0].kontainer.nama, (*Q).data[0].kontainer.nilai, R);
	
	if((*Q).last == 0){
		(*Q).first = -1;
		(*Q).last = -1;
	}else{
		/*menggeser elemen ke depan*/
		int i;
		for(i=((*Q).first + 1);i<=(*Q).last;i++){

			strcpy((*Q).data[i-1].kontainer.nama, (*Q).data[i].kontainer.nama);
			strcpy((*Q).data[i-1].kontainer.nilai, (*Q).data[i].kontainer.nilai);
		}
		(*Q).last = (*Q).last - 1;
	}
}

void printQueue(queue Q){
	if(Q.first != -1){
		printf("******************\n");
		printf("Queue 1\n");
		int i;
		for(i=Q.first;i<=Q.last;i++){
			printf("%s ", Q.data[i].kontainer.nama);
			printf("%s\n", Q.data[i].kontainer.nilai);
		}
	}
	else{
	/* proses jika queue kosong */
	printf("queue kosong\n");
	}
}

void printQueue2(queue Q){
	if(Q.first != -1){
		printf("******************\n");
		printf("Queue 2\n");
		int i;
		for(i=Q.first;i<=Q.last;i++){
			printf("%s ", Q.data[i].kontainer.nama);
			printf("%s\n", Q.data[i].kontainer.nilai);
		}
	}
	else{
	/* proses jika queue kosong */
	printf("queue kosong\n");
	}
}
