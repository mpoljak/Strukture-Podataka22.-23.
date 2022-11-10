#define _CRT_SECURE_NO_WARNINGS 
#define MAX_NAME (1024)
#define ERROR (-1)
#define SUCCESS (0)
#define EMPTYLIST (-2)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "create.h"
#include "insertBegin.h"
#include "printStudents.h"
#include "insertEnd.h"
#include "delete.h"
#include "findLastName.h"
#include "findPrev.h"
#include "personStruct.h" 
#include "insertAfter.h"
#include "insertBefore.h"
#include "sort.h"
#include "writeInFile.h"
#include "readFromFile.h"

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

int insertAfter(Position);
int insertBefore(Position);
int sort(Position);
int writeInFile(Position);
int readFromFile(Position);

Position findPrev(Position, char*);



int main()
{
	person Head;
	Head.next = NULL;
	int a = 1;
	char c;
	char last[MAX_NAME] = { 0 }, dat1[MAX_NAME] = "listofstudents.txt", dat2[MAX_NAME] = "listofstudents.txt";
	Position q = NULL;
	q = (Position)malloc(sizeof(person));
	if (q == NULL)
	{
		printf("Memory allocation error!\n");
		return ERROR;
	}

	while (a)
	{
		printf("\n  \n");
		red();
		printf("\t\t  **  MENU  **");
		white();
		printf("\n ---------------------------------------------------\n");
		cyan();
		printf("\n*     PRESS 1: TO ADD A PERSON AT THE BEGINNING.    *");
		printf("\n*     PRESS 2: TO ADD A PERSON AT THE END.          *");
		printf("\n*     PRESS 3: TO FIND A PERSON IN THE LIST.        *");
		printf("\n*     PRESS 4: TO DELETE A PERSON FROM THE LIST.    *");
		printf("\n*     PRESS 5: TO PRINT THE LIST.                   *");
		printf("\n*     PRESS 6: TO ADD PERSON BEHIND PERSON.         *");
		printf("\n*     PRESS 7: TO ADD PERSON IN FRONT OF PERSON.    *");
		printf("\n*     PRESS 8: TO SORT BY LASTNAME.                 *");
		printf("\n*     PRESS 9: TO WRITE THE LIST IN THE FILE.       *");
		printf("\n*     PRESS 10:TO READ THE LIST IN THE FILE.        *");
		printf("\n*     PRESS Q:TO EXIT THE PROGRAM.                 *");


		white();
		printf("\n----------------------------------------------------\n");
		printf("\n  \n");

		printf("                                    ENTER YOUR CHOICE: ");
		scanf(" %c", &c);

		switch (c)
		{

		case '1':
			insertBegin(&Head);
			break;

		case '2':
			insertEnd(&Head);
			break;

		case '3':
			findLastName(Head.next);
			break;

		case '4':
			delete(&Head);
			break;

		case '5':
			printStudents(Head.next);
			break;
		case '6':
			insertAfter(&Head);
			break;
		case '7':
			insertBefore(&Head);
			break;

		case '8':
			sort(&Head);
			break;

		case '9':
			writeInFile(Head.next, dat1);
			break;

		case '10':
			readFromFile(Head.next, dat2);
			break;

		case 'q':
		case 'Q':
			exit(0);

		default:
			printf("Selection error!\n");
			break;
		}

	}

	return SUCCESS;
}