#include "kuis1.h"

int main(){
	int i;//iterator
	//buat listnya
	list L;
	list K;
	createList(&L);
	createList(&K);
	
	char temp1[100];//tampung sementara masukannya
	int temp2;//sama kaya diatas
	
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%s %d", temp1, &temp2);
		addLast(temp1, temp2, &L);
	}
	scanf("%d", &m);
	for(i=0;i<m;i++){
		scanf("%s", temp3[i]);
	}
	
	pindahin(&L, &K);//pindahin
	//print deh
	printf("Isi list pertama:\n");
	printElement(L);
	printf("\n");
	printf("Isi list kedua:\n");
	printElement(K);
	
	return 0;
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Quiz 1 dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/