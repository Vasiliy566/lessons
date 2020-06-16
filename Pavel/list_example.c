#include <stdio.h>
#include <stdlib.h>

// Элемент списка
typedef struct element {
	int data;
	struct element * next;
} node_t;

void addElement(node_t* head, int elementData){
	node_t* tmp = head;
	// Ищем хвост
	while (tmp->next != NULL){
		tmp = tmp->next;
	}
	// Привязываем новый элемент
	tmp->next = malloc(sizeof(node_t));
	tmp->next->next = NULL;
	tmp->next->data = elementData;
}

void printAll(node_t* head){
	node_t* tmp = head;
	while(tmp != NULL){
		printf("[%d] ", tmp->data);
		tmp = tmp ->next;
	}
}

int main () {
	node_t * head = NULL;
    head = malloc(sizeof(node_t));
    head->data = 9999;
    
	if (head == NULL) {
	        return 1;
	    }
    addElement(head, 1);
    addElement(head, 2);
    addElement(head, 3);
    
    printAll(head);
	return 0;
}
