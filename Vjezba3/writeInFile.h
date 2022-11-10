#ifndef sort_h
#define sort_h

#include "personStruct.h"
#include "printStudents.h"

int sort(Position Head)
{
	Position p = NULL;
	Position q = NULL;
	Position temp = NULL;
	Position end = NULL;

	while (Head->next != end) {
		q = Head;
		p = Head->next;
		while (p->next != end) {
			if (strcmp(p->lastName, p->next->lastName) > 0) {
				temp = p->next;
				q->next = temp;
				p->next = temp->next;
				temp->next = p;
				p = temp;
			}
			q = p;
			p = p->next;
		}
		end = p;
	}
	printStudents(p->next);
	return SUCCESS;
}

#endif