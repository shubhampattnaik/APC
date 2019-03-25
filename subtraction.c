/********************************************************************************************************************************************************
 *Title			: Subtraction
 *Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
 *Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
 *Input Parameters	: head1: Pointer to the first node of the first double linked list.
 : tail1: Pointer to the last node of the first double linked list.
 : head2: Pointer to the first node of the second double linked list.
 : tail2: Pointer to the last node of the second double linked list.
 : headR: Pointer to the first node of the resultant double linked list.
 *Output			: Status (SUCCESS / FAILURE)
 ********************************************************************************************************************************************************/


#include "apc.h"


int subtraction(DList **head1, DList **tail1, DList **head2, DList **tail2, DList **headR, DList **tailR)
{
    int count1 = 0, count2 = 0;

    DList *head1_temp = *head1;
    DList *head2_temp = *head2;
    DList *temp1;
    DList *temp2;

    while(head1_temp)
    {
	count1++;
	head1_temp = head1_temp->next;
    }
    while(head2_temp)
    {
	count2++;
	head2_temp = head2_temp->next;
    }

    if(count1 < count2)
    {
	temp1 = *tail2;
	temp2 = *tail1;
    }
    else
    {
	temp1 = *tail1;
	temp2 = *tail2;
    }

    int sub, borrow = 0;
    if(*head1 == NULL && *head2 == NULL)
    {
	return FAILURE;
    }


    while(temp1)
    {
	if(temp1 && temp2)
	{
	    if((temp1->data) >= (temp2->data))
	    {
		sub = ((temp1->data) - (temp2->data) - borrow);
		borrow = 0;
	    }
	    else if((temp1->data) < (temp2->data))
	    {
		sub = ((temp1->data + 10000) - (temp2->data) - borrow);
		borrow = 1;
	    }
	    insert_at_first(headR, sub, tailR);
	    temp1 = temp1->prev;
	    temp2 = temp2->prev;
	}
	else if(temp1 && !temp2)
	{
	    sub = ((temp1->data) - borrow);
	    borrow = 0;

	    insert_at_first(headR, sub, tailR);
	    temp1 = temp1->prev;
	}
    }
}
