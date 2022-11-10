#ifndef readFromFile_h
#define readFromFile_h

#include "personStruct.h"

int readFromFile(Position p)
{
	FILE* fp;
	Position q = NULL;

	fp = fopen("listofstudents.txt", "r");

	if (fp == NULL) {
		printf("Dear coustomer,the file didn't open");
	}
	else {
		while (!feof(fp)) {
			q = (Position)malloc(sizeof(person));

			if (q == NULL) {
				printf("Memorija se nije alocirala!");
				return -1;
			}
			else {
				fscanf(fp, "\n %s %s %d", q->firstName, q->lastName, &q->birthYear);

				q->next = p->next;
				p->next = q;
				p = q;
			}
		}
	}

	fclose(fp);
	return SUCCESS;
}

#endif