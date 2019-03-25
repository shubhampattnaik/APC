/*******************************************************************************************************************************************************************
 *Title			: Division
 *Description		: This function performs division of two given large numbers and store the result in the resultant list.
 *Prototype		: int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
 *Input Parameters	: head1: Pointer to the first node of the first double linked list.
 : tail1: Pointer to the last node of the first double linked list.
 : head2: Pointer to the first node of the second double linked list.
 : tail2: Pointer to the last node of the second double linked list.
 : headR: Pointer to the first node of the resultant double linked list.
 *Output			: Status (SUCCESS / FAILURE)
 *******************************************************************************************************************************************************************/
#include "apc.h"


int division(DList **head1, DList **tail1, DList **head2, DList **tail2, DList **headR, DList **tailR)
{

    int count1 = 0, count2 = 0, count = 0;
    DList *tail11 = *tail1;
    DList *tail22 = *tail2;

    while(tail11->data > -1)
    {
	//printf("In while loop %d, tail11->data %d\n", count, tail11->data);
	//if(count == 1000000001)
	  //  return 0;


	DList *tail1_temp = *tail1;
	DList *tail2_temp = *tail2;
	DList *temp1;
	DList *temp2;

	while(tail1_temp)
	{
	    count1++;
	    tail1_temp = tail1_temp->prev;
	}
	while(tail2_temp)
	{
	    count2++;
	    tail2_temp = tail2_temp->prev;
	}

	if(count1 < count2)
	{
	    temp1 = tail22;
	    temp2 = tail11;
	}
	else
	{
	    temp1 = tail11;
	    temp2 = tail22;
	}

	int sub, borrow = 0;
	if(*head1 == NULL && *head2 == NULL)
	{
	    return FAILURE;
	}

	//printf("temp1->data %d, temp2->data %d\n", temp1->data, temp2->data);


	while(temp1)
	{
	    //printf("in\n");
	    if(temp1 && temp2)
	    {
		if((temp1->data) >= (temp2->data))
		{
		    //printf("test0\n");
		    if(temp1->prev && temp2->prev)
		    {
			if((temp1->prev->prev == NULL) && (temp1->prev->data < temp2->prev->data))
			{
			    //printf("test1\n");
			    sub = (((temp1->prev->data * 10000) + temp1->data) - ((temp2->prev->data * 10000) + temp2->data) - borrow);
			    borrow = 0;
			    //printf("test2\n");
			    temp1 = temp1->prev;
			    //printf("test3\n");
			    temp2 = temp2->prev;
			    //printf("->-> %d\n", sub);
			}
			else
			{
			    sub = ((temp1->data) - (temp2->data) - borrow);
			    borrow = 0;
			}
		    }
		    else
		    {
			sub = ((temp1->data) - (temp2->data) - borrow);
			borrow = 0;
		    }
		}
		else if((temp1->data) < (temp2->data))
		{
		    if(temp1->prev)
		    {
			sub = ((temp1->data + 10000) - (temp2->data) - borrow);
		    }
		    else
		    {
			sub = ((temp1->data) - (temp2->data) - borrow);
		    }
		    borrow = 1;
		}
		/*if((temp1->prev == NULL) && (borrow == 1))
		  {
		  sub = sub * (-1);
		  borrow = 0;
		  }*/
		insert_at_first(headR, sub, tailR);
		temp1 = temp1->prev;
		temp2 = temp2->prev;
	    }
	    else if(temp1 && !temp2)
	    {
		sub = ((temp1->data) - borrow);
		/*if((temp1->prev == NULL) && (borrow == 1))
		  {
		  sub = sub * (-1);
		  borrow = 0;
		  }*/
		if((temp1->prev == NULL) && (sub == 0))
		{
		    goto l1;
		}
		insert_at_first(headR, sub, tailR);
l1:	temp1 = temp1->prev;
	    }
	    //printf("Sub = %d\n", sub);
	} //subtraction completed here
	//print_list(*headR);
	//printf("In mid\n");

	count++;

	//printf("temp2->data %d\n", temp2->data);
	tail11 = *tailR;
	tail22 = *tail2;

	*headR = NULL;
	*tailR = NULL;
	//printf("tail11->data %d, tail22->data %d\n", tail11->data, tail22->data);

	//printf("End\n");
    }
    printf("COUNT = %d\n", --count);
}
