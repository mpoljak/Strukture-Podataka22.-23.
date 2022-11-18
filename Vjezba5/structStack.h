#ifndef structStack_h
#define structStack_h

struct Stack;
typedef struct Stack* Position;
typedef struct Stack {
    double number;
    Position next;
} Stack;


#endif