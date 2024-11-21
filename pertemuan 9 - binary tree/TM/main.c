#include "tm9.h"

int main(){
	tree T;
	tree U;
	char temp;
	char temp2;
	
	scanf(" %c", &temp);
	makeTree('A', &T); 
	
	scanf(" %c", &temp);
	addLeft(temp, T.root);
	
	scanf(" %c", &temp);
	addRight(temp,T.root);
	
	scanf(" %c", &temp);
	addLeft(temp,T.root->right);
	
	scanf(" %c", &temp);
	addRight(temp,T.root->left);
	
	scanf(" %c", &temp);
	addRight(temp,T.root->right);
	
	scanf(" %c", &temp);
	addLeft(temp,T.root->left->right);
	
	scanf(" %c", &temp);
	addRight(temp,T.root->right->left);
	
	scanf(" %c", &temp);
	addRight(temp,T.root->left->right);
	
	scanf(" %c", &temp);
	addRight(temp,T.root->right->right);
	
	scanf(" %c", &temp);
	addLeft(temp,T.root->right->right);
	
	scanf(" %c", &temp);
	addLeft(temp,T.root->left->right->left);
	
	scanf(" %c", &temp);
	addLeft(temp,T.root->right->left->right);
	
	scanf(" %c", &temp);
	addRight(temp,T.root->right->left->right);
	
	printf("Pre Order:\n");
	printTreePreOrder(T.root); 
	printf("\n");

	delLeft(T.root->left->right->left);//L Hilang
	printf("In Order:\n");
	printTreeInOrder(T.root); 
	printf("\n");

	delRight(T.root->right->right);//J Terhapus 
	printf("Post Order:\n");
	printTreePostOrder(T.root); 
	printf("\n");

	return 0;
}
