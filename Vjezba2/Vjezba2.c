#define _CRT_SECURE_NO_WARNINGS 
#define MAX_NAME (1024)
#define ALLOCATION_ERROR (-1)
#define SUCCESS (0)
#define EMPTYLIST (-2)

#include <stdio.h>
#include <stdlib.h>
#include  <string.h>

#include "create.h"
#include "insertBegin.h"
#include "printStudents.h"
#include "insertEnd.h"
#include "delete.h"
#include "findLastName.h"
#include "findPrev.h"
#include "personStruct.h"

void red() {
	printf("\033[1;31m");
}

void cyan() {
	printf("\033[0;36m");
}

void white() {
	printf("\033[0;37m");
}

int create(Position);
int insertBegin(Position);
int printStudents(Position);
int insertEnd(Position);
int delete(Position);
int findLastName(Position);
Position findPrev(Position, char*);



int main()
{
	person Head;
	Head.next = NULL;
	int x = 1;
	char c;
	Position q = NULL;

	q = (Position)malloc(sizeof(person));
	if (q == NULL)
	{
		printf("Memory allocation error!\n");
		return ALLOCATION_ERROR;
	}

	while (x)
	{
		printf("\n  \n");
		red();
		printf("\t\t  **  MENU  **");
		cyan();
		printf("\n ---------------------------------------------------\n");
		white();
		printf("\n*     PRESS A: TO ADD A PERSON AT THE BEGINNING.    *");
		printf("\n*     PRESS B: TO ADD A PERSON AT THE END.          *");
		printf("\n*     PRESS C: TO FIND A PERSON IN THE LIST.        *");
		printf("\n*     PRESS D: TO DELETE A PERSON FROM THE LIST.    *");
		printf("\n*     PRESS E: TO PRINT THE LIST.                   *");
		printf("\n*     PRESS F:TO EXIT THE PROGRAM.                  *");
		cyan();
		printf("\n----------------------------------------------------\n");
		printf("\n  \n");
		printf("                                    ENTER YOUR CHOICE: ");

		scanf(" %c", &c);

		switch (c)
		{

		case 'a':
		case 'A':
			insertBegin(&Head);
			break;

		case 'b':
		case 'B':
			insertEnd(&Head);
			break;

		case 'c':
		case 'C':
			findLastName(Head.next);
			break;

		case 'd':
		case 'D':
			delete(&Head);
			break;

		case 'e':
		case 'E':
			printStudents(Head.next);
			break;

		case 'f':
		case 'F':
			exit(0);

		default:
			printf("Selection error!\n");
			break;
		}

	}

	return SUCCESS;
}