#define _CRT_SECURE_NO_WARNINGS
#define MAX_CHR (256)
#define ALLOCATION_ERROR (-1)
#define EMPTYLIST (-2)
#define SUCCESS (0)

#include <stdio.h>
#include <stdlib.h>

#include "print.h"
#include "input.h"
#include "polynomialMultiply.h"
#include "polynomialAdd.h"
#include "structPolynomial.h"


void cyan() {
	printf("\033[0;36m");
}

void white() {
	printf("\033[0;37m");
}

void purple() {
	printf("\033[0;35m");
}



int main()
{
	char choice;
	int x = 1;
	
	struct polynomaial Head1;
	struct polynomaial Head2;
	struct polynomaial HeadA;
	struct polynomaial HeadM;

	Head1.next = NULL;
	Head2.next = NULL;
	HeadA.next = NULL;
	HeadM.next = NULL;

	while (x)
	{
		printf("\n  \n");
		cyan();
		printf("\t\t  **  MENU  **");
		cyan();
		printf("\n ---------------------------------------------------\n");
		white();
		printf("\n*     PRESS 1: TO PRINT POLYNOMIALS.                *");
		printf("\n*     PRESS 2: TO ADD  ADD POLYNOMIALS.             *");
		printf("\n*     PRESS 3: MULTIPLY POLYNOMIALS.                *");
		printf("\n*     PRESS 4:TO EXIT THE PROGRAM.                  *");
		cyan();
		printf("\n----------------------------------------------------\n");
		printf("\n  \n");
		printf("                                    ENTER YOUR CHOICE: ");

		scanf(" %c", &choice);

		switch (choice)
		{

		case '1':
			inputFirst(&Head1);
			inputSecond(&Head2);
			purple();
			printf("Polynomaial 1: \n\n");
			print(Head1.next);
			printf("\n\n");
		    printf("Polynomaial 2: \n\n");
			print(Head2.next);
			break;
		case '2':
			polynomaialAdd(Head1.next, Head2.next, &HeadA);
			purple();
			printf("Add Two Polynomials: \n\n");
			print(HeadA.next);
			break;
		case '3':
			polynomialMultiply(Head1.next, Head2.next, &HeadM);
			purple();
			printf("Multiply Two Polynomials:\n\n ");
			print(HeadM.next);
			break;
		case '4':
			exit(0);

		default:
			printf("Selection error!\n");
			break;
		}

	}

	return SUCCESS;
}