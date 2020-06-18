#include <stdio.h>
#include <stdlib.h>

// Элемент списка
typedef struct list_element {
	int data;
	struct list_element * next;
} list_node;

void listAddElement(list_node* head, int elementData){
	list_node* tmp = head;
	// Ищем хвост
	while (tmp->next != NULL){
		tmp = tmp->next;
	}
	// Привязываем новый элемент
	tmp->next = malloc(sizeof(list_node));
	tmp->next->next = NULL;
	tmp->next->data = elementData;
}

void listDeleteElement(list_node* head, int value){
	list_node * tmp = head;
	if (tmp->next != NULL){
		while ( tmp ->next != NULL && tmp->next->data != value){
			tmp = tmp->next;
		}	
		if (tmp->next != NULL){
			list_node * tmp2 = tmp->next;
			tmp->next = tmp2->next;
			free(tmp2);
		}
	}
}

void listShowAll(list_node* head){
	list_node* tmp = head -> next;
	while(tmp != NULL){
		printf("[%d] ", tmp->data);
		tmp = tmp ->next;
	}
}

// int main () {
// 	list_node * head = NULL;
//     head = malloc(sizeof(list_node));
//     head->data = 9999;
    
// 	if (head == NULL) {
// 	        return 1;
// 	    }
    
//     addElement(head, 1);
//     addElement(head, 2);
//     addElement(head, 3);
    


//     /*TUT 



//     */

//     //printAll(head);
// 	return 0;
// }
