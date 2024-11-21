#include "LOL120.h"

//create list
void createList(list *L){
	(*L).first = NULL;
}

//count elemen baris
int countElementB(list L){
	int hasil = 0;
	
	if(L.first != NULL){
		//list tidak kosong
		eBaris* bantu;
		
		//inisialisasi
		bantu = L.first;
		
		while(bantu != NULL){
			//proses
			hasil = hasil + 1;
			
			//iterasi
			bantu = bantu->next;
		}
	}
	return hasil;
}

//count elemen kolom
int countElemenK(eBaris L){
	int hasil = 0;
	if(L.col != NULL){
		//list tidak kosong
		eKolom* bantu;
		
		//inisialisasi
		bantu = L.col;
		
		while(bantu != NULL){
			//proses
			hasil = hasil + 1;
			
			//iterasi
			bantu = bantu->next_kol;
		}
	}
	return hasil;
}

//add first baris
void addFirstB(char nama, list *L){
	eBaris* baru;
	baru = (eBaris *) malloc (sizeof (eBaris));
	baru->kontainer.nama = nama;
	baru->col = NULL;
	if((*L).first == NULL){
		baru->next = NULL;
	}else{
		baru->next = (*L).first;
	}
	(*L).first = baru;
	baru = NULL;
}

//add first kolom
void addFirstK(char satu[], eBaris *L){
	eKolom* baru;
	baru = (eKolom *) malloc (sizeof (eKolom));
	strcpy(baru->kontainer_kol.satu, satu);
	
	if((*L).col == NULL){
		baru->next_kol = NULL;
	}else{
		baru->next_kol = (*L).col;
	}
	(*L).col = baru;
	baru = NULL;
}

//add after baris
void addAfterB(eBaris* prev, char nama){
	eBaris* baru;
	baru = (eBaris *) malloc (sizeof (eBaris));
	baru->kontainer.nama = nama;
	baru->col = NULL;
	if(prev->next == NULL){
		baru->next = NULL;
	}else{
		baru->next = prev->next;
	}
	prev->next = baru;
	baru = NULL;
}

//add after kolom
void addAfterK(eKolom* prev, char satu[]){
	eKolom* baru;
	baru = (eKolom *) malloc (sizeof (eKolom));
	strcpy(baru->kontainer_kol.satu, satu);
	
	if(prev->next_kol == NULL){
		baru->next_kol = NULL;
	}else{
		baru->next_kol = prev->next_kol;
	}
	prev->next_kol = baru;
	baru = NULL;
}

//add last baris
void addLastB(char nama, list *L){
	if((*L).first == NULL){
		//jika list adalah list kosong
		addFirstB(nama, L);
	}else{
		//jika list tidak kosong
		//mencari elemen terakhir list
		eBaris *last = (*L).first;
		while(last->next !=NULL){
			//iterasi
			last = last->next;
		}
		addAfterB(last, nama);
	}
}

//add last kolom
void addLastK(char satu[], eBaris *L){
	if((*L).col == NULL){
		//jika list adalah list kosong
		addFirstK(satu, L);
	}else{
		//jika list tidak kosong
		//mencari elemen terakhir list
		eKolom *last = (*L).col;
		while(last->next_kol !=NULL){
			//iterasi
			last = last->next_kol;
		}
		addAfterK(last, satu);
	}
}

//del first kolom
void delFirstK(eBaris *L){
	if((*L).col != NULL){
		//jika list bukan list kosong
		eKolom* hapus = (*L).col;
		if(countElemenK(*L) == 1){
			(*L).col = NULL;
		}else{
			(*L).col = (*L).col->next_kol;
			hapus->next_kol = NULL;
		}
		free(hapus);
	}
}

//del after kolom
void delAfterK(eKolom* prev){
	eKolom* hapus = prev->next_kol;
	if(hapus != NULL){
		if(hapus->next_kol == NULL){
			prev->next_kol = NULL;
		}else{
			prev->next_kol = hapus->next_kol;
			hapus->next_kol = NULL;
		}
		free(hapus);
	}
}

//del last kolom
void delLastK(eBaris *L){
	if((*L).col != NULL){
		//jika list bukan list kosong
		if(countElemenK(*L) == 1){
			//list terdiri dari satu elemen
			delFirstK(L);
		}else{
			//mencari elemen terakhir list
			eKolom *last = (*L).col;
			eKolom *before_last;
			
			while(last->next_kol != NULL){
				//iterasi
				before_last = last;
				last = last->next_kol;
			}
			delAfterK(before_last);
		}
	}
}

//del all kolom
void delAllK(eBaris *L){
	if(countElemenK(*L) != 0){
		int i;
		for(i=countElemenK(*L); i>=1; i--){
			//proses menghapus elemen list
			delLastK(L);
		}
	}
}

//del first baris
void delFirstB(list *L){
	if((*L).first != NULL){
		//jika list bukan list kosong
		eBaris* hapus = (*L).first;
		if(hapus->col != NULL){
			//menghapus semua elemen kolom jika adalah
			delAllK(hapus);
		}
		if(countElementB(*L) == 1){
			(*L).first = NULL;
		}else{
			(*L).first = (*L).first->next;
			hapus->next = NULL;
		}
		free(hapus);
	}else{
		printf("list kosong");
	}
}

//del after baris
void delAfterB(eBaris* prev){
	if(prev != NULL){
		eBaris* hapus = prev->next;
		if(hapus != NULL){
			if(hapus->col != NULL){
				//menghapus semua elemen kolom jika ada
				delAllK(hapus);
			}
			if(hapus->next == NULL){
				prev->next = NULL;
			}else{
				prev->next = hapus->next;
			}
			hapus->next = NULL;
			free(hapus);
		}
	}
}

//del last baris
void delLastB(list *L){
	if((*L).first != NULL){
		//jika list bukan list kosong
		if(countElementB(*L) == 1){
			//list terdiri dari satu elemen
			delFirstB(L);
		}else{
			//mencari elemen terakhir list
			eBaris *last = (*L).first;
			eBaris *before_last;
			
			while(last->next != NULL){
				//iterasi
				before_last = last;
				last = last->next;
			}
			delAfterB(before_last);
		}
	}
}

//del all baris
void delAllB(list *L){
	if(countElementB(*L) != 0){
		int i;
		for(i=countElementB(*L); i>=1; i--){
			//proses menghapus elemen list
			delLastB(L);
		}
	}
}

//print elemen
void printElement(list L){
	if(L.first != NULL){
		//jika list tidak kosong
		//inisialisai
		eBaris* bantu = L.first;
		int i = 1;
		
		while(bantu != NULL){
			//proses
			printf("%c\n", bantu->kontainer.nama);
			eKolom* eCol = bantu->col;
			while(eCol != NULL){
				printf("%s\n", eCol->kontainer_kol.satu);
				eCol = eCol->next_kol;
			}
			//iterasi
			bantu = bantu->next;
			i = i+1;
		}
	}else{
		//proses jika list kosong
		printf("list kosong\n");
	}
}