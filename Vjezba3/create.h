#ifndef create_h
#define create_h

#include "personStruct.h"

int create(Position q)
{
	person Head;
	Head.next = NULL;
	int x = 1;
	char c;

	printf("Write the name of the student: ");
	scanf(" %s", q->firstName);
	printf("Write the student's last name: ");
	scanf(" %s", q->lastName);
	printf("write the student's year of birth: ");
	scanf("%d", &q->birthYear);
	printf("\n----\n");

	return SUCCESS;
}

#endif