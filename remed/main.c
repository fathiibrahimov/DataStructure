#include "remed.h"

int main(){
	int n;
	int i;
	tree T;
	
	char tparent[100];
	char tsimpul[100];
	int tjam;
	int tmenit;
	int tdetik;
	char arah[50];
	
	char rootnya[100];
	
	scanf("%d", &n);
	
	for(i=0;i<n;i++){
		scanf("%s %s %d %d %d %s", tparent, tsimpul, &tjam, &tmenit, &tdetik, arah);
		
		if(strcmp(tparent, "null") == 0){//untuk rootnya
			makeTree(tsimpul, tjam, tmenit, tdetik, &T);
			
			strcpy(rootnya, tsimpul);
		}
		else{//jika bukan root
			
			if(strcmp(arah, "kiri") == 0){//jika mau isi yang kiri
			
				if(strcmp(tparent, rootnya) == 0){//jika parentnya itu root
					addLeft(tsimpul, tjam, tmenit, tdetik, T.root);
				}else{//jika parentnya bukan root
					addLeftCari(tparent, tsimpul, tjam, tmenit, tdetik, T.root);
				}
			}else if(strcmp(arah, "kanan") == 0){//jika mau isi yang kanan
				
				if(strcmp(tparent, rootnya) == 0){//jika parentnya itu root
					addRight(tsimpul, tjam, tmenit, tdetik, T.root);
				}else{//jika parentnya bukan root
					addRightCari(tparent, tsimpul, tjam, tmenit, tdetik, T.root);
				}
			}
		}
		
	}
	
	cek = 0;//mengatur cek ke 0
	waktu3=0;//mengatur waktu total ke 0
	printDaun(T.root);//cetak daunnya saja
	
	printf("total: %d detik\n", waktu3);
	
	
	return 0;
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Remedial dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/