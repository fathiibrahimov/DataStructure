#include "tp3.h"

void createList (list *L){//buat list
	
	(*L).first = -1;
	(*L).tail = -1;
	int i;
	
	for(i=0;i<n;i++){
		//proses menginisialisasi isi array
		(*L).data[i].prev = -2;
		(*L).data[i].next = -2;
	}
}

int countElement(list L){////buat ngehitung elemen
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

int emptyElement(list L){//buat elemen kosong
	int hasil = -1;
	
	if(countElement(L) < n){
		int ketemu = 0;
		int i = 0;
		while((ketemu == 0)&&(i < n)){
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

void addFirst(char judul[], char nama[], int nilai, char genre[], list *L){//tambah diawal
	if(countElement(*L) < n){
		int baru = emptyElement(*L);
		strcpy((*L).data[baru].kontainer.judul, judul);
		strcpy((*L).data[baru].kontainer.nama, nama);
		(*L).data[baru].kontainer.nilai = nilai;
		strcpy((*L).data[baru].kontainer.genre, genre);
		
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

void addAfter(int before, char judul[], char nama[], int nilai, char genre[], list *L){//tambah setelah
	
	if(countElement(*L) < n){
		int baru = emptyElement(*L);
		strcpy((*L).data[baru].kontainer.judul, judul);
		strcpy((*L).data[baru].kontainer.nama, nama);
		(*L).data[baru].kontainer.nilai = nilai;
		strcpy((*L).data[baru].kontainer.genre, genre);
		
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

void addLast(char judul[], char nama[], int nilai, char genre[], list *L){//tambah diakhir
	if((*L).first == -1){
		//proses jika list masih kosong
		addFirst(judul, nama, nilai, genre, L);
	}else{
		//proses jika list telah berisi elemen
		addAfter((*L).tail, judul, nama, nilai, genre, L);
	}
}

void delFirst(list *L){//hapus awal
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

void delAfter(int before, list *L){//hapus setelah	
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

void delLast(list *L){//hapus yang akhir
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

void printElement(list L){//print elemen secara benar dari awal
	if(L.first != -1){
		//inisialisasi
		int tunjuk = L.first;
		int i = 1;
		
		while(tunjuk != -1){
		//proses
			printf("%s ", L.data[tunjuk].kontainer.judul);
			printf("%s\n", L.data[tunjuk].kontainer.nama);
			//printf("%d ", L.data[tunjuk].kontainer.nilai);
			//printf("%s\n", L.data[tunjuk].kontainer.genre);
			//iterasi
			tunjuk = L.data[tunjuk].next;
			i=i+1;
		}
	}
}

void printElementToHead(list L){//print elemen dari tail
	if(L.first != -1){
		//inisialisasi
		int tunjuk = L.tail;//mulai dari tail
		int i = 1;
		
		while(tunjuk != L.first){
		//proses
			printf("%s ", L.data[tunjuk].kontainer.judul);
			printf("%s\n", L.data[tunjuk].kontainer.nama);
			//printf("%d ", L.data[tunjuk].kontainer.nilai);
			//printf("%s\n", L.data[tunjuk].kontainer.genre);
			//iterasi
			tunjuk = L.data[tunjuk].prev;
			i=i+1;
		}
		//print yang ketinggalan
		printf("%s ", L.data[tunjuk].kontainer.judul);
		printf("%s\n", L.data[tunjuk].kontainer.nama);
		//printf("%d ", L.data[tunjuk].kontainer.nilai);
		//printf("%s\n", L.data[tunjuk].kontainer.genre);
	}
	
}

void delAll(list *L){
	int i;
	for(i=countElement(*L);i>=1;i--){
		//proses menghapus elemen list
		delLast(L);
	}
}

void sorting(list *L){//sorting disini
	int pindah = 1;//buat tau apa perlu pindah
	while(pindah == 1){
		pindah = 0; 
		int tunjuk = (*L).first;
		int tunjuk2 = (*L).data[tunjuk].next;
		while(tunjuk2 >= 0){
			if((*L).data[tunjuk].kontainer.nilai > (*L).data[tunjuk2].kontainer.nilai){
				if(tunjuk == (*L).first){//kalau ada diujung kiri
					(*L).first = tunjuk2;
				}else{
					(*L).data[(*L).data[tunjuk].prev].next = tunjuk2;
				}
				if(tunjuk2 == (*L).tail){//kalau ada diujung kanan
					(*L).tail = tunjuk;
				}else{
					(*L).data[(*L).data[tunjuk2].next].prev = tunjuk;
				}
				//oper mang
				(*L).data[tunjuk].next = (*L).data[tunjuk2].next;
				(*L).data[tunjuk2].next = tunjuk;
				(*L).data[tunjuk2].prev = (*L).data[tunjuk].prev;
				(*L).data[tunjuk].prev = tunjuk2;
				
				pindah = 1;
				tunjuk2 = (*L).data[tunjuk].next;
			}else{
				tunjuk = tunjuk2;
				tunjuk2 = (*L).data[tunjuk2].next; 
			}
		}
	}
}

void caritanggal(int tawal, list *L){//pangkas list disini
	int tanda=tawal-14;//kurangin 14
	if(tanda < 1){//kalau kalau tanggalnya dibawah 14 kan gak valid tanggalnya, makanya di set ke satu saja
		tanda=1;
	}
	int count=0;
	if((*L).first != -1){
		//inisialisasi
		int tunjuk = (*L).first;
		int i = 1;
		
		while(tunjuk != -1){//cari satu satu yang kecil disini
		//proses
			if((*L).data[tunjuk].kontainer.nilai < tanda){//kalau lama banget lagunya dipangkas, langsung taro ke first
				(*L).first=(*L).data[tunjuk].next;
			}
			//iterasi
			tunjuk = (*L).data[tunjuk].next;
			i=i+1;
		}
	}
}

void printernya(list L){//print sesuai ketentuan
	if(L.first != -1){//kalau ada isinya
		printf("=== DAFTAR LAGU ===\n");
		printElement(L);
		printf("=== LAGU TERBARU ===\n");
		printElementToHead(L);
	}else{//kalau ga ada isinya
		printf("Tidak ada lagu terbaru.\n");
	}
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Tugas Praktikum 3 dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/