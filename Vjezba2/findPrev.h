#ifndef findPrev_h
#define findPrev_h

#include "personStruct.h"

Position findPrev(Position p, char* last){

	Position prev = NULL;
	prev = p;
	p = p->next;

	while (p != NULL && strcmp(p->lastName, last))
	{
		prev = p;
		p = p->next;
	}

	if (p == NULL)
	{
		printf("\nThe element does not exist in the list!\n");
		return NULL;
	}
	return prev;
}

#endif