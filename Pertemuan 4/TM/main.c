#include "LGS120.h"

int main(){
	list L;
	createList(&L);
	char temp1[50];
	char temp2[50];
	char temp3[50];
	
	scanf("%s %s %s", temp1, temp2, temp3);
	addLast(temp1, temp2, temp3, &L);
	
	scanf("%s %s %s", temp1, temp2, temp3);
	addFirst(temp1, temp2, temp3, &L);
	
	printElement(L);
	
	scanf("%s %s %s", temp1, temp2, temp3);
	addAfter(L.data[L.first].next, temp1, temp2, temp3, &L);
	
	delFirst(&L);
	
	printElement(L);
	
	scanf("%s %s %s", temp1, temp2, temp3);
	addFirst(temp1, temp2, temp3, &L);
	
	delAfter(L.first, &L);
	
	printElement(L);
	
	scanf("%s %s %s", temp1, temp2, temp3);
	addFirst(temp1, temp2, temp3, &L);
	
	scanf("%s %s %s", temp1, temp2, temp3);
	addLast(temp1, temp2, temp3, &L);
	
	printElementToHead(L);
	
	delAll(&L);
	printElement(L);
	
	return 0;
}