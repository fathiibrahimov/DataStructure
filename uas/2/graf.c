#include "graf.h"

void createEmpty(graph *G){
	(*G).first = NULL;
}

void addSimpul(char c[], graph *G){//menambahkan simpul
	simpul *baru;
	baru = (simpul *) malloc (sizeof (simpul));
	strcpy(baru->kontainer, c);
	baru->next = NULL;
	baru->arc = NULL;

	if((*G).first == NULL){
		/*jika graf kosong*/
		(*G).first = baru;
	}
	else{
		/*menambahkan simpul baru pada akhir graph*/
		simpul *last = (*G).first;
		while(last->next != NULL){
			last = last->next;
		}
		last->next = baru;
	}
}

void addJalur(simpul *awal, simpul *tujuan, int beban){//menambahkan jalur

	jalur *baru;
	baru = (jalur *) malloc (sizeof (jalur));
	baru->kontainer_jalur = beban;
	baru->next_jalur = NULL;
	baru->tujuan = tujuan;

	if(awal->arc == NULL){
		/*jika list jalur kosong*/
		awal->arc = baru;
	}else{
		/*menambahkan jalur baru pada akhir list jalur*/
		jalur *last = awal->arc;
		while(last->next_jalur != NULL){
			last = last->next_jalur;
		}
		last->next_jalur = baru;
	}
}

simpul* findSimpul(char c[], graph G){//menemukan suatu simpul

	simpul *hasil = NULL;
	simpul *bantu = G.first;

	int ketemu = 0;
	while((bantu != NULL) && (ketemu == 0)){
		if(strcmp(bantu->kontainer, c) == 0){
			hasil = bantu; ketemu = 1;
		}else{
			bantu = bantu->next;
		}
	}
	return hasil;
}


void delJalur(char ctujuan[], simpul *awal){//menghapus jalur
	jalur *hapus = awal->arc;
	if(hapus != NULL){
		jalur *prev = NULL;
		/*mencari jalur yang akan dihapus*/
		int ketemu = 0;
		while((hapus != NULL) && (ketemu == 0)){
			if(strcpy(hapus->tujuan->kontainer, ctujuan) == 0){
				ketemu = 1;
			}else{
				prev = hapus;
				hapus = hapus->next_jalur;
			}
		}
		if(ketemu == 1){
			if(prev == NULL){
				/*hapus jalur pertama*/
				awal->arc = hapus->next_jalur;
				hapus->next_jalur = NULL;
			}else{
				if(hapus->next_jalur == NULL){
					/*hapus jalur terakhir*/
					prev->next_jalur = NULL;
				}else{
					/*hapus jalur di tengah*/
					prev->next_jalur = hapus->next_jalur;
					hapus->next_jalur = NULL;
				}
			}
			free(hapus);
		}else{
			printf("tidak ada jalur dengan simpul tujuan\n");
		}
	}else{
		printf("tidak ada jalur dengan simpul tujuan\n");
	}
}

void delAll(simpul *awal){//menghapus semua
	jalur *bantu; bantu = awal->arc;
	jalur *hapus;

	while(bantu != NULL){
		hapus = bantu;
		bantu = bantu->next_jalur;
		awal->arc = bantu;
		hapus->next_jalur = NULL;
		free(hapus);
	}
}

void delSimpul(char c[], graph *G){//menghapus simpul
	simpul *hapus = (*G).first;
	if(hapus != NULL){

		simpul *prev = NULL;

		/*mencari simpul yang akan dihapus*/ int ketemu = 0;
		while((hapus != NULL) && (ketemu == 0)){
			if(hapus->kontainer == c){
				ketemu = 1;
			}else{
				prev = hapus;
				hapus = hapus->next;
			}
		}
		if(ketemu == 1){
			/* jika simpul yang akan dihapus ada */
			/* hapus semua jalur dari simpul lain yang mengarah pada simpul yang dihapus */
			simpul *bantu; bantu = (*G).first;
			/* memeriksa semua simpul dalam graf */
			while(bantu != NULL){
				/* jika simpul yang ditelusuri tidak sama dengan yang dihapus */
				if(bantu != hapus){
					/* hapus semua jalur yang mengarah pada simpul yang dihapus */
					delJalur(hapus->kontainer, bantu);
				}
				bantu = bantu->next;
			}
			/* hapus semua jalur */
			delAll(hapus);
			if(prev == NULL){
				/*hapus simpul pertama*/
				(*G).first = hapus->next;
				hapus->next = NULL;
			}else{
				if(hapus->next == NULL){
					/*hapus simpul terakhir*/
					prev->next = NULL;
				}else{
					/*hapus simpul di tengah*/
					prev->next = hapus->next;
					hapus->next = NULL;
				}
			}
			free(hapus);
		}else{
			printf("tidak ada simpul dengan info karakter masukan\n");
		}
	}else{
		printf("tidak ada simpul dengan info karakter masukan\n");
	}
}

void printGraph(graph G){//mencetak output jalur pada graf
	simpul *bantu = G.first;

	if(bantu != NULL){
		while(bantu != NULL){
			printf("%s\n", bantu->kontainer);
			jalur *bantu_jalur = bantu->arc;
			while(bantu_jalur != NULL){
				printf("- jalur ke %s\n", bantu_jalur->tujuan->kontainer);
				bantu_jalur = bantu_jalur->next_jalur;
			}
			bantu = bantu->next;
		}
	}else{
		printf("graf kosong\n");
	}
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi UAS dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
