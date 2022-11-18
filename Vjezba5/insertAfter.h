#pragma once
#include "structStack.h"

int insertAfter(Position head, Position element)
{
    element->next = head->next;
    head->next = element;

    Print(head->next);

    return SUCCESS;
}
