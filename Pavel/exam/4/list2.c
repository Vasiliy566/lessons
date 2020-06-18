#include <stdio.h>
#include <stdlib.h>

// Элемент списка
typedef struct element 
{
	int data;
	struct element * next;
} node_t;

void addElement(node_t* head, int elementData)
{
	node_t* tmp = head;
	// Ищем хвост
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	// Привязываем новый элемент
	tmp->next = malloc(sizeof(node_t));
	tmp->next->next = NULL;
	tmp->next->data = elementData;
}

void printAll(node_t* head)
{
	node_t* tmp = head;
	while(tmp != NULL)
	{
		printf("[%d] ", tmp->data);
		tmp = tmp ->next;
	}
}

int main () 
{
	node_t * head = NULL;
    head = malloc(sizeof(node_t));
    head->data = 9999;
    
	if (head == NULL) 
	{
	        return 1;
	}
    addElement(head, 1);
    addElement(head, 2);
    addElement(head, 3);
    

	node_t * head2 = NULL;
	head2 = malloc(sizeof(node_t));
	head2->data = 8888;

	if (head2 == NULL)
	{
		return 2;
	}
	addElement(head2, 4);
	addElement(head2, 5);
	addElement(head2, 6);

	node_t * tmp = head;
	node_t * tmp2 = head2;
	while (tmp != NULL && tmp2 != NULL)
	{
		printf("%d ", (tmp->data + tmp2->data));
		tmp = tmp->next;
		tmp2 = tmp2->next;

	}
}
