/********************************************************************************************************************************************************
 *Author	: Shubham Pattnaik
 *Date		: Fri Feb 15, 20:44
 *Title		: main function(Driver function)
 *Description	: This function is used as the driver function for the all the functions
 ********************************************************************************************************************************************************/
#include "apc.h"

int main(int argc, char *argv[])
{
    /* Declare the pointers */
    DList *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL, *tailR = NULL;
    char option;
    int flag = 0;
    char *input;

    if(argc == 1)
	flag = 1;
    else
	separate_operands(argv[1], &head1, &tail1, &head2, &tail2);
    //print_list(head1);
    //print_list(head2);
    //printf("%c\n", operator);

    do
    {
	if(flag)
	{
	    delete_list(&head1, &tail1);
	    delete_list(&head2, &tail2);
	    delete_list(&headR, &tailR);
	    printf("Enter expression with operator to calculate: ");
	    fgets(input, 300, stdin);
	    input[strlen(input) - 1] = '\0';
	    separate_operands(input, &head1, &tail1, &head2, &tail2);
	}

	switch (operator)
	{
	    case '+':
		addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
		print_list(headR);
		break;
	    case '-':	
		subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
		print_list(headR);
		break;
	    case '*':	
		multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
		print_list(headR);
		break;
	    case '/':
		division(&head1, &tail1, &head2, &tail2, &headR, &tailR);
		//print_list(headR);
		break;
	    default:
		printf("Invalid Input:-( Try again...\n");
	}
	flag = 1;
	printf("Want to continue? Press [yY | nN]: ");
	scanf("%c", &option);
	while(getchar() != '\n');
    }while (option == 'y' || option == 'Y');

    return 0;
}
