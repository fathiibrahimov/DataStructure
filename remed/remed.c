#include "remed.h"

void makeTree(char mnama[], int mjam, int mmenit, int mdetik, tree *T){
	simpul *baru;
	baru = (simpul *) malloc (sizeof(simpul));
	
	strcpy(baru->nama, mnama);
	baru->jam = mjam;
	baru->menit = mmenit;
	baru->detik = mdetik;
	
	baru->right = NULL;
	baru->left = NULL;
	(*T).root = baru;
	baru = NULL;
}

void addRight(char mnama[], int mjam, int mmenit, int mdetik, simpul *root){
	if(root->right == NULL){
		/*jika sub pohon kanan kosong*/
		simpul *baru;
		baru = (simpul *) malloc (sizeof (simpul));
		strcpy(baru->nama, mnama);
		baru->jam = mjam;
		baru->menit = mmenit;
		baru->detik = mdetik;
		
		baru->right = NULL;
		baru->left = NULL;
		root->right = baru;
	}else{
		printf("sub pohon kanan telah terisi \n");
	}
}
 
void addLeft(char mnama[], int mjam, int mmenit, int mdetik, simpul *root){
	if(root->left == NULL){
		/*jika sub pohon kiri kosong*/
		simpul *baru;
		baru = (simpul *) malloc (sizeof (simpul));
		strcpy(baru->nama, mnama);
		baru->jam = mjam;
		baru->menit = mmenit;
		baru->detik = mdetik;

		baru->right = NULL;
		baru->left = NULL;
		root->left = baru;
	}
}

void addRightCari(char dicari[], char mnama[], int mjam, int mmenit, int mdetik, simpul *root){
	//jadi prosedur ini akan loop sampai menemukan simpul yang tepat, baru kemudian menambahkannya
	//menggunakan prinsip preorder traversal
	if(root != NULL){
		if(strcmp(dicari, root->nama) == 0){
			if(root->right == NULL){
				/*jika sub pohon kanan kosong*/
				simpul *baru;
				baru = (simpul *) malloc (sizeof (simpul));
				strcpy(baru->nama, mnama);
				baru->jam = mjam;
				baru->menit = mmenit;
				baru->detik = mdetik;
				
				baru->right = NULL;
				baru->left = NULL;
				root->right = baru;
			}
		}
		addRightCari(dicari, mnama, mjam, mmenit, mdetik, root->left);
		addRightCari(dicari, mnama, mjam, mmenit, mdetik, root->right);
	}
	
	
}
 
void addLeftCari(char dicari[], char mnama[], int mjam, int mmenit, int mdetik, simpul *root){
	//jadi prosedur ini akan loop sampai menemukan simpul yang tepat, baru kemudian menambahkannya
	//menggunakan prinsip preorder traversal
	if(root != NULL){
		//printf(" %c ", root->nama);
		if(strcmp(dicari, root->nama) == 0){
			if(root->left == NULL){
				/*jika sub pohon kanan kosong*/
				simpul *baru;
				baru = (simpul *) malloc (sizeof (simpul));
				strcpy(baru->nama, mnama);
				baru->jam = mjam;
				baru->menit = mmenit;
				baru->detik = mdetik;
				
				baru->right = NULL;
				baru->left = NULL;
				root->left = baru;
			}else{
				printf("sub pohon kiri telah terisi \n");
			}
		}
		addLeftCari(dicari, mnama, mjam, mmenit, mdetik, root->left);
		addLeftCari(dicari, mnama, mjam, mmenit, mdetik, root->right);
	}
}

void delAll(simpul *root){

	if(root != NULL){
		delAll(root->left);
		delAll(root->right);
		free(root);
	}
}


void delRight(simpul *root){
	if(root != NULL){
		if(root->right != NULL){
			delAll(root->right);
			root->right = NULL;
		}
	}
}

void delLeft(simpul *root){

	if(root != NULL){
		if(root->left != NULL){
			delAll(root->left);
			root->left = NULL;
		}
	}
}

void printDaun(simpul *root){
	int tempjam;
	int tempmenit;
	int tempdetik;
	
	if(root != NULL){
		
		printDaun(root->left);
		if(root->left == NULL){
			
			//hitung jumlah detik
			tempjam = 3600*root->jam;
			tempmenit = 60*root->menit;
			tempdetik = root->detik;
			
			if(cek == 1){//kalau sudah isi kanan
				waktu2 = abs(waktu1-(tempjam+tempmenit+tempdetik));
				
				printf("%s %d detik\n", root->nama, waktu2);
				waktu3 = waktu3+waktu2;
				waktu2=0;
				waktu1=0;
				cek = 0;
			}else{//kalau mau isi yang kiri
				
				waktu1 = tempjam+tempmenit+tempdetik;
				printf("%s ", root->nama);
				cek = 1;
			}
		}
		
		if(cek == 0){
			printDaun(root->right);
		}else{
			printDaun(root->right);
		}		
	}

}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Remedial dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
