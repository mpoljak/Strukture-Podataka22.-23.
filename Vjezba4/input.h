#ifndef input_h
#define input_h

#include "structPolynomial.h"

int inputFirst(Position p)
{
	FILE* fp = NULL;
	fp = fopen("Polynomial1.txt", "r");
	if (fp == NULL)
	{
		printf("Failed to open file!\n");
		return FAILED;
	}
	while (!feof(fp))
	{
		Position q = NULL;
		q = (Position)malloc(sizeof(struct polynomaial));
		if (q == NULL)
		{
			printf("Memory allocation error!\n");
			return ALLOCATION_ERROR;
		}
		Position prev, temp;
		temp = p->next;
		prev = p;
		fscanf(fp, "%d %d", &q->coeff, &q->power);
		while (temp != NULL && (temp->power < q->power))
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = q;
		if (temp != NULL)
			q->next = temp;
		else
			q->next = NULL;
	}
	return SUCCESS;
}
int inputSecond(Position p)
{
	FILE* fp = NULL;
	fp = fopen("Polynomial2.txt", "r");
	if (fp == NULL)
	{
		printf("Failed to open file!\n");
		return FAILED;
	}
	while (!feof(fp))
	{
		Position q = NULL;
		q = (Position)malloc(sizeof(struct polynomaial));
		if (q == NULL)
		{
			printf("Memory allocation error!\n");
			return ALLOCATION_ERROR;
		}
		Position prev, temp;
		temp = p->next;
		prev = p;
		fscanf(fp, "%d %d", &q->coeff, &q->power);
		while (temp != NULL && temp->power < q->power)
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = q;
		if (temp != NULL)
			q->next = temp;
		else
			q->next = NULL;
	}
	return SUCCESS;
}

#endif
