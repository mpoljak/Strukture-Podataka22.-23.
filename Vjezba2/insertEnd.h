#ifndef insertEnd_h
#define insertEnd_h

#include "personStruct.h"

int insertEnd(Position p)
{
	while (p->next != NULL)
	{
		p = p->next;
	}

	insertBegin(p);

	return SUCCESS;
}

#endif