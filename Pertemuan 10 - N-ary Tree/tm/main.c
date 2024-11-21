#include "tm10.h"

int main(){
	tree T;
	makeTree('A', &T);
	
	printf("Langkah 1\n");
	printf("================\n");
	addChild('B', T.root);
	addChild('C', T.root);
	addChild('D', T.root);
	addChild('E',T.root->child->sibling);
	delChild('B', T.root);
	addChild('F',T.root->child);
	addChild('G',T.root->child->child);
	addChild('H',T.root);
	printTreePreOrder(T.root);
	printf("\n");
	delChild('H', T.root);
	printTreePreOrder(T.root);
	printf("\n");
	addChild('I',T.root->child->sibling);
	addChild('J',T.root->child->child);
	printTreePreOrder(T.root);
	printf("\n");
	
	printf("Langkah 2\n");
	printf("================\n");
	tree T2;

	copyTree(T.root, &T2.root);
	if(isEqual(T.root, T2.root) == 1){
		printf("Sama\n");
	}
	else{
		printf("Tidak Sama\n");
	}
	
	printf("Langkah 3\n");
	printf("================\n");
	simpul *node = findSimpul('A', T.root->child->child);
	if(node != NULL){
		printf("A ditemukan\n");
	}else{
		printf("A tidak ditemukan\n");
	}
	
	node = findSimpul('A', T.root->child->sibling->child);
	if(node != NULL){
		printf("A ditemukan\n");
	}else{
		printf("A tidak ditemukan\n");
	}
	
	node = findSimpul('A', T.root);
	if(node != NULL){
		printf("A ditemukan\n");
	}else{
		printf("A tidak ditemukan\n");
	}
	/*
	simpul *node = findSimpul('B', T.root);
	if(node != NULL){
		addChild('E', node);
		addChild('F', node);
	}

	node = findSimpul('C', T.root);
	if(node != NULL){
		addChild('G', node);
	}
	node = findSimpul('D', T.root);
	if(node != NULL){
		addChild('H', node);
		addChild('I', node);
		addChild('J', node);
	}

	node = findSimpul('J', T.root);
	if(node != NULL){
		addChild('K', node);
		addChild('L', node);
		addChild('M', node);
	}
	
	
	printf("=================\n");
	printf("preOrder\n");
	printTreePreOrder(T.root);
	printf("\n=================\n");
	printf("postOrder\n");
	printTreePostOrder(T.root);
	printf("\n=================\n");

	tree T2;

	copyTree(T.root, &T2.root);
	if(isEqual(T.root, T2.root) == 1){

		printf("pohon sama\n");
	}
	else{
		printf("pohon tidak sama\n");
	}
	node = findSimpul('J', T.root);
	if(node != NULL){
		delChild('K', node);
		delChild('L', node);
		delChild('M', node);
	}
	printf("=================\n");
	printf("preOrder setelah dihapus\n");
	printTreePreOrder(T.root);
	printf("\n=================\n");
	*/
	return 0;
}
