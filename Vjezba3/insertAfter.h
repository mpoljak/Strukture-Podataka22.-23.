#ifndef insertAfter_h
#define insertAfter_h

#include "personStruct.h"
#include "create.h"

int insertAfter(Position p)
{
	Position new = NULL;
	new = (Position)malloc(sizeof(struct _person));
	if (new == NULL)
	{
		printf("Memory allocation error!\n");
		return ERROR;
	}
	create(new);

	char last[MAX_NAME];
	printf("After which person do you want to add a new one:\n");
	scanf("%s", last);
	while (p->next != NULL && strcmp(last, p->lastName) != 0)
	{
		p = p->next;
	}
	new->next = p->next;
	p->next = new;

	printf("Person has been added!\n");
	return SUCCESS;
}

#endif