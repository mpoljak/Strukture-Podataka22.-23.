#ifndef personStruct_h
#define personStruct_h

struct _person;
typedef struct _person* Position;
typedef struct _person {
	char firstName[MAX_NAME];
	char lastName[MAX_NAME];
	int birthYear;
	Position next;
} person;

#endif