#include "apc.h"

int separate_operands(char argv[], DList **head1, DList **tail1, DList **head2, DList **tail2)
{
    int i, j, data, count = 1;
    char opr1_arr[50] = {0};
    char opr2_arr[50] = {0};
    char temp_data[5] = {0};

    //printf("%s\n", argv);
    for(i = 0; i < strlen(argv); i++)
    {
	if((argv[i] != '+') && (argv[i] != '-') && (argv[i] != '*') && (argv[i] != '/'))
	{
	    opr1_arr[i] = argv[i];
	}
	else
	{
	    //opr1_arr[i] = '\0';
	    break;
	}
    }
    operator = argv[i];
    i++;

    for(j = 0; i < strlen(argv); i++, j++)
    {
	opr2_arr[j] = argv[i];
    }
    //opr2_arr[j] = '\0';
/*    if(operator == '-')
    {

	if(strlen(opr1_arr) <= strlen(opr2_arr))
	{
	    if((strlen(opr1_arr) == strlen(opr2_arr)) && (opr1_arr[0] > opr2_arr[0]))
	    {
		goto label;
	    }
	    char temp_arr[50] = {0};
	    strcpy(temp_arr, opr1_arr);
	    strcpy(opr1_arr, opr2_arr);
	    strcpy(opr2_arr, temp_arr);
	    s_flag = -1;
	}
    }	*/

    //printf("opr1 = %s, strlen = %lu\noperator = %c\nopr2 = %s, strlen = %lu\n", opr1_arr, strlen(opr1_arr), operator, opr2_arr, strlen(opr2_arr));


    /* Store opr1_arr data into double linked list */

label:for(i = (strlen(opr1_arr) - 1); i >= 0;)
      {
	  for(j = 3; count <= 4; j--)
	  {
	      if(i >= 0)
	      {
		  temp_data[j] = opr1_arr[i];
		  count++;
		  i--;
	      }
	      else
	      {
		  temp_data[j] = '0';
		  count++;
	      }
	  }
	  temp_data[4] = '\0';
	  count = 1;
	  //printf("%s\n", temp_data);

	  data = strtol(temp_data, 0, 10);
	  //printf("%d\n", data);

	  insert_at_first(head1, data, tail1);
      }


      //Store opr2_arr data into double linked list
      for(i = (strlen(opr2_arr) - 1); i >= 0;)
      {
	  for(j = 3; count <= 4; j--)
	  {
	      if(i >= 0)
	      {
		  temp_data[j] = opr2_arr[i];
		  count++;
		  i--;
	      }
	      else
	      {
		  temp_data[j] = '0';
		  count++;
	      }
	  }
	  temp_data[4] = '\0';
	  count = 1;
	  //printf("%s\n", temp_data);

	  data = strtol(temp_data, 0, 10);
	  //printf("%d\n", data);

	  insert_at_first(head2, data, tail2);
      }
}
