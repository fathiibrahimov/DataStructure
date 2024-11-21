#include "tmstack.h"

int main(){
  stack S;
  stack T;
  createEmpty(&S);
  createEmpty(&T);
  
  char temp[100];
  
  printStack(S, 1);
  printStack(T, 2);
  
  scanf("%s", temp);
  push(temp, &S);
  
  scanf("%s", temp);
  push(temp, &T);
  
  printStack(S, 1);
  printStack(T, 2);
  
  pop(&S);
  popTo(&T, &S);
  
  scanf("%s", temp);
  push(temp, &S);
  
  scanf("%s", temp);
  push(temp, &S);
  
  scanf("%s", temp);
  push(temp, &T);
  
  popTo(&S, &T);
  
  printStack(S, 1);
  printStack(T, 2);
  
  return 0;
}
