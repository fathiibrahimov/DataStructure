#include "tm.h"

void createList (list *L){//membuat list
	(*L).first = NULL;//mengatur headnya supaya null
}

int countElement(list L){//menghitung elemen
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

void addFirst(char nama[], char rumus[], char konsentrasi[], list *L){//menambah elemen di awal
	elemen* baru;//buat elemen baru
	baru = (elemen*) malloc (sizeof (elemen));
	//memasukkan data ke elemen barunya
	strcpy(baru->kontainer.nama, nama);
	strcpy(baru->kontainer.rumus, rumus);
	strcpy(baru->kontainer.konsentrasi, konsentrasi);
	
	if((*L).first == NULL){
		//jika list kosong
		baru->next = NULL;
	}
	else{
		//jika list tidak kosong
		baru->next = (*L).first;
	}
	
	(*L).first = baru;
	baru = NULL;

}

void addAfter(elemen* prev, char nama[], char rumus[], char konsentrasi[], list *L){//menambah elemen setelah
	elemen* baru;
	baru = (elemen*) malloc (sizeof (elemen));
	//memasukkan data ke elemen barunya
	strcpy(baru->kontainer.nama, nama);
	strcpy(baru->kontainer.rumus, rumus);
	strcpy(baru->kontainer.konsentrasi, konsentrasi);
		
	if(prev->next == NULL){
		baru->next = NULL;
	}else{
		baru->next = prev->next;
	}
	prev->next = baru;
	baru=NULL;
	
}

void addLast(char nama[], char rumus[], char konsentrasi[], list *L){//menambah elemen di akhir
	if((*L).first == NULL){
		//proses jika list masih kosong
		addFirst(nama, rumus, konsentrasi, L);
	}else{
		//proses jika list telah berisi elemen
		elemen* prev = (*L).first;
		while(prev->next != NULL){
		//iterasi
		prev = prev->next;
		}
		addAfter(prev, nama, rumus, konsentrasi, L);
	}
}

void delFirst(list *L){//menghapus elemen di awal
	if((*L).first != NULL){
		//jika list bukan list kosong
		elemen* hapus = (*L).first;
		if(countElement(*L) == 1){
			(*L).first = NULL;
		}else{
			(*L).first = (*L).first->next;
			hapus->next = NULL;
		}
		free(hapus);//memorinya dibebasin
	}
}

void delAfter(elemen* prev, list *L){//menghapus elemen setelah
	elemen* hapus = prev->next;
	if(hapus != NULL){
		if(hapus->next == NULL){
			prev->next = NULL;
		}else{
			prev->next = hapus->next;
			hapus->next = NULL;
		}
		free(hapus);//memorinya dibebasin
	}
}

void delLast(list *L){//menghapus elemen di akhir
	if((*L).first != NULL){
		//jika list tidak kosong
		if(countElement(*L) == 1){
			//proses jika list hanya berisi satu elemen
			delFirst(L);
		}
		else{
			elemen* last = (*L).first;
			elemen* prev;
			
			while(last->next != NULL){
				
				//iterasi
				prev = last;
				last = last->next;
			}
			//elemen sebelum elemen terakhir menjadi elemen terakhir
			delAfter(prev, L);
		}	
	}
}

void printElement(list L){//cetak elemen di list
	if(L.first != NULL){
		//inisialisasi
		elemen* tunjuk = L.first;
		int i = 1;
		printf("=====\n");
		while(tunjuk != NULL){
		//proses
			
			printf("%s %s %s\n", tunjuk->kontainer.nama, tunjuk->kontainer.rumus, tunjuk->kontainer.konsentrasi);
			//iterasi
			tunjuk = tunjuk->next;
			i=i+1;
		}
		
	}
	
	else{
		//proses jika list kosong
		printf("List Kosong\n");
	}
	
}

void delAll(list *L){//hapus semua elemen
	if(countElement(*L) != 0){
		int i;
		for(i=countElement(*L);i>=1;i--){
			//proses menghapus elemen list
			delLast(L);
		}
	}
}