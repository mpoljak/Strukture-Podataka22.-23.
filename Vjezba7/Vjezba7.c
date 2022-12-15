#define _CRT_SECURE_NO_WARNINGS

#define MAX_SIZE (256)
#define MAX_CHR (265)

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void red() {
	printf("\033[1;31m");
}

void cyan() {
	printf("\033[0;36m");
}

void white() {
	printf("\033[0;37m");
}

struct Directory;
typedef struct Directory *DirPosition;
typedef struct Directory {
	char name [MAX_SIZE];
	DirPosition child;
	DirPosition siblings;
}Directory;

typedef struct stack *StackPosition;
typedef struct stack {
	StackPosition Dir;
	StackPosition next;
}stack;

	DirPosition md(DirPosition, DirPosition);
	int dir(DirPosition);
	StackPosition MakeStack();
	DirPosition MakeDirectory ();
	void Remove (DirPosition);
	DirPosition ChangeDirectory(StackPosition, DirPosition);
	int PushStack(StackPosition, DirPosition);
	StackPosition PopStack(StackPosition);
	StackPosition AllocateMemoryForStack();

	int main()
	{
		int x = 1;
		char y = { 0 };

		StackPosition stack = NULL;
		DirPosition Dir = NULL, current = NULL, element = NULL;
		printf("\n  \n");
		red();
		printf("\n                             Welcome to my code! \n");
		white();
		printf("\n     Your tree is empty and you need to write the name of directory\n");
		red();
		stack = MakeStack();
		Dir = MakeDirectory();
		current = Dir;
		

		while (x)
		{
			printf("\n  \n");
			cyan();
			printf("\t\t    ______________  PLEASE CHOOSE  ______________ \n");
			white();
			printf("\n                ---------------------------------------------------  \n");
			red();
			printf("\n             *     PRESS 1:");
			white();
			printf(" MD                                      *");
			red();
			printf("\n             *     PRESS 2:");
			white();
			printf(" CD DIR                                  *");
			red();
			printf("\n             *     PRESS 3:");
			white();
			printf(" CD                                      *");
			red();
			printf("\n             *     PRESS 4:");
			white();
			printf(" DIR                                     *");
			red();
			printf("\n             *     PRESS 5:");
			white();
			printf(" TO EXIT THE PROGRAM.                    *");
			printf("\n                ___________________________________________________\n");
			scanf(" %c", &y);

			switch (y) {
			case '1':
				element = MakeDirectory();
				current->child = md(current->child, element);
				break;
			case '2':
				element = ChangeDirectory( stack,current);
				current = element;
				break;
			case '3':
				element = PopStack(current, stack);
				if (!element)
					printf("It cannot go higher than root!");
				else
					current = element;
				break;
			case '4':
				dir(current);
				break;
			case '5':
				Remove(Dir);
				x = 0;
				break;
			default:
				printf("    I'm sorry, you chose the wrong option.\n");
				printf("       TRY AGAIN!");
				break;
			}
		}
		return 0;
	}
	StackPosition MakeStack()
	{
		StackPosition newStackElement = NULL;
		newStackElement = (StackPosition)malloc(sizeof(stack));
		if (newStackElement == NULL)
		{
			printf("Can not allocate memory!\n");
			return NULL;
		}
		newStackElement->next = NULL;

		return newStackElement;
	}

	DirPosition MakeDirectory()
	{
		DirPosition newDirectory = NULL;
		newDirectory = (DirPosition)malloc(sizeof(Directory));
		if (newDirectory == NULL)
		{
			printf("Can not allocate memory!\n");
			return NULL;
		}
		newDirectory->child = NULL;
		newDirectory->siblings = NULL;

		printf("\n       INSERT NAME:");
		white();
		scanf(" %s", newDirectory->name);

		return newDirectory;
	}


	DirPosition md(DirPosition current, DirPosition element)
	{
		if (current == NULL)
			return element;

		if (strcmp(current->name, element->name) < 0)
		{
			current->siblings = md(current->siblings, element);
		}
		else if (strcmp(current->name, element->name) > 0)
		{
			element->siblings = current;
			return element;
		}
		else if (strcmp(current->name, element->name) == 0)
		{
			printf("\nThat name already exists!");
		}
		return current;
	}
	int dir(DirPosition current)
	{
		if (!current->child)
			printf("Directory is empty!\n");
		else
		{
			current = current->child;
			while (current)
			{
				printf(" %s\n", current->name);
				current = current->siblings;
			}
		}
		return 0;
	}

	void Remove(DirPosition current)
	{
		if (!current)
			return;
		remove(current->siblings);
		remove(current->child);
		free(current);
	}

	DirPosition ChangeDirectory(StackPosition stack, DirPosition current)
	{
		DirPosition q = NULL, pom = NULL;
		char  ime[MAX_CHR] = { 0 };

		printf("Enter the name of the directory you want to access:\n");
		scanf(" %s", ime);

		if (current->child == NULL)
		{
			printf("Directory is empty!\n");
			return NULL;
		}
		pom = current->child;
		while (pom != NULL)
		{
			if (strcmp(pom->name, ime) == 0)
				q = pom;
			pom = pom->siblings;
		}
		PushStack(stack, current);
		return q;
	}
	int PushStack(StackPosition stack, DirPosition current)
	{
		StackPosition q = NULL;
		q = MakeStack();
		q->Dir = current;
		q->next = stack->next;
		stack->next = q;
		return 0;
	}

	StackPosition PopStack(DirPosition current, StackPosition stackHead)
	{
		StackPosition newStackElement;
		StackPosition tempStackElement = stackHead;
		if (newStackElement = AllocateMemoryForStack())
		{
			while (tempStackElement->next)
				tempStackElement = tempStackElement->next;
			newStackElement->next = tempStackElement->next;
			tempStackElement->next = newStackElement;
			newStackElement->Dir = current;
			return 0;
		}
		else
			return 1;
	}

	StackPosition AllocateMemoryForStack()
	{
		StackPosition newStackElement = (StackPosition)malloc(sizeof(Directory));
		if (!newStackElement)
		{
			printf("Can not allocate memory!\n");
		}
		return newStackElement;
	}