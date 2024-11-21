#include "tmstack.h"

void createEmpty(stack *S) {
  (*S).top = -1;
}

int isEmpty(stack S){
  int hasil = 0;
  if (S.top == -1) {
    hasil = 1;
  }
  return hasil;
}

int isFull(stack S){
  int hasil = 0;
  if (S.top == 9) {
    hasil = 1;
  }
  return hasil;
}

void push(char nama[], stack *S) {
  if (isFull(*S) == 1) {
    //jika stack penuh
    printf("stack penuh\n");
  }else{
    if (isEmpty(*S) == 1) {
      //jika stack kosong
      (*S).top = 0;
      strcpy((*S).data[0].nama, nama);
    }else{
      //jika stack tidak kosong
      (*S).top = (*S).top +1;
      strcpy((*S).data[(*S).top].nama, nama);
    }
  }
}

void pop(stack *S){
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

void printStack(stack S, int tanda){
	if(tanda == 1){
		printf("S1 - ");
	}else{
		printf("S2 - ");
	}
	
	if(S.top != -1){
		int i;
		int j=0;
		for(i=S.top;i>=0;i--){
			j++;
			if(i != S.top){
				printf(" ");
			}
			printf("%s", S.data[i].nama);
		}
		printf("\n");
	}else{
		/* proses jika stack kosong */
		printf("Stack Kosong\n");
	}
	
}


void popTo(stack *S, stack *T){
  if ((*S).top == 0) {
    //jika stack berisi satu elemen
	push((*S).data[(*S).top].nama, T);
    (*S).top = -1;
  }else{
    if ((*S).top != -1) {
      //jika stack tidak kosong
	  push((*S).data[(*S).top].nama, T);
      (*S).top = (*S).top - 1;
	  
    }
  }
}