#include "kuis1.h"

int main(){
	list L;
	createList(&L);
	char temp1[100];
	
	int i;
	scanf("%d", &n);//scan berapa banyak
	
	for(i=0;i <n; i++){
		scanf("%s", temp1);
		addLast(temp1, &L);
	}
	
	carisama(L);//cari
	return 0;
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Quiz 1 dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/