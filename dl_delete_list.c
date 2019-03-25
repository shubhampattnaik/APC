#include "apc.h"

int delete_list(DList **head, DList **tail)
{
    if(*head == NULL && *tail == NULL)
    {
	return 0;
    }


    DList *temp = (*tail)->prev;

    while(temp)
    {
	free(temp->next);
	temp = temp->prev;
    }
    free(*head);
    *head = NULL;
    *tail = NULL;
    
    return SUCCESS;
}
