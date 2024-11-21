#include "kuis1.h"

void createList (list *L){
	(*L).first = NULL;
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

void addFirst(char makan[], int harga, list *L){
	elemen* baru;
	baru = (elemen*) malloc (sizeof (elemen));
	strcpy(baru->kontainer.makan, makan);
	baru->kontainer.harga = harga;
	
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

void addAfter(elemen* prev, char makan[], int harga, list *L){
	elemen* baru;
	baru = (elemen*) malloc (sizeof (elemen));
	
	strcpy(baru->kontainer.makan, makan);
	baru->kontainer.harga = harga;
		
	if(prev->next == NULL){
		baru->next = NULL;
	}else{
		baru->next = prev->next;
	}
	prev->next = baru;
	baru=NULL;
	
}

void addLast(char makan[], int harga, list *L){
	if((*L).first == NULL){
		//proses jika list masih kosong
		addFirst(makan, harga, L);
	}else{
		//proses jika list telah berisi elemen
		elemen* prev = (*L).first;
		while(prev->next != NULL){
		//iterasi
		prev = prev->next;
		}
		addAfter(prev, makan, harga, L);
	}
}

void delFirst(list *L){
	if((*L).first != NULL){
		//jika list bukan list kosong
		elemen* hapus = (*L).first;
		if(countElement(*L) == 1){
			(*L).first = NULL;
		}else{
			(*L).first = (*L).first->next;
			hapus->next = NULL;
		}
		free(hapus);
	}
}

void delAfter(elemen* prev, list *L){
	elemen* hapus = prev->next;
	if(hapus != NULL){
		if(hapus->next == NULL){
			prev->next = NULL;
		}else{
			prev->next = hapus->next;
			hapus->next = NULL;
		}
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

void printElement(list L){
	if(L.first != NULL){
		//inisialisasi
		elemen* tunjuk = L.first;
		int i = 1;
		
		while(tunjuk != NULL){
		//proses
			printf("%s ", tunjuk->kontainer.makan);
			printf("%d\n", tunjuk->kontainer.harga);
			//iterasi
			tunjuk = tunjuk->next;
			i=i+1;
		}
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


void pindahin(list *L, list *K){
	int i, j =0;
	int found=0;
	if((*L).first != NULL){
		if(countElement(*L) > 1){//kasus kalau listnya lebih dari 1, biar gak run error
			//inisialisasi
			elemen* tunjuk = (*L).first;//buat penanda delAfter
			elemen* tunjuk2 = tunjuk->next;//buat penanda yang mau dipindah
			
			for(i=0;i<m;i++){//mengakses semua yang ada di temp3 aka yang mau dipindah
				j=0;
				found=0;
				tunjuk = (*L).first;
				tunjuk2 = tunjuk->next;
				while(tunjuk2 != NULL && found==0){//mencari di list apakah ada yang sama
					j++;
					if(strcmp(temp3[i], tunjuk2->kontainer.makan)==0){//kalau ada yang sama
						if(tunjuk2->next == NULL){//kalau yang samanya ada di ujung akhir
							addLast(tunjuk2->kontainer.makan, tunjuk2->kontainer.harga, K);
							delLast(L);//hapus akhir aja
							found=1;//break while
						}else{//kalau yang sama adanya di tengah
							addLast(tunjuk2->kontainer.makan, tunjuk2->kontainer.harga, K);
							delAfter(tunjuk, L);//delete setelah
							found=1;//break while
						}
					}
					tunjuk = tunjuk->next;
					tunjuk2 = tunjuk2->next;

				}
			}
			//ini cari apa di head ada yang sama atau nggak, kalau sama dia bakal addFirst ke list sebelah
			found=0;
			tunjuk = (*L).first;
			while(tunjuk != NULL && found==0){
				for(i=0;i<m;i++){
					if(strcmp(temp3[i], tunjuk->kontainer.makan)==0){
						addFirst(tunjuk->kontainer.makan, tunjuk->kontainer.harga, K);
						delFirst(L);
						found=1;
					}
				}
				tunjuk = tunjuk->next;
			}
		}else{//ini kasus kalau cuma ada satu elemen di listnya			
			elemen* tunjuk = (*L).first;
			int i;
			for(i=0;i<m;i++){
				if(strcmp(temp3[i], tunjuk->kontainer.makan)==0){
					
					addLast(tunjuk->kontainer.makan, tunjuk->kontainer.harga, K);
					delAll(L);
				}
			}
		}
	}
	
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Quiz 1 dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/