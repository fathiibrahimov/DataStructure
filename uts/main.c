#include "lolbat20.h"

int main(){
	list L;
	createList(&L);
	
	
	int i;
	int j;
	
	char temp1[100];
	int temp2;
	char temp3[100];
	
	scanf("%d", &n);
	
	if(n != 0){
		scanf("%s %d %s", temp1, &temp2, temp3);
		addFirstB(temp1, temp2, &L);
		
		eBaris* bantu = L.first;

		for(i=0;i<n;i++){
			addLastK(temp3, bantu);
			
			if(i != n-1){
				scanf("%s %d %s", temp1, &temp2, temp3);
				addLastB(temp1, temp2, &L);
			}
			bantu = bantu->next;
		}
		
	}	
	
	scanf("%d", &m);
	for(i=0;i<m;i++){
		scanf("%s %d", temp4[i], &temp5[i]);
	}
	/*
	printElement(L);
	for(i=0;i<m;i++){
		printf("%s %d\n", temp4[i], temp5[i]);
	}*/
	
	pindah(&L);
	sorting(&L);
	sorting2(&L);
	print(L);
	
	return 0;
}
/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi UTS dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/