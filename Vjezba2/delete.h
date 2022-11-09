#ifndef delete_h
#define delete_h

#include "personStruct.h"
#include "findPrev.h"

int delete(Position p) {
	Position prev = NULL;
	char last[MAX_NAME];
	printf("Write the last name of the person you want to delete:\n");
	scanf("%s", &last);
	prev = findPrev(p, last);

	if (prev != NULL)
	{
		p = prev->next;
		prev->next = p->next;
		free(p);
		printf("\n The student is deleted: %s\n", last);
	}

	return SUCCESS;
}

#endif