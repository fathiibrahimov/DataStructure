#include "graf.h"

int main(){
	//membuat grafnya
	graph G;
	graph H;
	createEmpty(&G);
	createEmpty(&H);
	
	//jumlah simpul graf dan jumlah jalur
	//1 untuk graf 1, 2 untuk graf 2, 3 untuk gabungan
	int p1;
	int pj1;
	int p2;
	int pj2;
	int pj3;
	int i;//iterator
	int cekgabung=0;//untuk mengetahui apakah ada penggabungan graf atau tidak
	
	//penampungan sementara
	char temp[100];
	char temp2[100];
	
	//meminta simpul graf
	scanf("%d", &p1);
	for(i=0;i<p1;i++){
		scanf("%s", temp);
		addSimpul(temp, &G);
	}
	
	simpul *begin = findSimpul(temp, G);
	simpul *end = findSimpul(temp, G);
	
	//meminta jalur graf
	scanf("%d", &pj1);
	for(i=0;i<pj1;i++){
		scanf("%s %s", temp,temp2);
		begin = findSimpul(temp, G);
		end = findSimpul(temp2, G);
		if((begin != NULL) && (end != NULL)){
			addJalur(begin, end, 3);
		}
	}
	
	//meminta simpul graf
	scanf("%d", &p2);
	for(i=0;i<p2;i++){
		scanf("%s", temp);
		addSimpul(temp, &H);
	}
	
	//meminta simpul graf
	scanf("%d", &pj2);
	for(i=0;i<pj2;i++){
		scanf("%s %s", temp,temp2);
		begin = findSimpul(temp, H);
		end = findSimpul(temp2, H);
		if((begin != NULL) && (end != NULL)){
			addJalur(begin, end, 3);
		}
	}
	
	//meminta jalur graf tambahan
	scanf("%d", &pj3);
	for(i=0;i<pj3;i++){
		scanf("%s %s", temp,temp2);
		
		//cek satu satu, yang mana yang ditambah, kalau berbeda graf maka cekgabung bernilai true
		
		begin = findSimpul(temp, G);
		end = findSimpul(temp2, G);
		if((begin != NULL) && (end != NULL)){
			addJalur(begin, end, 3);
		}
		
		begin = findSimpul(temp, H);
		end = findSimpul(temp2, H);
		if((begin != NULL) && (end != NULL)){
			addJalur(begin, end, 3);
		}
		
		begin = findSimpul(temp, G);
		end = findSimpul(temp2, H);
		if((begin != NULL) && (end != NULL)){
			addJalur(begin, end, 3);
			cekgabung=1;
		}
		
		begin = findSimpul(temp, H);
		end = findSimpul(temp2, G);
		if((begin != NULL) && (end != NULL)){
			addJalur(begin, end, 3);
			cekgabung=1;
		}
	}
	
	//print
	if(cekgabung == 1){
		printf("Graf Gabungan:\n\n");
		printGraph(G);
		printGraph(H);
	}else{
		printf("Graf Pertama:\n\n");
		printGraph(G);
		
		printf("\nGraf Kedua:\n\n");
		printGraph(H);
	}
	
	return 0;
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi UAS dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
