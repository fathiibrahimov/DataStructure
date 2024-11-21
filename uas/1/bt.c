#include "bt.h"

void makeTree(char c[], tree *T){//untuk membuat pohon
	simpul *baru;
	baru = (simpul *) malloc (sizeof(simpul));
	strcpy(baru->kontainer, c);
	baru->right = NULL;
	baru->left = NULL;
	(*T).root = baru;
	baru = NULL;
}

void addRight(char c[], simpul *root){//untuk menghapus child sebelah kanan
	if(root->right == NULL){
		/*jika sub pohon kanan kosong*/
		simpul *baru;
		baru = (simpul *) malloc (sizeof (simpul));
		strcpy(baru->kontainer, c);
		baru->right = NULL;
		baru->left = NULL;
		root->right = baru;
	}else{
		printf("sub pohon kanan telah terisi \n");
	}
}
 
void addLeft(char c[], simpul *root){//untuk menghapus child sebelah kiri
	if(root->left == NULL){
		/*jika sub pohon kiri kosong*/
		simpul *baru;
		baru = (simpul *) malloc (sizeof (simpul));
		strcpy(baru->kontainer, c);
		baru->right = NULL;
		baru->left = NULL;
		root->left = baru;
	}else{
		printf("sub pohon kiri telah terisi \n");
	}
}


void delAll(simpul *root){//untuk menghapus semuanya

	if(root != NULL){
		delAll(root->left);
		delAll(root->right);
		free(root);
	}
}


void delRight(simpul *root){//untuk menghapus child sebelah kanan
	if(root != NULL){
		if(root->right != NULL){
			delAll(root->right);
			root->right = NULL;
		}
	}
}

void delLeft(simpul *root){//untuk menghapus child sebelah kiri

	if(root != NULL){
		if(root->left != NULL){
			delAll(root->left);
			root->left = NULL;
		}
	}
}

void printTreePreOrder(simpul *root){//untuk mencetak secara preorder simpul kiri kanan

	if(root != NULL){
		printf("%s ", root->kontainer);
		printTreePreOrder(root->left);
		printTreePreOrder(root->right);
	}

}

void printTreeInOrder(simpul *root){//untuk mencetak secara inorder kiri simpul kanan

	if(root != NULL){
		printTreeInOrder(root->left);
		printf("%s ", root->kontainer);
		printTreeInOrder(root->right);
	}

}

void printTreePostOrder(simpul *root){//untuk mencetak secara postorder kiri kanan simpul

	if(root != NULL){
		printTreePostOrder(root->left);
		printTreePostOrder(root->right);
		printf("%s ", root->kontainer);
	}
}

void copyTree(simpul *root1, simpul **root2){//untuk copy pohon
	if(root1 != NULL){
		(*root2) = (simpul *) malloc (sizeof (simpul));
		strcpy((*root2)->kontainer, root1->kontainer);
		(*root2)->right = NULL;
		(*root2)->left = NULL;
		if(root1->left != NULL){
			copyTree(root1->left, &(*root2)->left);
		}
		if(root1->right != NULL){
			copyTree(root1->right, &(*root2)->right);
		}
	}
}


int isEqual(simpul *root1, simpul *root2){//untuk mengecek apakah sama atau tidak

	int hasil = 1;

	if((root1 != NULL)&&(root2 != NULL)){
		/* jika simpul pohon 1 dan pohon 2 sama sama tidak NULL */
		if(strcmp(root1->kontainer, root2->kontainer) != 0){
			/* jika isi kontainer simpul pohon 1 dan pohon 2 tidak sama */
			hasil = 0;
		}else{
			/* jika isi kontainer simpul pohon 1 dan simpul pohon 2 sama, maka telusuri simpul selanjutnya */
			//simpulnya dicerminkan
			if(hasil == 1){
				hasil = isEqual(root1->left, root2->right);
			}
			if(hasil == 1){
				
				hasil = isEqual(root1->right, root2->left);
			}
		}
	}else{
		if((root1 != NULL)|| (root2 != NULL)){
			/* jika salah satu simpul ada yang NULL */
			hasil = 0;
		}
	}
	
	return hasil;
}

void masuk(char parent[], char child[], char arah[], simpul *root){//prosedur untuk masukan
	//menggunakan preorder traversal untuk mencari parentnya dulu, kemudian diliat arahnya
	//baru selanjutnya dimasukkan
	if(root != NULL){
		if(strcmp(root->kontainer, parent) == 0){
			if(strcmp(arah, "kanan") == 0){
				addRight(child, root);
			}else if(strcmp(arah, "kiri") == 0){
				addLeft(child, root);
			}
		}
		masuk(parent, child, arah, root->left);
		masuk(parent, child, arah, root->right);
	}
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi UAS dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/