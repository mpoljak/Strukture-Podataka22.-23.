#ifndef polynomialMultiply_h
#define polynomialMultiply_h

#include "structPolynomial.h"

int polynomialMultiply(Position p1, Position p2, Position r)
{
	Position first = p1->next;
	Position second = p2->next;
	struct polynomaial P;
	Position s = NULL;
	s = (Position)malloc(sizeof(struct polynomaial));
	if (s == NULL)
	{
		printf("Memory allocation error!\n");
		return ALLOCATION_ERROR;
	}
	s->next = NULL;
	P.next = s;
	while (first != NULL)
	{
		second = p2->next;
		while (second != NULL)
		{

			s->coeff = first->coeff * second->coeff;
			s->power = first->power + second->power;
			polynomaialAdd(&P, r, r);

			second = second->next;
		}
		first = first->next;
	}

	return SUCCESS;
}

#endif