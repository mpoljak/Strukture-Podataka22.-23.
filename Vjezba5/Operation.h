#ifndef Operation_h
#define Operation_h

#include "structStack.h"

int Operation(Position head, char operation, double* result) {
    double operand1 = 0;
    double operand2 = 0;
    int status1 = 0;
    int status2 = 0;

    status1 = Pop(head, &operand1);
    if (status1 != 0) {
        return POSTFIX_ERROR;
    }

    status2 = Pop(head, &operand2);
    if (status2 != 0) {
        return POSTFIX_ERROR;
    }

    switch (operation)
    {
    case '+':
        *result = operand2 + operand1;
        break;
    case '-':
        *result = operand2 - operand1;
        break;
    case '*':
        *result = operand2 * operand1;
        break;
    case '/':
        *result = operand2 / operand1;
        break;
    default:
        printf("\nIncorrect postfix operand.", operation);
        return EXIT_FAILURE;
    }

    return SUCCESS;

}
#endif