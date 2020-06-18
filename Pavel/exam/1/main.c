#include <stdio.h>
#include <stdlib.h>
#include "list.c"
#include "binaryTree.c"

void task1_solver(tree_node * root, list_node * head){
	if ( root -> right != NULL){
		task1_solver(root -> right, head);
	}

	if ( root -> left != NULL){
		task1_solver(root -> left, head);
	}
	
	printf("will delete %d\n", root->data);	
	listDeleteElement(head, root->data);

}

int main (){
	// tree
	tree_node * root = NULL;
    root = malloc(sizeof(tree_node));
    root->data = 0;
    root->right = NULL;
	root->left = NULL;
	treeAddElement(root, 12);
    treeAddElement(root, 2);
    treeAddElement(root, 5);
    treeAddElement(root, 22);
    treeAddElement(root, -4);
    treeAddElement(root, 7);
    treeAddElement(root, 100);
    
    printf("Tree: ");
    treeShowAll(root);
   
    // list
	list_node * head = NULL;
    head = malloc(sizeof(list_node));
    head->data = 9999;
    
	if (head == NULL) {
	        return 1;
	    }
    
    listAddElement(head, 1);
    listAddElement(head, 2);
    listAddElement(head, 3);
    listAddElement(head, 4);
    listAddElement(head, 5);

    printf("\nList:");
    listShowAll(head);
    
    task1_solver(root, head);

    printf("\nList:");
    listShowAll(head);
}