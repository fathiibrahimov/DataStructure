#include "kuis2a.h"

void createEmpty(stack *S) {//membuat stack
  (*S).top = -1;
}

int isEmpty(stack S){//mengecek apakah kosong stacknya
  int hasil = 0;
  if (S.top == -1) {
    hasil = 1;
  }
  return hasil;
}

int isFull(stack S){//mengecek apakah penuh stacknya
  int hasil = 0;
  if (S.top == 59) {
    hasil = 1;
  }
  return hasil;
}

void push(char tanda, int nomor, stack *S) {//push data
  if (isFull(*S) == 1) {
    //jika stack penuh
    printf("stack penuh\n");
  }else{
    if (isEmpty(*S) == 1) {
      //jika stack kosong
      (*S).top = 0;
	  (*S).data[0].tanda = tanda;
	  (*S).data[0].nomor = nomor;
    }else{
      //jika stack tidak kosong
      (*S).top = (*S).top +1;
	  (*S).data[(*S).top].tanda = tanda;
	  (*S).data[(*S).top].nomor = nomor;
    }
  }
}

void pop(stack *S){//pop data
  
  if ((*S).top == 0) {
    //jika stack berisi satu elemen
	
    (*S).top = -1;
  }else{
    if ((*S).top != -1) {
      //jika stack tidak kosong
      (*S).top = (*S).top - 1;
    }
  }
}

void printStack(stack S){//mencetak isi stack
  if(S.top != -1){
    int i;
	for(i=S.top;i>=0;i--){
    
    printf("%d ", S.data[i].nomor);
    printf("%c\n", S.data[i].tanda);
  }
  }else{
    /* proses jika stack kosong */
    printf("stack kosong\n");
  }
}

void popTo(stack *S, stack *T){//pop ke stack sebelah
  if ((*S).top == 0) {
    //jika stack berisi satu elemen
	push((*S).data[(*S).top].tanda, (*S).data[(*S).top].nomor, T);
    (*S).top = -1;
  }else{
    if ((*S).top != -1) {
      //jika stack tidak kosong
	  push((*S).data[(*S).top].tanda, (*S).data[(*S).top].nomor, T);
      (*S).top = (*S).top - 1;
	  
    }
  }
}

int sama(char c1, char c2){ //mengecek pasangan
    if (c1 == '(' && c2 == ')'){ 
		return 1; 
	}else if (c1 == '{' && c2 == '}') {
        return 1; 
	}else{
        return 0;
	}		
} 

void pisah(stack *S, stack *T, stack *U, int n){//memisahkan yang berpasangan
	int i;
	
	for(i=0; i<=(*S).top; i++){//memisahkan yang titik koma dulu
		if(((*S).data[i].tanda == '{') || ((*S).data[i].tanda == '(')){
			push((*S).data[i].tanda, (*S).data[i].nomor, T);
		}
		
		if(((*S).data[i].tanda == '}') || ((*S).data[i].tanda == ')')){
			if(isEmpty(*S)==1){
				push((*S).data[i].tanda, (*S).data[i].nomor, U);
			}else if(sama((*T).top, (*S).data[i].tanda)){
				push((*S).data[i].tanda, (*S).data[i].nomor, U);
				pop(T);
			}
		}
	}
	 
	
	
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Quiz 2 dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
