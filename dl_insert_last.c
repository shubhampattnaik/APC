#include "apc.h"

int insert_at_last(DList **head, data_t data, DList **tail)
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

    //if list is empty, update head and tail with adress of nwe node
    if(*head == NULL && *tail == NULL)
    {
	*tail = new;
	*head = new;
	return SUCCESS;
    }

    //if list is not empty
    (*tail)->next = new;	//update last node's next with address of new
    new->prev = *tail;		//update new's prev with address of last node
    *tail = new;		//update tail with address of new node
    
    return SUCCESS;
}
