#ifndef newElement_h
#define newElement_h

#include "structStack.h"

Position newElement(double number) {
    Position element = NULL;

    element = (Position)malloc(sizeof(Stack));
    if (!element) {
        perror("\nMemory allocation error!");
        return element;
    }

    element->number = number;
    element->next = NULL;

    return element;
}
#endif