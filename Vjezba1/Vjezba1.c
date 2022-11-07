#define _CRT_SECURE_NO_WARNINGS
#define FILE_DIDNT_OPEN_ERROR (-1)
#define ERROR (-2)
#define MAX_LINE (1024)
#define MAX_FILE_NAME (256)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct students {
	char FirstName[MAX_FILE_NAME];
	char LastName[MAX_FILE_NAME];
	int Points;
} stud;

int countStudentsInFile();
int readStudentsFromFile(stud*);
int printStudents(int*, stud*);
stud *Allocation(int, stud*);


int main ()
{  
	stud *students = NULL;
	
    int count = countStudentsInFile();
	students = Allocation(count, students);
	readStudentsFromFile(students);
	printStudents(students,count);

	return EXIT_SUCCESS;
}

int countStudentsInFile() {
	char buffer[MAX_FILE_NAME];
	int count = 0;
	FILE *fp;
	fp = fopen("listofstudents.txt", "r");

	if (fp == NULL) {
		printf("Dear coustomer,the file didn't open! \n");
		return FILE_DIDNT_OPEN_ERROR;
	}

	while (fgets(buffer, sizeof(buffer), fp) != NULL)
	{
		if (strcmp(buffer, "\n") != 0) {
			count++;
		}
	}
	rewind(fp);
	printf("The number of students in the file is > %d\n", count);

	fclose(fp);
	return count;
}

stud *Allocation(int count, stud *students){
	students = (stud*)malloc(sizeof(stud) *count);

	if (students == NULL)
	{
		printf("Memory allocation error!\n");
		return ERROR;
	}

	if (students->FirstName==NULL || students->LastName==NULL || students->Points==NULL)
    {
		printf("Memory allocation error! \n");
	}

	return students;
}

int readStudentsFromFile (stud *students) 
{
	int i = 0;
	FILE *fp;
	fp = fopen("listofstudents.txt", "r");

	if (fp == NULL) {
		printf("File didn't open!\n");
		return FILE_DIDNT_OPEN_ERROR;
	}

	while (!feof(fp)) {
		fscanf(fp, "%s %s %d", students[i].FirstName, students[i].LastName, &students[i].Points);
		i++;
	}

	fclose(fp);
	return students;
}

int printStudents(stud *students, int count)
{
	double rel_br_bod[MAX_FILE_NAME];
	double max_br_bod = 85;
	FILE *fp;
	fp = fopen("listofstudents.txt", "r");

	if (fp == NULL) {
		printf("File didn't open!\n");
		return FILE_DIDNT_OPEN_ERROR;
	}


	for (int i = 0; i < count; i++) {
		rel_br_bod[i] = ((double)students[i].Points / (double)max_br_bod) * 100;
	}

	printf("First name\tLast name\tPoints\t\tRelative points\n");

	for (int i = 0; i < count; i++) {
		printf("%-12s\t%-12s\t%-10d\t%-10.2lf\n", students[i].FirstName, students[i].LastName, students[i].Points, rel_br_bod[i]);
	}

	free(students);
	fclose(fp);
	return 0;
}