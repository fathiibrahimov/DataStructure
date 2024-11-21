#include "lolbat20.h"

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
void addFirstB(char jenis[], int tahun, list *L){
	eBaris* baru;
	baru = (eBaris *) malloc (sizeof (eBaris));
	strcpy(baru->kontainer.jenis, jenis);
	baru->kontainer.tahun =  tahun;
	
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
void addFirstK(char nama[], eBaris *L){
	eKolom* baru;
	baru = (eKolom *) malloc (sizeof (eKolom));
	 
	strcpy(baru->kontainer_kol.nama, nama);
	
	if((*L).col == NULL){
		baru->next_kol = NULL;
	}else{
		baru->next_kol = (*L).col;
	}
	(*L).col = baru;
	baru = NULL;
}

//add after baris
void addAfterB(eBaris* prev, char jenis[], int tahun){
	eBaris* baru;
	baru = (eBaris *) malloc (sizeof (eBaris));
	strcpy(baru->kontainer.jenis, jenis);
	baru->kontainer.tahun =  tahun;
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
void addAfterK(eKolom* prev, char nama[]){
	eKolom* baru;
	baru = (eKolom *) malloc (sizeof (eKolom));
	 
	strcpy(baru->kontainer_kol.nama, nama);
	
	if(prev->next_kol == NULL){
		baru->next_kol = NULL;
	}else{
		baru->next_kol = prev->next_kol;
	}
	prev->next_kol = baru;
	baru = NULL;
}

//add last baris
void addLastB(char jenis[], int tahun, list *L){
	if((*L).first == NULL){
		//jika list adalah list kosong
		addFirstB(jenis, tahun, L);
	}else{
		//jika list tidak kosong
		//mencari elemen terakhir list
		eBaris *last = (*L).first;
		while(last->next !=NULL){
			//iterasi
			last = last->next;
		}
		addAfterB(last, jenis, tahun);
	}
}

//add last kolom
void addLastK(char nama[], eBaris *L){
	if((*L).col == NULL){
		//jika list adalah list kosong
		addFirstK(nama, L);
	}else{
		//jika list tidak kosong
		//mencari elemen terakhir list
		eKolom *last = (*L).col;
		while(last->next_kol !=NULL){
			//iterasi
			last = last->next_kol;
		}
		addAfterK(last, nama);
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
		
		while(bantu != NULL){
			//proses
			printf("%s ", bantu->kontainer.jenis);
			printf("%d ", bantu->kontainer.tahun);
			eKolom* eCol = bantu->col;
			while(eCol != NULL){
				printf("%s", eCol->kontainer_kol.nama);
				eCol = eCol->next_kol;
			}
			printf("\n");
			//iterasi
			bantu = bantu->next;
		}
	}else{
		//proses jika list kosong
		printf("list kosong\n");
	}
}

void pindah(list *L){
	//iterator
	int i;
	int j;
	
	char temp1[100];//untuk tampungan jenis
	
	if((*L).first != NULL){
		eBaris* bantu;
		eBaris* bantu2;
		eKolom* eCol;
		eKolom* eCol2;
		
		
		if(n>1){	
			for(i=0;i<m;i++){
				//printf("mau cari yang ini : %s\n", temp4[i]);
				bantu = (*L).first;
				bantu2 = bantu->next;
				
				while(bantu2 != NULL){
					//proses
					eCol = bantu2->col;
					 
					while(eCol != NULL){
						if(strcmp(temp4[i], eCol->kontainer_kol.nama)==0){//mencari yang sama
							//printf("ketemu\n");
							
							if(strcmp(bantu2->kontainer.jenis, "keras")==0){//kalau ada yang keras maka dibalik jadi ringan
								strcpy(temp1, "ringan");
							}else{//kalau ringan maka dibalik jadi keras
								strcpy(temp1, "keras");
							}
							addFirstB(temp1, temp5[i], L);//tambahkan untuk elemen besar
							(*L).first->col = eCol;//pindahkan elemen kecil
							bantu2->col = NULL;//hapus next elemen kecil dari elemen besar yang lama
							delAfterB(bantu);//hapus elemen besar yang lama
						}
						eCol = eCol->next_kol;//jalan terus
						
					}
					//iterasi
					bantu = bantu->next;
					bantu2 = bantu2->next;
				}
			}
		}
	}
}

void sorting(list *L){
	int i;
	if((*L).first != NULL){
		//jika list tidak kosong
		//inisialisai
		eBaris* bantu = (*L).first;
		eBaris* bantu2 = bantu->next;
		eBaris* tunjuk = (*L).first;
		eBaris* temp = (*L).first;
		
		while(bantu2 != NULL){
			//proses
			
			if(strcmp(bantu2->kontainer.jenis, "ringan")==0){//mencari yang ringan
				//yang ringan diletakkan di paling akhir
				bantu->next=bantu2->next;
				
				tunjuk = (*L).first;
				while(tunjuk->next != NULL){//mencari pointer paling akhir ada dimana
					tunjuk=tunjuk->next;
				}
				tunjuk->next=bantu2;
				bantu2->next=NULL;
			}
			
			bantu=bantu->next;
			bantu2=bantu->next;
		}
		
		while(strcmp((*L).first->kontainer.jenis, "ringan")==0){//ini kalau yang jenis ringannya ada di paling awal, karena yang sebelumnya tidak menjangkau paling awal
			
			while(tunjuk->next != NULL){
				tunjuk=tunjuk->next;
			}
			
			tunjuk->next=(*L).first;
			(*L).first=(*L).first->next;
			tunjuk->next->next=NULL;
			
		}
		
		
		
		
	}
}

void sorting2(list *L){
	int i;
	int ringan=0;
	int keras=0;
	int pindah=1;
	
	if((*L).first != NULL){
		if((*L).first != NULL){
		//jika list tidak kosong
		//inisialisai
		eBaris* bantu = (*L).first;
		eBaris* bantu2 = bantu->next;
		eBaris* bantu3 = bantu2->next;
		eBaris* tunjuk = (*L).first;
		eBaris* temp = (*L).first;
		
			while(bantu != NULL){
				if(strcmp(bantu->kontainer.jenis, "ringan")==0){
					ringan++;
				}else{
					keras++;
				}
				bantu = bantu->next;
			}
			
			while(pindah==1){
				pindah=0;
				
				if(keras==2){
					bantu = (*L).first;
					bantu2 = bantu->next;
					
					for(i=0;i<keras;i++){
						if(bantu->kontainer.tahun > bantu2->kontainer.tahun){
							pindah=1;
							if(bantu == (*L).first){
								bantu->next=bantu2->next;
								(*L).first=bantu2;
								(*L).first->next=bantu;
							}else{
								
							}
						}
					}
				}else if(keras==1){
					
				}else if(keras>2){
					bantu = (*L).first;
					bantu2 = bantu->next;
					bantu3 = bantu2->next;
					
					for(i=0;i<keras-2;i++){
						if(bantu2->kontainer.tahun > bantu3->kontainer.tahun){
							bantu2->next=bantu3->next;
							bantu->next=bantu3;
							bantu3->next=bantu2;
						}
						
					}
				}
			}
			
			
			
			
		}
		
	}
	
}

void print(list L){
	int i;
	int keras, ringan = 0;
	if(L.first != NULL){
		if(L.first != NULL){
		//jika list tidak kosong
		//inisialisai
		eBaris* bantu = L.first;
		
			while(bantu != NULL){
				if(strcmp(bantu->kontainer.jenis, "ringan")==0){
					ringan++;
				}else{
					keras++;
				}
				bantu = bantu->next;
			}
			
			bantu = L.first;
			eKolom* eCol;
			printf("- obat keras\n");
				
			for(i=0;i<keras;i++){
				printf("%d ", bantu->kontainer.tahun);
				eCol = bantu->col;
				while(eCol != NULL){
					printf("%s\n", eCol->kontainer_kol.nama);
					eCol = eCol->next_kol;
				}
				
				bantu = bantu->next;
			}
			
			printf("\n- obat ringan\n");
			for(i=0;i<ringan;i++){
				printf("%d ", bantu->kontainer.tahun);
				eCol = bantu->col;
				while(eCol != NULL){
					printf("%s\n", eCol->kontainer_kol.nama);
					eCol = eCol->next_kol;
				}
				
				bantu = bantu->next;
			}
			
			
			
			
		}
		
	}
	
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi UTS dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/