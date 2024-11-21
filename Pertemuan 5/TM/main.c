#include "tm5.h"

int main(){
	char temp1[100];
	char temp2[100];
	
	list L;
	createList(&L);
	
	
	scanf("%s %s", temp1, temp2);
	addFirst(temp1, temp2, &L);
	
	scanf("%s %s", temp1, temp2);
	addAfter (L.first, temp1, temp2, &L);
	
	scanf("%s %s", temp1, temp2);
	addBefore(L.first->next, temp1, temp2, &L);
	
	printElement(L);
	
	delAfter(L.first->next->prev, &L);
	
	scanf("%s %s", temp1, temp2);
	addLast(temp1, temp2, &L);
	
	printElement(L);

	delFirst(&L);
	
	scanf("%s %s", temp1, temp2);
	addLast(temp1, temp2, &L);
	
	scanf("%s %s", temp1, temp2);
	addAfter (L.first->next, temp1, temp2, &L);
	
	delLast(&L);
	
	printElementToHead(L);
	delAll(&L);
	
	printElement(L);
	
	return 0;
}