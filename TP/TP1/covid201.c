#include "covid201.h"

void createList (list *L){
	
	(*L).first = -1;
	int i;
	
	for(i=0;i<n;i++){
		//proses menginisialisasi isi array
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

void addFirst(char nama[], int skala, list *L){
	if(countElement(*L) < n){
		int baru = emptyElement(*L);
		strcpy((*L).data[baru].kontainer.nama, nama);
		(*L).data[baru].kontainer.skala = skala;
		
		if((*L).first == -1){
			//jika list kosong
			(*L).data[baru].next = -1;
		}
		else{
			//jika list tidak kosong
			(*L).data[baru].next = (*L).first;
		}
		
		(*L).first = baru;
	}
	else{
		//proses jika array penuh
		printf("sudah tidak dapat ditambah\n");
	}
}

void addAfter(int prev, char nama[], int skala, list *L){
	
	if(countElement(*L) < n){
		int baru = emptyElement(*L);
		strcpy((*L).data[baru].kontainer.nama, nama);
		(*L).data[baru].kontainer.skala = skala;
		
		if((*L).data[prev].next == -1){
			(*L).data[baru].next = -1;
		}else{
			(*L).data[baru].next = (*L).data[prev].next;
		}
		(*L).data[prev].next = baru;
	}
	else{
		//proses jika array penuh
		printf("sudah tidak dapat ditambah\n");
	}
	
}

void addLast(char nama[], int skala, list *L){
	if((*L).first == -1){
		//proses jika list masih kosong
		addFirst(nama, skala, L);
	}else{
		//proses jika list telah berisi elemen
		if(countElement(*L) < n){
			//proses jika array belum penuh
			//proses mencari elemen terakhir
			//inisialisasi
			int prev = (*L).first;
			
			while((*L).data[prev].next != -1){
				//iterasi
				prev = (*L).data[prev].next;
			}
			addAfter(prev, nama, skala, L);
		}else{
			//proses jika array penuh
			printf("sudah tidak dapat ditambah\n");
		}
	}
}

void delFirst(list *L){
	if((*L).first != -1){
		int hapus = (*L).first;
		if(countElement(*L) == 1){
			(*L).first = -1;
		}else{
			(*L).first = (*L).data[hapus].next;
		}
		//elemen awal sebelumnya dikosongkan
		(*L).data[hapus].next = -2;
	}
	else{
		//proses jika list kosong
		printf("list kosong\n");
	}
}

void delAfter(int prev, list *L){
	
	int hapus = (*L).data[prev].next;
	
	if(hapus != -1){
		if((*L).data[hapus].next == -1){
			(*L).data[prev].next = -1;
		}else{
			(*L).data[prev].next = (*L).data[hapus].next;
		}
		//pengosongan elemen
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
			int hapus = (*L).first;
			int prev;
			
			while((*L).data[hapus].next != -1){
				
				//iterasi
				prev = hapus;
				hapus = (*L).data[hapus].next;
			}
			//elemen sebelum elemen terakhir menjadi elemen terakhir
			delAfter(prev, L);
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
		int i = 1;
		
		while(tunjuk != -1){
		//proses
			printf("%s %d\n", L.data[tunjuk].kontainer.nama, L.data[tunjuk].kontainer.skala);
			printf("next : %d\n", L.data[tunjuk].next);
			//iterasi
			tunjuk = L.data[tunjuk].next;
			i=i+1;
		}
		printf("========\n");
	}
	else{
		//proses jika list kosong
		printf("list kosong\n");
		printf("========\n");
	}
}

void delAll(list *L){
	int i;
	for(i=countElement(*L);i>=1;i--){
		//proses menghapus elemen list
		delLast(L);
	}
}

void tandain(list L){
	if(L.first != -1){
		//inisialisasi
		int tunjuk = L.first;
		int i = 0;
		
		while(tunjuk != -1){//prosedur ini bakal loop terus sampai ketemu -1 buat mengindex si index
		//proses
			mark[i]= i;
			//iterasi
			tunjuk = L.data[tunjuk].next;
			i=i+1;
		}
	}
}

void pilah(list *L){//sorting skala secara asc di sini
	int i;
	int j;
	int temp2;
	int temp;
	int panjang = countElement(*L);
	tandain(*L);
	
	for(i=1;i<panjang;i++){
		//menjadikan array ke i sebagai kunci (data sisip)

		temp=tampungan[i];
		temp2 = mark[i];
		
		j=i-1;
		
		while(j>=0 && temp < tampungan[j]){
			//tukar posisi

			tampungan[j+1] = tampungan[j];
			mark[j+1] = mark[j];
			
			//j mundur 1
			j=j-1;
		}
		//menempatkan kunci pada array

		tampungan[j+1]=temp;
		mark[j+1]=temp2;
		
	}
}

void pilahdesc(list *L){//sorting skala secara desc disini
	int i;
	int j;
	int temp2;
	int temp;
	tandain(*L);
	int panjang = countElement(*L);
	
	for(i=1;i<panjang;i++){
		//menjadikan array ke i sebagai kunci (data sisip)

		temp=tampungan[i];
		temp2 = mark[i];
		
		j=i-1;
		
		while(j>=0 && temp > tampungan[j]){
			//tukar posisi

			tampungan[j+1] = tampungan[j];
			mark[j+1] = mark[j];
			
			//j mundur 1
			j=j-1;
		}
		//menempatkan kunci pada array

		tampungan[j+1]=temp;
		mark[j+1]=temp2;
		
	}
}

void printsort(list L){//print list berdasarkan sortingan
	int panjang=countElement(L);
	int i, j = panjang;
	if(L.first != -1){
		//inisialisasi
		int tunjuk = L.first;
		int i = 0;
		
		while(tunjuk != -1){
		//proses
			printf("%d. %s\n", i+1, L.data[mark[i]].kontainer.nama);
			//iterasi
			tunjuk = L.data[tunjuk].next;
			i=i+1;
		}
	}
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Tugas Praktikum 1 dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/