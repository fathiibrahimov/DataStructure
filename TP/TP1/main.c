#include "covid201.h"

/*
	Saya memasukkan skala ke array, kemudian saya sorting dan saya catat indexnya kemana saja.
	begitu diminta untuk print, saya tinggal print berdasarkan index yang sudah disorting sebagai penunjuknya.
	secara teknis ini tidak merubah index list, hanya mencari index yang urutannya benar saja kemudian di print.
	saya tidak mencontek, melainkan bertanya kepada teman saya mengenai hal ini, dan dia tidak memberikan sedikit pun kode kepada saya
	yang dia beri tahu kan juga bukan dalam bentuk kode melainkan bentuk ucapan manusia biasa saja, tidak satupun terselip sintaks kodingan.
	jika akhirnya ada kesamaan dengan teman saya, maka hal tersebut merupakan suatu bentuk ketidaksengajaan 
	karena saya mengerjakannya tanpa melihat kodingan orang lain. 
*/

int main(){
	//buat dulu listnya ya kan
	n=100;
	list L;
	createList(&L);
	
	//sebelum add ke list kita tampung sementara dulu
	int i=0;
	char temp1[100];
	int temp2;
	char urutan[5];
	
	scanf("%s", temp1);
	
	while(strcmp(temp1, "asc") !=0 && strcmp(temp1, "desc") !=0){//biar berhenti begitu bertemu dengan doi
		scanf("%d", &temp2);
		tampungan[i]=temp2;
		addLast(temp1, temp2, &L);
		scanf("%s", temp1);
		i++;
	}
	strcpy(urutan, temp1);//masukkan string terakhir, yaitu doi ke dalam urutan	
	
	if(strcmp(urutan, "asc")==0){//kalau mintanya asc
		pilah(&L);
		printsort(L);
	}else if(strcmp(urutan, "desc")==0){//kalau mintanya desc
		pilahdesc(&L);
		printsort(L);
		
	}
	
	return 0;
}
/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Tugas Praktikum 1 dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/