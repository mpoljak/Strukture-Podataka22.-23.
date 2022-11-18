#ifndef Pop_h
#define Pop_h

#include "structStack.h"

int Pop(Position head, double* result) {
    Position delete = NULL;

    delete = head->next;
    if (!delete) {
        perror("\nThe stack is empty!.");
        return EMPTYSTACK;
    }

    head->next = delete->next;
    *result = delete->number;
    free(delete);

    return SUCCESS;
}
#endif