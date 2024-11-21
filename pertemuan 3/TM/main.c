#include "tm.h"

int main(){
	//untuk menampung sementara
	char temp1[100];
	char temp2[100];
	char temp3[10];
	
	list L;
	createList(&L);//buat listnya
	
	scanf("%s %s %s", temp1, temp2, temp3);
	addFirst(temp1, temp2, temp3, &L);
	
	scanf("%s %s %s", temp1, temp2, temp3);
	addLast(temp1, temp2, temp3, &L);
	
	
	scanf("%s %s %s", temp1, temp2, temp3);
	addFirst(temp1, temp2, temp3, &L);
	
	
	printElement(L);
	
	scanf("%s %s %s", temp1, temp2, temp3);
	addAfter(L.first->next, temp1, temp2, temp3, &L);
	
	printElement(L);
	
	delAfter(L.first->next, &L);
	
	scanf("%s %s %s", temp1, temp2, temp3);
	addLast(temp1, temp2, temp3, &L);
	
	printElement(L);
	
	delFirst(&L);
	
	delLast(&L);
	
	printElement(L);
	
	delAll(&L);
	
	printf("=====\n");
	printElement(L);
	
	scanf("%s %s %s", temp1, temp2, temp3);
	addLast(temp1, temp2, temp3, &L);
	
	printElement(L);
	printf("=====\n");
	
	return 0;
}