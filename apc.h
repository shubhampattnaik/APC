#ifndef APC_H
#define APC_H
#define SUCCESS 0
#define FAILURE -1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
}DList;
char operator;
int s_flag;

/* Function prototypes */
int separate_operands(char argv[], DList **head1, DList **tail1, DList **head2, DList **tail2);
int addition(DList **, DList **, DList **, DList **, DList **, DList **);
int subtraction(DList **, DList **, DList **, DList **, DList **, DList **);
int multiplication(DList **, DList **, DList **, DList **, DList **, DList **);
int division(DList **, DList **, DList **, DList **, DList **, DList **);
int insert_at_first(DList **, data_t, DList **);
int insert_at_last(DList **, data_t, DList **);
int delete_list(DList **, DList **);
int print_list(DList *head);

#endif
