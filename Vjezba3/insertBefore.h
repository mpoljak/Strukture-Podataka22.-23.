#ifndef insertBefore_h
#define insertBefore_h

#include "personStruct.h"
#include "create.h"

int insertBefore(Position p)
{
	Position prev = NULL;
	Position new = NULL;
	new = (Position)malloc(sizeof(struct _person));
	if (new == NULL)
	{
		printf("Memory allocation error!\n");
		return ERROR;
	}
	create(new);

	char last[MAX_NAME];
	printf("Before which person do you want to add a new one:\n");
	scanf("%s", &last);
	prev = p;
	while (p->next != NULL && strcmp(last, p->lastName) != 0)
	{
		prev = p;
		p = p->next;
	}
	if (p->next != NULL)
	{
		new->next = p;
		prev->next = new;
		printf("Person has been added!\n");
		return SUCCESS;
	}
}

#endif