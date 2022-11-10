#ifndef insertBegin_h
#define insertBegin_h

#include "personStruct.h"

int insertBegin(Position p)
{
	Position q = NULL;

	q = (Position)malloc(sizeof(person));

	create(q);

	q->next = p->next;
	p->next = q;

	return SUCCESS;
}

#endif