#include "graf.h"

int main(){
	graph G;
	createEmpty(&G);
	addSimpul('A', &G);
	addSimpul('B', &G);
	addSimpul('C', &G);
	addSimpul('D', &G);
	addSimpul('E', &G);
	addSimpul('F', &G);
	
	char temp;
	scanf(" %c", &temp);


	simpul *begin = findSimpul('A', G);
	simpul *end = findSimpul('B', G);
	if((begin != NULL) && (end != NULL)){
		addJalur(begin, end, 3);
	}
	
	begin = findSimpul('B', G);
	end = findSimpul('C', G);
	if((begin != NULL) && (end != NULL)){
		addJalur(begin, end, 3);
	}
	
	begin = findSimpul('B', G);
	end = findSimpul('E', G);
	if((begin != NULL) && (end != NULL)){
		addJalur(begin, end, 3);
	}

	begin = findSimpul('C', G);
	end = findSimpul('D', G);
	if((begin != NULL) && (end != NULL)){
		addJalur(begin, end, 3);
	}
	
	begin = findSimpul('D', G);
	end = findSimpul('F', G);
	if((begin != NULL)  && (end != NULL)){
		addJalur(begin, end, 8);
	}
	
	printGraph(G);
	
	delSimpul(temp, &G);
	printf("-----\n");
	printGraph(G);


	return 0;
}
