#include "LST120.h"

int main(){
	n=100;
	list L;
	createList(&L);
	
	char temp1[100];
	char temp2;
	int temp3;
	
	scanf("%s %c %d", temp1, &temp2, &temp3);
	addFirst(temp1, temp2, temp3, &L);
	
	scanf("%s %c %d", temp1, &temp2, &temp3);
	addFirst(temp1, temp2, temp3, &L);
	
	scanf("%s %c %d", temp1, &temp2, &temp3);
	addAfter(L.data[L.first].next, temp1, temp2, temp3, &L);
	
	printElement(L);
	
	delFirst(&L);
	
	scanf("%s %c %d", temp1, &temp2, &temp3);
	addLast(temp1, temp2, temp3, &L);
	
	delAfter(L.first, &L);
	
	printElement(L);
	
	scanf("%s %c %d", temp1, &temp2, &temp3);
	addAfter(L.first, temp1, temp2, temp3, &L);
	
	delLast(&L);
	
	printElement(L);
	
	delAll(&L);
	
	printElement(L);
	
	
	return 0;
}