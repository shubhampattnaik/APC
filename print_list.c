#include "apc.h"

int print_list(DList *head)
{
    //if list is empty
    if(head == NULL)
    {
	printf("List is empty! \n");
	return FAILURE;
    }

    //temp will point to first node
    DList *temp = head;

    //traverse till end node and print data of each node
    printf("Result:  ");
    if(s_flag == -1)
	printf("-");
    while (temp)
    {
	printf("%.4d", temp->data);
	temp = temp->next;
    }
    
    printf("\n");
    return SUCCESS;
}
