#include "tm5.h"

void createList (list *L){
	(*L).first = NULL;
	(*L).tail = NULL;
}

int countElement(list L){
	int hasil = 0;
	if(L.first != NULL){
		//list tidak kosong
		
		elemen* tunjuk;
		
		//inisialisasi
		tunjuk = L.first;
		
		while(tunjuk != NULL){
			//proses
			hasil = hasil+1;
			
			//iterasi
			tunjuk = tunjuk->next;
		}
	}
	return hasil;
}

void addFirst(char nim[], char nama[],list *L){
	elemen* baru;
	baru = (elemen*) malloc (sizeof (elemen));
	strcpy(baru->kontainer.nim, nim);
	strcpy(baru->kontainer.nama, nama);
	
	if((*L).first == NULL){
		//jika list kosong
		baru->prev = NULL;
		baru->next = NULL;
		(*L).tail = baru;
	}
	else{
		//jika list tidak kosong
		baru->next = (*L).first;
		baru->prev = NULL;
		(*L).first->prev = baru;
	}
	
	(*L).first = baru;
	baru = NULL;

}

void addAfter(elemen* before, char nim[], char nama[], list *L){	
		
	if(before != NULL){
		elemen* baru;
		baru = (elemen*) malloc (sizeof (elemen));
		
		strcpy(baru->kontainer.nim, nim);
		strcpy(baru->kontainer.nama, nama);
		if(before->next == NULL){
			baru->next = NULL;
			(*L).tail = baru;
		}else{
			baru->next = before->next;
			baru->next->prev = baru;
		}
		baru->prev = before;
		before->next = baru;
		baru=NULL;
	}
}

void addBefore(elemen* before, char nim[], char nama[], list *L){
		
	if(before != NULL){
		elemen* baru;
		baru = (elemen*) malloc (sizeof (elemen));
		
		strcpy(baru->kontainer.nim, nim);
		strcpy(baru->kontainer.nama, nama);
		if(before->prev == NULL){
			baru->prev = NULL;
			(*L).first = baru;
		}else{
			baru->prev = before->prev;
			baru->prev->next = baru;
		}
		baru->next = before;
		before->prev = baru;
		baru=NULL;
	}
}

void addLast(char nim[], char nama[],  list *L){
	if((*L).first == NULL){
		//proses jika list masih kosong
		addFirst(nim, nama, L);
	}else{
		//proses jika list telah berisi elemen
		addAfter((*L).tail, nim, nama, L);
	}
}

void delFirst(list *L){
	if((*L).first != NULL){
		//jika list bukan list kosong
		elemen* hapus = (*L).first;
		if(countElement(*L) == 1){
			(*L).first = NULL;
			(*L).tail = NULL;
		}else{
			(*L).first = (*L).first->next;
			(*L).first->prev = NULL;
			hapus->next = NULL;
		}
		free(hapus);
	}
}

void delAfter(elemen* before, list *L){
	
	if(before != NULL){
		elemen* hapus = before->next;
		if(hapus != NULL){
			if(hapus->next == NULL){
				(*L).tail = before;
				before->next = NULL;
			}else{
				before->next = hapus->next;
				hapus->next->prev = before;
				hapus->next = NULL;
			}
		}
		hapus->prev = NULL;
		free(hapus);
	}
}

void delLast(list *L){
	if((*L).first != NULL){
		//jika list tidak kosong
		if(countElement(*L) == 1){
			//proses jika list hanya berisi satu elemen
			delFirst(L);
		}
		else{
			//elemen sebelum elemen terakhir menjadi elemen terakhir
			delAfter((*L).tail->prev, L);
		}	
	}
}

void printElement(list L){
	if(L.first != NULL){
		//inisialisasi
		elemen* tunjuk = L.first;
		int i = 1;
		
		while(tunjuk != NULL){
		//proses
			printf("%s ", tunjuk->kontainer.nim);
			printf("%s\n", tunjuk->kontainer.nama);
			
			//iterasi
			tunjuk = tunjuk->next;
			i=i+1;
		}
		printf("-----\n");
	}
	else{
		//proses jika list kosong
		printf("LGD Kosong\n");
		printf("-----\n");
	}
}

void printElementToHead(list L){
	if(L.first != NULL){
		//inisialisasi
		elemen* tunjuk = L.tail;
		int i = 1;
		
		while(tunjuk != NULL){
		//proses
			printf("%s ", tunjuk->kontainer.nim);
			printf("%s\n", tunjuk->kontainer.nama);
			
			//iterasi
			tunjuk = tunjuk->prev;
			i=i+1;
		}
		printf("-----\n");
	}
	else{
		//proses jika list kosong
		printf("LGD Kosong\n");
		printf("-----\n");
	}
}

void delAll(list *L){
	if(countElement(*L) != 0){
		int i;
		for(i=countElement(*L);i>=1;i--){
			//proses menghapus elemen list
			delLast(L);
		}
	}
}