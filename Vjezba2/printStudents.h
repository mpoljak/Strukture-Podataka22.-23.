#ifndef printStudents_h
#define printStudents_h

#include "personStruct.h"

int printStudents(Position p)
{
	if (p == NULL) {
		printf("The list is empty!");
		return EMPTYLIST;
	}
	else {
		printf("\n  \n");
		printf("FIRST NAME\tLAST NAME\tBIRTH YEAR\n");

		while (p != 0) {
			printf("%-12s\t%-12s\t%-10d\t%-10.0l\n", p->firstName, p->lastName, p->birthYear);
			p = p->next;
		}
	}
	return SUCCESS;
}

#endif