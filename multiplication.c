/*******************************************************************************************************************************************************************
 *Title			: Multiplication
 *Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
 *Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
 *Input Parameters	: head1: Pointer to the first node of the first double linked list.
 : tail1: Pointer to the last node of the first double linked list.
 : head2: Pointer to the first node of the second double linked list.
 : tail2: Pointer to the last node of the second double linked list.
 : headR: Pointer to the first node of the resultant double linked list.
 *Output			: Status (SUCCESS / FAILURE)
 *******************************************************************************************************************************************************************/
#include "apc.h"

int multiplication(DList **head1, DList **tail1, DList **head2, DList **tail2, DList **headR, DList **tailR)
{
    int pro = 0, carry = 0, flag = 0, k = 0, i;

    if(*head1 == NULL && *head2 ==NULL)
    {
	return FAILURE;
    }

    DList *temphead1 = NULL;
    DList *temptail1 = NULL;

    DList *temphead2 = NULL;
    DList *temptail2 = NULL;

    DList *temphead3 = NULL;
    DList *temptail3 = NULL;
    
    DList *temp1 = *tail1;
    DList *temp2 = *tail2;

    while(temp2)
    {
	pro = 0;
	carry = 0;

	while(temp1)
	{
	    pro = (((temp1->data) * (temp2->data)) + carry) % 10000;
	    carry = (((temp1->data) * (temp2->data)) + carry) / 10000;

	    printf("pro = %d, carry = %d\n", pro, carry);


	    insert_at_first(&temphead1, pro, &temptail1);


	    temp1 = temp1->prev;
	}

	if(carry != 0)
	    insert_at_first(&temphead1, carry, &temptail1);

	for(i = 0; i < k; i++)
	{
	    insert_at_last(&temphead2, 0, &temptail2);
	}

	//	print_list(temphead1);
	//	print_list(temphead2);

	if(!flag)	
	    addition(&temphead1, &temptail1, &temphead2, &temptail2, &temphead3, &temptail3);
	else	
	    addition(&temphead3, &temptail3, &temphead2, &temptail2, headR, tailR);
	k++;
	temp2 = temp2->prev;
	temp1 = *tail1;
	temphead1 = temptail1 = NULL;
	flag = 1;

    }
    print_list(temphead3);

}
