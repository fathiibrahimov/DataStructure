#include "LOL120.h"

int main(){
	list L;
	createList(&L);
	int i;
	int j;
	int n;
	char temp1;
	char temp2[50];
	char temp3[50];
	char temp4[50];
	char temp5[50];
	
	scanf("%d", &n);
	
	scanf(" %c", &temp1);
	addLastB(temp1, &L);
	
	eBaris* bantu = L.first;
	
	for(i=0;i<n;i++){
		
		scanf("%s", temp2);
		addLastK(temp2, bantu);
		
		scanf("%s", temp3);
		addFirstK(temp3, bantu);
		

		scanf("%s", temp4);
		addAfterK(bantu->col, temp4);
		
		scanf("%s", temp5);
		addFirstK(temp5, bantu);
			
		
		if(i != n-1){
			scanf(" %c", &temp1);
			addLastB(temp1, &L);
		}
		
		bantu = bantu->next;

	}
	
	
	printElement(L);
	
	return 0;
}