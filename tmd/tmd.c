#include "tmd.h"

void makeTree(char c[], int jumlah, tree *T){
	simpul *node;
	char temp[100];
	int i;
	
	node = (simpul *) malloc (sizeof(simpul));
	strcpy(node->kontainer, c);
	node->jumlahbawaan = jumlah;
	node->sibling = NULL;
	node->child = NULL;
	(*T).root = node;
	
	for(i=0;i<jumlah;i++){
		//printf("bawaan:\n");
		scanf("%s", temp);
		strcpy(node->bawaan[i], temp);
	}
}

void addChild(char c[], int jumlah, simpul *root){
	int i;
	char temp[100];
	
	if(root != NULL){
		//jika simpul root tidak kosong, berarti dapat ditambahkan simpul anak
		simpul *baru;
		baru = (simpul *) malloc (sizeof(simpul));
		strcpy(baru->kontainer, c);
		baru->child = NULL;
		baru->jumlahbawaan = jumlah;
		for(i=0;i<jumlah;i++){
			//printf("bawaan:\n");
			scanf("%s", temp);
			strcpy(baru->bawaan[i], temp);
		}

		if(root->child == NULL){
			/* jika simpul root belum memiliki simpul anak maka simpul baru menjadi anak pertama */
			baru->sibling = NULL;
			root->child = baru;
		}else{
			if(root->child->sibling == NULL){
				/* jika simpul root memiliki anak yang belum memiliki saudara, maka simpul baru menjadi anak kedua */
				baru->sibling = root->child;
				root->child->sibling = baru;
			}else{
				simpul *last = root->child;
				/*mencari simpul anak terakhir karena akan dikaitkan dengan simpul baru sebagai simpul anak terakhir yang baru,
				simpul anak terakhir adalah yang memiliki sibling simpul anak pertama, maka selama belum sampai pada simpul anak terakhir,
				penunjuk last akan berjalan ke simpul anak berikutnya */
				while(last->sibling != root->child){
					last = last->sibling;
				}
				baru->sibling = root->child;
				last->sibling = baru;
			}
		}
			
			
	}
}

void delAll(simpul *root){
  
	if(root != NULL){
		/* jika simpul root tidak kosong */
		if(root->child != NULL){
			if(root->child->sibling == NULL){
				/* jika hanya memiliki satu simpul anak */
				delAll(root->child);
				free(root);
			}else{
				simpul *bantu;
				simpul *proses;
				bantu = root->child;
				while(bantu->sibling != root->child){
					proses = bantu;
					bantu = bantu->sibling;
					delAll(proses);
				}
			}
			free(root);
		}else{
			free(root);
		}
	}
}

void delChild(char c[], simpul *root){
	if(root != NULL){
		simpul *hapus = root->child;
		if(hapus != NULL){
			if(hapus->sibling == NULL){
				/*jika hanya mempunyai satu anak*/
				if(strcmp(root->child->kontainer, c) == 0){
					delAll(root->child);
					root->child = NULL;
				}else{
					printf("tidak ada simpul anak dengan kontainer karakter masukan\n");
				}
			}else{
				/*jika memiliki lebih dari satu simpul anak*/
				simpul *prev = NULL;
				/*mencari simpul yang akan dihapus*/
				int ketemu = 0;
				while((hapus->sibling != root->child)&&(ketemu == 0)){
					if(strcmp(hapus->kontainer, c) == 0){
						ketemu = 1;
					}else{
						prev = hapus;
						hapus = hapus->sibling;
					}
				}
				/*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
				if((ketemu == 0)&&(strcmp(hapus->kontainer, c) == 0)){
					ketemu = 1;
				}
				if(ketemu == 1){
					simpul *last = root->child;
					/* mencari simpul anak terakhir untuk membantu proses atau pemeriksaan jika yang dihapus nantinya anak terakhir */
					while(last->sibling != root->child){
					last = last->sibling;
					}
					if(prev == NULL){
						/*jika simpul yang dihapus anak pertama*/
						if((hapus->sibling == last)&&(last->sibling == root->child)){
							/*jika hanya ada dua anak*/
							root->child = last;
							last->sibling = NULL;
						}
						else{
							/* jika memiliki simpul anak
							lebih dari dua simpul */
							root->child = hapus->sibling;
							last->sibling = root->child;
						}
					}else{
						if((prev == root->child) &&(last->sibling == root->child)){
							/* jika hanya ada dua simpul anak dan yang dihapus adalah simpul anak kedua */
							root->child->sibling = NULL;
						}else{
							/* jika yang dihapus bukan simpul anak pertama dan simpul root memiliki simpul anak lebih dari dua simpul */
							prev->sibling = hapus->sibling;
							hapus->sibling = NULL;
						}
					}
					delAll(hapus);
				}else{
					printf("tidak ada simpul anak dengan kontainer karakter masukan\n");
				}
			}
		}
	}
}

simpul* findSimpul(char c[], simpul *root){
	simpul *hasil = NULL;
	if(root != NULL){
		if(root->kontainer == c){
			hasil = root;
		}else{
			simpul *bantu = root->child;
			if(bantu != NULL){
				if(bantu->sibling == NULL){
					/*jika memiliki satu simpul anak*/
					if(strcmp(bantu->kontainer, c) == 0){
						hasil = bantu;
					}else{
						hasil = findSimpul(c, bantu);
					}
				}else{
					/*jika memiliki banyak simpul anak*/
					int ketemu = 0;
					while((bantu->sibling != root->child) &&(ketemu == 0)){
						if(strcmp(bantu->kontainer, c) == 0){
							hasil = bantu;
							ketemu = 1;
						}else{
							hasil = findSimpul(c, bantu);
							bantu = bantu->sibling;
							if(hasil != NULL){
								ketemu = 1;
							}
						}
					}
					/*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
					if(ketemu == 0){
						if(strcmp(bantu->kontainer, c) == 0){
							hasil = bantu;
						}else{
							hasil =	findSimpul(c, bantu);
						}
					}
				}
			}
		}
	}
	return hasil;
}

void printTreePreOrder(simpul *root){
	int i;
	if(root != NULL){
		printf("|%s\n", root->kontainer);
		for(i=0;i<root->jumlahbawaan;i++){
			printf(" %s\n", root->bawaan[i]);
		}
		
		simpul *bantu = root->child;
		
		if(bantu != NULL){
			if(bantu->sibling == NULL){
				/*jika memiliki satu simpul anak*/
				printTreePreOrder(bantu);
			}else{
				//jika memiliki banyak simpul anak
				
				//mencetak simpul anak*/
				while(bantu->sibling !=	root->child){
					printTreePreOrder(bantu);
					bantu = bantu->sibling;
					
				}
				/*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
				printTreePreOrder(bantu);
			}
		}
	}
}

void printTreePostOrder(simpul *root){
	int i;
	if(root != NULL){
		simpul *bantu = root->child;

		if(bantu != NULL){
			if(bantu->sibling == NULL){
				/*jika memiliki satu simpul anak*/
				printTreePostOrder(bantu);
			}else{
				/*jika memiliki banyak simpul anak*/

				/*mencetak simpul anak*/
				while(bantu->sibling !=root->child){
					printTreePostOrder(bantu);
					bantu = bantu->sibling;
				}
				/*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
				printTreePostOrder(bantu);
			}
		}
		printf("|%s\n", root->kontainer);
		for(i=0;i<root->jumlahbawaan;i++){
			printf("%s\n", root->bawaan[i]);
		}
	}
}

void pindahnaungan(char child[], char parent[], simpul *root){
	simpul *yangmaugantianak;//simpul yang anaknya mau pindah, jadi harus dihapus child/siblingnya
	simpul *yangmaunambahanak;//simpul tujuan yang mau pindah, jadi harus ditambah childnya
	simpul *yangmaupindah;//simpul yang mau berpindah
	int i;
	
	
	//pertama dicari dulu simpul simpulnya
	for(i=0;i<ps;i++){
		if(strcmp(child, pohonsementara[i][1]) == 0){
			yangmaugantianak = findSimpul(pohonsementara[i][0], root);//srisiam
			yangmaunambahanak = findSimpul(parent, root);//anosmum
			yangmaupindah = findSimpul(child, root);//sagodol
		}
	}

	
	if(yangmaugantianak->child->sibling == NULL){//kalau anaknya cuma satu dan itu yang mau pindah
		yangmaugantianak->child = NULL;
	}else{
		//kalau anaknya tidak cuma satu
		simpul *cari = yangmaugantianak->child;
		
		//pertama cari simpul yang sibling ke yang mau pindah
		//lalu simpul itu arahin ke sibling setelah sibling yang mau pindah
		
		
		simpul *last = yangmaugantianak->child;
		while(last->sibling != yangmaupindah){
			last = last->sibling;
		}
		if(last->sibling->sibling == last){
			yangmaugantianak->child = last;
			yangmaugantianak->child->sibling = NULL;
		}else{
			if(yangmaugantianak->child != yangmaupindah){
				last->sibling = last->sibling->sibling;
			}else{
				yangmaugantianak->child = yangmaugantianak->child->sibling;
				last->sibling = last->sibling->sibling;
				
				
			}
		}
	}
	
	//masih error
	/*
	if(yangmaunambahanak->child == NULL){
		
		yangmaunambahanak->sibling = NULL;
		yangmaunambahanak->child = yangmaupindah;
	}else{
		if(yangmaunambahanak->child->sibling == NULL){
			yangmaupindah->sibling = yangmaunambahanak->child;
			yangmaunambahanak->child->sibling = yangmaupindah;
		}else{
			simpul *last = yangmaunambahanak->child;
			while(last->sibling != yangmaunambahanak->child){
				last = last->sibling;
			}
			yangmaupindah->sibling = yangmaunambahanak->child;
			last->sibling = yangmaupindah;
		}
	}
	*/
	
}

void cetak(simpul *root){//untuk mencetak sesuai pola
	int i;
	int j;
	int panjangmax = 0;
	int akumulasi = 0;
	int posisi;
	
	if(root != NULL){
		printf("|%s\n", root->kontainer);
		
		//seharusnya pertama liat parentnya siapa, kemudian dicari yang paling panjang katanya dari simpul tersebut
		//terus berputar sampai menuju root
		//tapi masih error
		
		for(j=0;j<ps;j++){
			if(strcmp(root->kontainer, pohonsementara[j][1]) == 0){
				posisi = j;
			}
		}
		
		if(strcmp(pohonsementara[posisi][0], NULL) !=0 ){
			panjangmax = strlen(pohonsementara[posisi][0]);
		}
		
		for(i=0;i<root->jumlahbawaan;i++){
			
			printf(" %s\n", root->bawaan[i]);
		}
		
		simpul *bantu = root->child;
		
		if(bantu != NULL){
			if(bantu->sibling == NULL){
				/*jika memiliki satu simpul anak*/
				printTreePreOrder(bantu);
			}else{
				//jika memiliki banyak simpul anak
				
				//mencetak simpul anak*/
				while(bantu->sibling !=	root->child){
					printTreePreOrder(bantu);
					bantu = bantu->sibling;
					
				}
				/*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
				printTreePreOrder(bantu);
			}
		}
	}
	
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi TMD dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/