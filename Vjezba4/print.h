#ifndef print_h
#define print_h

#include "structPolynomial.h"

int print(Position p)
{
	if (p == NULL)
	{
		printf("The list is empty!\n");
		return EMPTYLIST;
	}

	while (p != NULL)
	{
		printf("The coefficient is: %d The exponent is: %d\n", p->coeff, p->power);
		p = p->next;
	}
	return SUCCESS;
}

#endif