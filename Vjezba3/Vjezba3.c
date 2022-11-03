#define _CRT_SECURE_NO_WARNINGS 
#define MAX_NAME (1024)
#define ERROR (-1)
#define SUCCESS (0)

#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
#include <conio.h>

void red() {
	printf("\033[1;31m");
}

void cyan() {
	printf("\033[0;36m");
}

void white() {
	printf("\033[0;37m");
}

struct _person;
typedef struct _person* Position;
typedef struct _person {
	char firstName[MAX_NAME];
	char lastName[MAX_NAME];
	int birthYear;
	Position next;
} person;

int create(Position );
int insertBegin(Position );
int prints(Position );
int insertEnd(Position );
int delete(Position );
int findLastName(Position );

int insertAfter(Position );
int insertBefore(Position );
int sort(Position );
int writeInFile(Position);
int readFromFile(Position);

Position findPrev(Position , char*);



int main()
{
	person Head;
	Head.next = NULL;
	int a = 1;
	char c;
	char prez[MAX_NAME] = { 0 }, dat1[MAX_NAME] = "write.txt", dat2[MAX_NAME] = "read.txt";
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
			prints(Head.next);
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


int create(Position q)
{
	printf("Write the name of the student: ");
	scanf(" %s", q->firstName);
	printf("Write the student's last name: ");
	scanf(" %s", q->lastName);
	printf("write the student's year of birth: ");
	scanf("%d", &q->birthYear);
	printf("\n----\n");

	return SUCCESS;
}


int insertBegin(Position p )
{
	Position q = NULL;
	q = (Position)malloc(sizeof(person));
	create(q);

	q->next = p->next;
	p->next = q;

	return SUCCESS;
}


int insertEnd(Position p)
{
	while (p->next != NULL)
	{
		p = p->next;
	}

	insertBegin(p);

	return SUCCESS;
}


int prints(Position p)
{
	if (p == NULL) {
		printf("The list is empty!");
		return ERROR;
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


int findLastName(Position p)
{
	char last[MAX_NAME];
	printf("write the last name of the person you want to find:\n");
	scanf("%s", &last);
	while (p != NULL && strcmp(p->lastName, last))
	{
		p = p->next;
	}

	if (p == NULL)
	{
		printf("\nThe element does not exist in the list!\n");
	}
	else
	{
		printf("\n%s %s %d\n", p->firstName, p->lastName, p->birthYear);
		printf("\n");
	};
	return SUCCESS;
}


Position findPrev(Position p, char *last)
{
	Position prev = NULL;
	prev = p;
	p = p->next;

	while (p != NULL && strcmp(p->lastName, last))
	{
		prev = p;
		p = p->next;
	}

	if (p == NULL)
	{
		printf("\nThe element does not exist in the list!\n");
		return NULL;
	}
	return prev;
}


int delete(Position p)
{
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

int insertAfter(Position p)
{
	Position new = NULL;
	new= (Position)malloc(sizeof(struct _person));
	if (new == NULL)
	{
		printf("Memory allocation error!\n");
		return ERROR;
	}
	 create(new);

	char last [MAX_NAME];
	printf("Write the last name of the person after whom you want to add a new one:\n");
	scanf("%s", last);
	while (p->next != NULL && strcmp(last, p->lastName) != 0)
	{
		p = p->next;
	}
	new->next = p->next;
	p->next = new;

	printf("Person has been added!\n");
    return SUCCESS;
}

int insertBefore(Position p)
{
	Position prev = NULL;
	Position new = NULL;
	new = (Position)malloc(sizeof(struct _person));
	if (new == NULL)
	{
		printf("Memory allocation error!\n");
		return ERROR;
	}
	create(new);

	char last[MAX_NAME];
	printf("Write the last name of the person before whom you want to add a new one::\n");
	scanf("%s", &last);
	prev = p;
	while (p->next != NULL && strcmp(last, p->lastName) != 0)
	{
		prev = p;
		p = p->next;
	}
	if (p->next != NULL)
	{
		new->next = p;
		prev->next = new;
		printf("Person has been added!\n");
		return SUCCESS;
	}
}

int sort(Position Head)
{
	Position p = NULL;
	Position q = NULL;
	Position temp = NULL;
	Position end = NULL;

	while (Head->next != end) {
		q = Head;
		p = Head->next;
		while (p->next != end) {
			if (strcmp(p->lastName, p->next->lastName) > 0) {
				temp = p->next;
				q->next = temp;
				p->next = temp->next;
				temp->next = p;
				p = temp;
			}
			q = p;
			p = p->next;
		}
		end = p;
	}
	prints(p->next);
	return SUCCESS;
}


int writeInFile(Position p)
{
	FILE* fp;

	fp = fopen("listofstudents.txt", "w");

	if (fp == NULL)
	{
		printf("Dear coustomer,the file didn't open!");
		return -1;
	}

	while (p != NULL)
	{
		fprintf(fp, "%s %s %d\n", p->firstName, p->lastName, p->birthYear);
		p = p->next;
	}

	fclose(fp);
	return SUCCESS;
}

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