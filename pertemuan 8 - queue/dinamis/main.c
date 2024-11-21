#include "queuedinamis.h"

int main(){
	queue Q;
	queue R;
	createEmpty(&Q);
	createEmpty(&R);
	char temp1[50];
	char temp2[10];
	
	scanf("%s %s", temp1, temp2);
	add(temp1, temp2, &Q);
	
	scanf("%s %s", temp1, temp2);
	add(temp1, temp2, &Q);
	
	scanf("%s %s", temp1, temp2);
	addpriority(temp1, temp2, 2, &Q);
	
	printQueue(Q);
	
	del(&Q, &R);
	
	printQueue(Q);
	printQueue2(R);
	
	scanf("%s %s", temp1, temp2);
	addpriority(temp1, temp2, 1, &Q);
	
	scanf("%s %s", temp1, temp2);
	addpriority(temp1, temp2, 99, &Q);
	
	printQueue(Q);
	
	del(&Q, &R);
	del(&Q, &R);
	
	scanf("%s %s", temp1, temp2);
	add(temp1, temp2, &Q);
	
	printQueue(Q);
	printQueue2(R);
	
	printf("******************\n");

	return 0;
}
