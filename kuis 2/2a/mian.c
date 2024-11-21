#include "kuis2a.h"

int main(){
  stack S;
  stack T;
  stack U;
  createEmpty(&S);
  createEmpty(&T);
  createEmpty(&U);
  
  int n;
  int i;
  int tempnomor;
  char temptanda;
  
  scanf("%d", &n);
  
  for(i=0;i<n;i++){
	  scanf("%d %c", &tempnomor, &temptanda);
	  push(temptanda, tempnomor, &S);
  }
  
  //printStack(S);
  pisah(&S, &T, &U, n);
  printStack(U);
  
  return 0;
}

/*Saya Ahmad Fathi Ibrahimov mengerjakan evaluasi Quiz 2 dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
