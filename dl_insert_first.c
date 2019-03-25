#include "apc.h"

int insert_at_first(DList **head, data_t data, DList **tail)
{
    //Create new node
    DList *new = malloc(sizeof(DList));

    if(!new)
    {
	return FAILURE;
    }

    //if new node created, update data & link
    new->prev = NULL;
    new->data = data;
    new->next = NULL;

    //If list is empty, update head and tail with address of new node
    if((*head) == NULL && (*tail) == NULL)
    {
	*head = new;
	*tail = new;
	return SUCCESS;
    }
    
    //If list is not empty
    (*head)->prev = new;	//update prev address of first node
    new->next = *head;		//update next address of new node
    *head = new;		//update head with adress of new node
    return SUCCESS;
}
