#include "tp7.h"

void createEmpty(queue *Q){//buat queue kosong
	(*Q).first = NULL;//atur null semuanya
	(*Q).last = NULL;
}

int isEmpty(queue Q){//mengecek apakah queue kosong
	int hasil = 0;
	if(Q.first == NULL){
		hasil = 1;
	}
	return hasil;
}

int countElement(queue Q){//menghitung jumlah elemen dalam queue
	int hasil = 0;
	if(Q.first != NULL){
		/* queue tidak kosong */
		elemen* bantu;
		/* inisialisasi */
		bantu = Q.first;
		while(bantu != NULL){
			/* proses */
			hasil= hasil + 1;

			/* iterasi */
			bantu = bantu->next;
		}
	}
	return hasil;
}

void add(char nama[], char nilai[], int jam, queue *Q ){//enqueue
	elemen* baru;
	baru = (elemen *) malloc (sizeof (elemen));
	strcpy(baru->kontainer.nama, nama);
	strcpy(baru->kontainer.nilai, nilai);
	baru->kontainer.jam = jam;
	baru->next = NULL;
	
	if((*Q).first == NULL){
		(*Q).first = baru;
	}else{
		(*Q).last->next = baru;
	}
	(*Q).last = baru;
	baru = NULL;
}

void addpriority(char nama[], char nilai[], int jam, int prioritas, queue *Q ){//enqueue dengan prioritas
	int i;
	
	elemen* baru;
	baru = (elemen *) malloc (sizeof (elemen));
	strcpy(baru->kontainer.nama, nama);
	strcpy(baru->kontainer.nilai, nilai);
	baru->kontainer.jam = jam;
	baru->next = NULL;

	if(countElement(*Q) < prioritas){//kalau prioritas melebihi banyaknya elemen dalam queue
 		if((*Q).first == NULL){
 			(*Q).first = baru;
 		}else{ 
 			(*Q).last->next = baru;
 		}
 		(*Q).last = baru;
 		baru = NULL;
 	}else{//kalau prioritas tidak melebihi banyaknya elemen dalam queue
		elemen* bantu = (*Q).first;
		elemen* bantu2 = NULL;
		i=1;
		
		while(bantu != NULL && i < prioritas){
			
			bantu2 = bantu;
			bantu = bantu->next;
			i = i+1;
		}
		
		baru->next = bantu;
		if(bantu2 == NULL){
			(*Q).first = baru;
		}else{
			bantu2->next = baru;
		}
		
	}
}

void del(queue *Q){//dequeue
	if((*Q).first != NULL){
		/* jika queue bukan queue kosong */
		elemen *hapus = (*Q).first;
		
		if(countElement(*Q) == 1){
			(*Q).first = NULL;
			(*Q).last = NULL;
		}else{
			(*Q).first = (*Q).first->next; hapus->next = NULL;
		}

	free(hapus);
	}
}

void printQueue(queue Q){//hanya untuk mengetes apakah sudah terurut atau belum, tidak dipakai dalam soal ini

	if(Q.first != NULL){
		printf("******************\n");

		elemen* bantu = Q.first;
		int i = 1;
		while(bantu != NULL){
			printf("%s ", bantu->kontainer.nama);
			printf("%s ", bantu->kontainer.nilai);
			printf("%d\n", bantu->kontainer.jam);
			/* iterasi */
			bantu = bantu->next;
			i = i + 1;
		}
	}else{
		/* proses jika queue kosong */
		printf("queue kosong\n");
	}
}

void ganti(char nama[], char nilai[], int jam, queue *Q){//mengecek harus masuk prioritas keberapa
	if(strcmp(nilai, "Gold")==0){//jika golden
		//update posisi prioritas yang terpengaruh
		//karena gold, maka silver dan bronze otomatis posisinya mundur
		a++;
		b++;
		c++;
		addpriority(nama, nilai, jam, a, Q);//enqueue
	}else if(strcmp(nilai, "Silver")==0){//jika silver
		//karena silver, maka bronze otomatis posisinya mundur
		b++;
		c++;
		addpriority(nama, nilai, jam, b, Q);//enqueue
	}else if(strcmp(nilai, "Bronze")==0){//jika bronze
		c++;//tidak ada yang terpengaruh, hanya bronze yang mundur sendiri
		addpriority(nama, nilai, jam, c, Q);
	}else if(strcmp(nilai, "Reguler")==0){//jika tidak punya tiket prioritas
		add(nama, nilai, jam, Q);
	}
}

void printoutput(queue Q){//cetak sesuai permintaan soal
	int tunggu=0;//waktu menunggu yang dinanti
	elemen* bantu = Q.first;
	
	//mencari sampai ketemu yang mau dilihat waktu tunggunya sembari nambah nambahin jamnya
	while(strcmp(bantu->kontainer.nama, carinama) != 0){
		tunggu = tunggu + bantu->kontainer.jam;
		bantu = bantu->next;
	}
	
	tunggu = tunggu + bantu->kontainer.jam;//tambah jamnya karena yang mau diliat belum ketambah
	
	//cetak
	printf("%s mengantri selama %d\n", carinama, tunggu);
	printf("Daftar orang setelahnya:\n");
	
	bantu = bantu->next;//pindah ke sebelah
	if(bantu == NULL){//kalau ternyata sudah tidak ada lagi orang yang menunggu
		printf("Tidak Ada Data.\n");
	}else{//kalau ada yang menunggu setelah yang dicari cari
		while(bantu != NULL){//terus muter sampai ketemu null dan cetak namanya
			printf("%s\n", bantu->kontainer.nama);
			/* iterasi */
			bantu = bantu->next;
		}
	}
	
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Tugas Praktikum 7 dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/