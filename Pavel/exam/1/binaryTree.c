#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct tree_element {
	int data;
	struct tree_element * right;
	struct tree_element * left;
} tree_node;

void treeAddElement(tree_node * root, int data){
	
	if (data > root->data){
		if (root->right == NULL){
			tree_node * newElement = NULL;
		    newElement = malloc(sizeof(tree_node));
		    newElement->right = NULL;
		    newElement->left = NULL;
		    newElement->data = data;
		    root->right = newElement;
		}
		else {
			treeAddElement(root->right, data);
		}
	}
	if (data <= root->data){
		if (root->left == NULL){
			tree_node * newElement = NULL;
		    newElement = malloc(sizeof(tree_node));
		    newElement->right = NULL;
		    newElement->left = NULL;
		    newElement->data = data;
		    root->left = newElement;
		}
		else {
			treeAddElement(root->left, data);
		}
	}
}

void treeShowAll(tree_node * root){
	if ( root -> right != NULL){
		treeShowAll(root -> right);
	}
	
	printf("%d, ", root->data);
	
	if ( root -> left != NULL){
		treeShowAll(root -> left);
	}

}
bool treeIsContains(tree_node * root, int value){
	tree_node * tmp = root;
	bool res = false;
	while (root != NULL){
		if (value == tmp->data ){
			return true;
		}
		if (value > tmp->data){
			if ( tmp->right == NULL){
				return false;
			}
			else {tmp = tmp->right;}
		}
		if (value < tmp->data){
			if ( tmp->left == NULL){
				return false;
			}
			else {tmp = tmp->left;}
		} 
	}
}

// int main (){
// 	tree_node * head = NULL;
//     head = malloc(sizeof(tree_node));
//     head->data = 0;
//     head->right = NULL;
// 	head->left = NULL;
// 	addElement(head, 12);
//     addElement(head, -2);
//     addElement(head, 5);
//     addElement(head, 22);
//     addElement(head, -4);
//     addElement(head, 7);
//     addElement(head, 100);
    
//     showAll(head);
//     printf("\n****************\n");

// }