#include "kuis1.h"

void createList (list *L){
	
	(*L).first = -1;
	(*L).tail = -1;
	int i;
	
	for(i=0;i<100;i++){
		//proses menginisialisasi isi array
		(*L).data[i].prev = -2;
		(*L).data[i].next = -2;
	}
}

int countElement(list L){
	int hasil = 0;
	if(L.first != -1){
		//list tidak kosong
		int hitung;
		
		//inisialisasi
		hitung = L.first;
		
		while(hitung != -1){
			//proses
			hasil = hasil+1;
			
			//iterasi
			hitung = L.data[hitung].next;
		}
	}
	
	return hasil;
}

int emptyElement(list L){
	int hasil = -1;
	
	if(countElement(L) < 100){
		int ketemu = 0;
		int i = 0;
		while((ketemu == 0)&&(i < 100)){
			if(L.data[i].next == -2){
				hasil = i;
				ketemu = 1;
			}
			else{
				i = i +1;
			}
		}
	}
	
	return hasil;
}

void addFirst(char nama[], list *L){
	if(countElement(*L) < 100){
		int baru = emptyElement(*L);
		strcpy((*L).data[baru].kontainer.nama, nama);
		
		if((*L).first == -1){
			//jika list kosong
			(*L).data[baru].prev = -1;
			(*L).data[baru].next = -1;
			(*L).tail = baru;
		}
		else{
			//jika list tidak kosong
			(*L).data[baru].prev = -1;
			(*L).data[baru].next = (*L).first;
			(*L).data[(*L).first].prev = baru;
		}
		
		(*L).first = baru;
	}
	else{
		//proses jika array penuh
		printf("sudah tidak dapat ditambah\n");
	}
}

void addAfter(int before, char nama[], list *L){
	
	if(countElement(*L) < 100){
		int baru = emptyElement(*L);
		strcpy((*L).data[baru].kontainer.nama, nama);
		
		if((*L).data[before].next != -1){
			//jika baru bukan menjadi elemen terakhir
			(*L).data[baru].prev = before;
			(*L).data[baru].next = (*L).data[before].next;
			(*L).data[before].next = baru;
			(*L).data[(*L).data[baru].next].prev = baru;
		}else{
			//jika baru menjadi elemen terakhir
			(*L).data[baru].prev = before;
			(*L).data[before].next = baru;
			(*L).data[baru].next = -1;
			(*L).tail = baru;
		}
	}
	else{
		//proses jika array penuh
		printf("sudah tidak dapat ditambah\n");
	}
	
}

void addLast(char nama[], list *L){
	if((*L).first == -1){
		//proses jika list masih kosong
		addFirst(nama, L);
	}else{
		//proses jika list telah berisi elemen
		addAfter((*L).tail, nama, L);
	}
}

void delFirst(list *L){
	if((*L).first != -1){
		int hapus = (*L).first;
		if(countElement(*L) == 1){
			(*L).first = -1;
			(*L).tail = -1;
		}else{
			(*L).first = (*L).data[(*L).first].next;
			(*L).data[(*L).first].prev = -1;
		}
		//elemen awal sebelumnya dikosongkan
		(*L).data[hapus].prev = -2;
		(*L).data[hapus].next = -2;
	}
	else{
		//proses jika list kosong
		printf("list kosong\n");
	}
}

void delAfter(int before, list *L){
	
	int hapus = (*L).data[before].next;
	
	if(hapus != -1){
		if((*L).data[hapus].next == -1){
			(*L).tail = before;
			(*L).data[before].next = -1;
		}else{
			(*L).data[before].next = (*L).data[hapus].next;
			(*L).data[(*L).data[hapus].next].prev = before;
		}
		//pengosongan elemen
		(*L).data[hapus].prev = -2;
		(*L).data[hapus].next = -2;
	}
	
}

void delLast(list *L){
	if((*L).first != -1){
		if(countElement(*L) == 1){
			//proses jika list hanya berisi satu elemen
			delFirst(L);
		}
		else{
			
			//elemen sebelum elemen terakhir menjadi elemen terakhir
			delAfter((*L).data[(*L).tail].prev, L);
		}
		
	}else{
		//proses jika list kosong
		printf("list kosong\n");
	}
}

void printElement(list L){
	if(L.first != -1){
		//inisialisasi
		int tunjuk = L.first;
		
		while(tunjuk != -1){
		//proses
			printf("%s\n", L.data[tunjuk].kontainer.nama);
			//iterasi
			tunjuk = L.data[tunjuk].next;
		}
	}
	else{
		//proses jika list kosong
		printf("list kosong\n");
	}
}

void delAll(list *L){
	int i;
	for(i=countElement(*L);i>=1;i--){
		//proses menghapus elemen list
		delLast(L);
	}
}

void carisama(list L){
	int batas=n/2;//buat batas pencarian
	int i;//iterator
	int tunjuk1 = L.first;//penunjuk yang di kiri
	int tunjuk2 = L.tail;//penunjuk yang di kanan
	int count=0;//menghitung jumlah yang sama ada berapa
	int pertama=-1;//sentinel number buat nentuin berapa nilai yang beda pertama kali
	
	for(i=0;i<batas;i++){//loop sebanyak batas
		if(strcmp(L.data[tunjuk1].kontainer.nama, L.data[tunjuk2].kontainer.nama)==0){//kalau sama antara awal dengan akhir
			count++;//nambah itungannya
		}else{
			if(pertama==-1){//kalau ternyata ga sama, dan belum ada yang beda samsek, dia akan mengganti nilai pertama
				pertama=i;
			}
		}
		tunjuk1=L.data[tunjuk1].next;//iterator
		tunjuk2=L.data[tunjuk2].prev;
	}
	
	if(count==batas){//kalau sama semua
		printf("urutan sama\n");
	}else{//kalau tidak sama
		printf("urutan tidak sama mulai urutan ke %d\n", pertama+1);
	}
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Quiz 1 dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
