#include <stdio.h>
#include <stdlib.h>
#include "list.c"
#include "binaryTree.c"


int main (){
	// tree
	tree_node * root = NULL;
    root = malloc(sizeof(tree_node));
    root->data = 0;
    root->right = NULL;
	root->left = NULL;
	
   
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
    listAddElement(head, 2);
    listAddElement(head, 3);
    listAddElement(head, 4);
    
    printf("\nList:");
    listShowAll(head);
    
    list_node * tmp = head->next;
    while ( tmp != NULL){
    	list_node * tmp2 = head->next;
    	int times = 0;
    	while ( tmp2 != NULL){
    		if (tmp ->data == tmp2->data){
    			times ++;	
    		}
    		tmp2 = tmp2->next;	
    	}
    	if ( times >= 2 && !treeIsContains(root, tmp->data))
    		treeAddElement(root, tmp->data);
    	tmp = tmp->next;	
    }
    printf("\nTree: ");
    treeShowAll(root);
}