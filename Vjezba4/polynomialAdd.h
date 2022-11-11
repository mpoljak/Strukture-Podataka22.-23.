#ifndef polynomialAdd_h
#define polynomialAdd_h

#include "structPolynomial.h"

int polynomaialAdd(Position p1, Position p2, Position r) {
	while (p1->next != NULL && p2->next != NULL)
	{
		Position s = NULL;
		s = (Position)malloc(sizeof(struct polynomaial));
		if (s == NULL)
		{
			printf("Memory allocation error!\n");
			return ALLOCATION_ERROR;
		}
		s->next = NULL;

		if (p1->next->power < p2->next->power)
		{
			s->power = p1->next->power;
			s->coeff = p1->next->coeff;
			p1 = p1->next;
		}
		else if (p1->next->power > p2->next->power)
		{
			s->power = p2->next->power;
			s->coeff = p2->next->coeff;
			p2 = p2->next;
		}
		else
		{
			s->power = p1->next->power;
			s->coeff = (p1->next->coeff + p2->next->coeff);
			p1 = p1->next;
			p2 = p2->next;
		}
		r->next = s;
		r = s;
	}
	Position temp;
	if (p1->next == NULL)
		temp = p2->next;
	else
		temp = p1->next;
	while (temp != NULL)
	{
		Position s = NULL;
		s = (Position)malloc(sizeof(struct polynomaial));
		if (s == NULL)
		{
			printf("Memory allocation error!\n");
			return ALLOCATION_ERROR;
		}
		s->next = NULL;
		s->power = temp->power;
		s->coeff = temp->coeff;
		r->next = s;
		r = s;
		temp = temp->next;
	}
	return SUCCESS;
}

#endif