#include "tmd.h"

int main(){
	tree T;
	char temp[100];
	char templagi[100];
	char tempbawaan[100];
	int i, j, ulang = 0;
	int tunjuk=0;
	int tunjuk2=0;
	int ulangbawaan;
	char ortu[100];
	
	int n;
	char parent[100];
	char child[100];
	ps=0;
	simpul *node;
	
	scanf("%d", &n);
	
	//meminta masukan disini
	for(ulang = 0; ulang < n; ulang++){
		scanf("%s", temp);
		
		//dikosongkan terlebih dahulu karena ada karakter ghoib
		for(j=0;j<100;j++){
			templagi[j]='\0';
		}
		
		for(i=0;i<2;i++){
			while(temp[tunjuk] != '#'){
				templagi[tunjuk2]=temp[tunjuk];
				tunjuk++;
				tunjuk2++;
			}
			tunjuk++;
			tunjuk2++;
			templagi[tunjuk2]='\0';//huruf setelah terakhir diberi null supaya tidak muncul yang ghoib
			tunjuk2=0;
			
			if(i==0){
				strcpy(parent, templagi);
				for(j=0;j<100;j++){
					templagi[j]='\0';
				}
			}else if(i==1){
				strcpy(child, templagi);
				for(j=0;j<100;j++){
					templagi[j]='\0';
				}
			}
		}
		
		ulangbawaan = temp[tunjuk] - '0';
		tunjuk = 0;
		tunjuk2 = 0;
		
		if(strcmp(parent, "null") == 0){
			strcpy(ortu, child);
			makeTree(child, ulangbawaan, &T);
			strcpy(pohonsementara[ps][0], parent);
			strcpy(pohonsementara[ps][1], child);
			ps++;
			
		}else{
			if(strcmp(ortu, parent) != 0){
				node = findSimpul(parent, T.root);
				if(node != NULL){
					addChild(child, ulangbawaan, node);
					strcpy(pohonsementara[ps][0], parent);
					strcpy(pohonsementara[ps][1], child);
					ps++;
				}
			}else{
				addChild(child, ulangbawaan, T.root);
				strcpy(pohonsementara[ps][0], parent);
				strcpy(pohonsementara[ps][1], child);
				ps++;
			}
		}
		
		for(j=0;j<100;j++){
			parent[j]='\0';
			child[j]='\0';
		}
	}
	//selesai meminta masukan untuk pohon
	
	//meminta masukan untuk yang mau pindah
	scanf("%d", &ppp);
	for(i=0;i<ppp;i++){
		scanf("%s %s", pohonpindah[i][0], pohonpindah[i][1]);
	}
	
	//mencetak pohon awal
	printf("pohon awal:\n\n");
	printTreePreOrder(T.root);
	
	//pindah naungan seharusnya
	for(i=0;i<ppp;i++){
		if(strcmp(pohonpindah[i][1], "mandiri")==0){
			//kalau jadi mandiri
		}else{
			pindahnaungan(pohonpindah[i][0], pohonpindah[i][1], T.root);
		}
		
	}
	
	//mencetak pohon yang sudah pindah dan mandiri
	printf("\npohon pindah naungan:\n");
	printTreePreOrder(T.root);
	
	return 0;
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi TMD dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/