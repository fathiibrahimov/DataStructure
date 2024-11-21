#include "bt.h"

int main(){	
	//menanam pohon
	tree T;
	tree U;
	
	//tampungan sementara untuk input
	char temp[100];//child
	char tempp[100];//parent
	char tempc[100];//arah
	int p1;//jumlah node di pohon1
	int p2;//jumlah node di pohon2
	int i;//iterator
	
	//pertama kali buat pohonnya dulu, minta satu masukan
	scanf("%d", &p1);
	if(p1 > 0){
		scanf("%s %s %s", tempp, temp, tempc);
		makeTree(temp, &T);
	}
	
	//meminta masukan setelah masukan pertama
	for(i=1;i<p1;i++){
		scanf("%s %s %s", tempp, temp, tempc);
		masuk(tempp, temp, tempc, T.root);
	}
	
	//sama seperti diatas, untuk pohon 2
	scanf("%d", &p2);
	if(p2 > 0){
		scanf("%s %s %s", tempp, temp, tempc);
		makeTree(temp, &U);
	}
	
	for(i=1;i<p2;i++){
		scanf("%s %s %s", tempp, temp, tempc);
		masuk(tempp, temp, tempc, U.root);
	}
	
	//mengecek apakah sama
	if(isEqual(T.root, U.root) == 1){
		printf("pohon pertama cerminan pohon kedua\n");
	}else{
		printf("pohon pertama bukan cerminan pohon kedua\n");
	}
	
	return 0;
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi UAS dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/