#define _CRT_SECURE_NO_WARNINGS
#define FILE_DIDNT_OPEN_ERROR (-1)
#include <stdio.h>
#include <stdlib.h>

typedef struct students {
	char FirstName[50];
	char LastName[50];
	int Points;
} stud;

int countStudentsInFile(FILE*);
void readStudentsFromFile(FILE*, stud*);

int main()
{
	char buffer[150];
	char ch;
	int count;
	FILE* fp;
	stud* student;
	double rel_br_bod[100];
	int max_br_bod = 100;


	fp = fopen("listofstudents.txt", "r");
	if (fp == NULL) {
		printf("Dear coustomer,the file didn't open! \n");
		return FILE_DIDNT_OPEN_ERROR;
	}

	count = countStudentsInFile(fp);

	student = (stud*)malloc(sizeof(stud) * count);

	readStudentsFromFile(fp, student);

	for (int i = 0; i < count; i++) {
		rel_br_bod[i] = ((double)student[i].Points / (double)max_br_bod) * 100;
	}

	printf("First name\tLast name\tPoints\t\tRelative points\n");

	for (int i = 0; i < count; i++) {
		printf("%-12s\t%-12s\t%-10d\t%-10.2lf\n", student[i].FirstName, student[i].LastName, student[i].Points, rel_br_bod[i]);
	}

	free(student);
	fclose(fp);

	return 0;
}

int countStudentsInFile(FILE *fp){
	char buffer[150];
	int count = 0;

	while (fgets(buffer, sizeof(buffer), fp) != NULL)
	{
		if (strcmp(buffer, "\n") != 0) {
			count++;
		}

	}

	rewind(fp);

	printf("The number of students in the file is > %d\n", count);

	return count;
}

void readStudentsFromFile(FILE* fp, stud* student) {
	int i = 0;
	while (!feof(fp)) {
		fscanf(fp, " %s	%s	%d", student[i].FirstName, student[i].LastName, &student[i].Points);
		i++;
	}
}