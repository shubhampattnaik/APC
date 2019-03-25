/*******************************************************************************************************************************************************************
*Title			: Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int addition(DList **head1, DList **tail1, DList **head2, DList **tail2, DList **headR, DList **tailR)
{
    int sum = 0, carry = 0;
    if(*head1 == NULL && *head2 == NULL)
    {
	return FAILURE;
    }

    DList *temp1 = *tail1;
    DList *temp2 = *tail2;

    while(temp1 != NULL || temp2 != NULL)
    {
	if(temp1 != NULL && temp2 != NULL)
	{
	    sum = ((temp1->data) + (temp2->data) + carry) % 10000;
	    carry = ((temp1->data) + (temp2->data) + carry) / 10000;
	    //printf("sum = %04d, carry = %d\n", sum, carry);

	    temp1 = temp1->prev;
	    temp2 = temp2->prev;
	}
	else if(temp1 == NULL && temp2 != NULL)
	{
	    sum = ((temp2->data) + carry) % 10000;
	    carry = ((temp2->data) + carry) / 10000;
	    temp2 = temp2->prev;
	}
	else if(temp1 != NULL && temp2 == NULL)
	{
	    sum = ((temp1->data) + carry) % 10000;
	    carry = ((temp1->data) + carry) / 10000;
	    temp1 = temp1->prev;
	}
	insert_at_first(headR, sum, tailR);
    }
    if(carry != 0)
    {
	insert_at_first(headR, carry, tailR);
    }
}
