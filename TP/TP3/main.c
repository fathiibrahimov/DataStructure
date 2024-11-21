#include "tp3.h"

int main(){
	int i;//iterator
	int tawal;//tanggal maksimal
	scanf("%d", &n);
	scanf("%d", &tawal);
	
	list L;
	createList(&L);
	//penampungan sementara untuk add
	char temp1[100];
	char temp2[100];
	int temp3;
	char temp4[50];
	
	//scan
	for(i=0;i<n;i++){
		scanf("%s %s %d %s", temp1, temp2, &temp3, temp4);
		addLast(temp1, temp2, temp3, temp4, &L);
		tampungan[i]=temp3;
	}

	sorting(&L);//sorting
	caritanggal(tawal, &L);//pangkas list sesuai tanggal
	printernya(L);//print sesuai ketentuan	
	
	return 0;
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Tugas Praktikum 3 dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/