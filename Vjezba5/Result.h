#pragma once

#include "structStack.h"
#include "Pop.h"

int Result(Position head, double* result) {
    int status = 0;

    status = Pop(head, result);

    if (status != 0) {
        return status;
    }
    if (head->next) {
        printf("\nIncorrect postfix.");
        return POSTFIX_ERROR;
    }

    return SUCCESS;
}
