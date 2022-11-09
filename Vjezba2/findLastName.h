#ifndef findLastName_h
#define findLastName_h

#include "personStruct.h"

int findLastName(Position p)
{
	char last[MAX_NAME];
	printf("write the last name of the person you want to find:\n");
	scanf("%s", &last);
	while (p != NULL && strcmp(p->lastName, last))
	{
		p = p->next;
	}

	if (p == NULL)
	{
		printf("\nThe element does not exist in the list!\n");
	}
	else
	{
		printf("\n%s %s %d\n", p->firstName, p->lastName, p->birthYear);
		printf("\n");
	};
	return SUCCESS;
}

#endif