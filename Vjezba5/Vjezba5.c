#define _CRT_SECURE_NO_WARNINGS
#define POSTFIX_ERROR (-2)
#define SUCCESS (0)
#define EMPTYSTACK (-3)
#define FILE_DIDNT_OPEN_ERROR (-1)

#include <stdio.h>
#include<stdlib.h>
#include<string.h>


#include "PostfixResult.h"
#include "readFromFile.h"
#include "Result.h"
#include "newElement.h"
#include "insertAfter.h"
#include "Pop.h"
#include "Operation.h"
#include "structStack.h"

void purple() 
{

    printf("\033[0;35m");
}

void cyan()
{
    printf("\033[0;36m");
}


void white() 
{
    printf("\033[0;37m");
}

int Postfiks(char*, double*);
int Print(Position );

int main() {
    double result = 0;

    PostfixResult("postfiks.txt", &result);
    purple();
    printf("\n RESULT:%.1lf\n", result);
    white();
    return EXIT_SUCCESS;
}

int Postfiks(char* buffer, double* result)
{
    Stack head = { .number = 0, .next = NULL };
    char* currentBuffer = buffer;
    char operation = 0;
    double number = 0.0;
    int status = 0, bytes = 0;
    Position element = NULL;

    while (strlen(currentBuffer) > 0) {
        status = sscanf(currentBuffer, " %lf %n", &number, &bytes);
        if (status != 1) {
            sscanf(currentBuffer, " %c %n", &operation, &bytes);
            status = Operation(&head, operation, result);

            if (status != EXIT_SUCCESS) {
                return POSTFIX_ERROR;
            }

            number = *result;
        }

        element = newElement(number);
        if (!element) {
            return -1;
        }

        currentBuffer += bytes;
        printf("|%s|", currentBuffer);
        purple();
        printf("  =>  ");
        white();
        insertAfter(&head, element);
    }

    return Result(&head, result);
}

int Print(Position first)
{
    Position temp = first;

    while (temp)
    {
        cyan();
        printf("%.0lf,", temp->number);
        white();
        temp = temp->next;
    }
    printf("\n");

    return 0;
}