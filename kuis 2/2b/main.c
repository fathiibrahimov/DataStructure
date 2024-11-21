#include "kuis2b.h"

int main(){
	queue Q;
	createEmpty(&Q);
	
	//tampungan sementara
	char temp1[50];
	char temp2[10];
	int temp3;
	
	
	scanf("%d", &n);
	int i;
	for(i=0; i<n;i++){//meminta orangnya
		scanf("%s %s %d", temp1, temp2, &temp3);
		addpriority(temp1, temp2, temp3, temp3, &Q);
	}
	
	scanf("%d", &m);
	for(i=0;i<m;i++){//meminta gelombangnya
		scanf("%d", &gelombang[i]);
	}
	
	printQueue(Q);
	

	return 0;
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Quiz 2 dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/