#define _CRT_SECURE_NO_WARNINGS
#define FILE_DIDNT_OPEN_ERROR (-1)
#define ERROR (-2)
#define MAX_LINE (1024)
#define MAX_FILE_NAME (256)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "countStudentsInFile.h"
#include "Allocation.h"
#include "readStudentsFromFile.h"
#include "printStudents.h"

int countStudentsInFile();
int readStudentsFromFile(stud*);
int printStudents(stud*, int);
stud* Allocation(int, stud*);


int main()
{
	stud* students = NULL;

	int count = countStudentsInFile();
	students = Allocation(count, students);
	readStudentsFromFile(students);
	printStudents(students, count);

	return EXIT_SUCCESS;
}
