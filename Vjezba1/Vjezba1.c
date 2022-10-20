#define _CRT_SECURE_NO_WARNINGS
#define FILE_DIDNT_OPEN_ERROR (-1)
#include <stdio.h>
#include <stdlib.h>

typedef struct studenti {
	char FirstName[50];
	char LastName[50];
	int Points;
} stud;

int main()
{
	char buffer[150];
	char ch;
	int count = 0, i = 0;
	FILE* fp;
	stud* student;
	double rel_br_bod[100];
	int max_br_bod = 100;


	fp = fopen("listofstudents.txt", "r");
	if (fp == NULL) {
		printf("Dear coustomer,the file didn't open! \n");
		return FILE_DIDNT_OPEN_ERROR;
	}

	while (fgets(buffer, sizeof(buffer), fp) != NULL)
	{
		if (strcmp(buffer, "\n") != NULL) {
			count++;
		}
	
}

	rewind(fp);

	printf("The number of students in the file is > %d\n", count);

	student = (stud*)malloc(sizeof(stud) * count);

	while (!feof(fp)) {
		fscanf(fp, " %s	%s	%d", student[i].FirstName, student[i].LastName, &student[i].Points);
		i++;
	}
	for (i = 0; i < count; i++)
		rel_br_bod[i] = ((double)student[i].Points / (double)max_br_bod) * 100;

	for (i = 0; i < count; i++) {
		printf("%s	%s	%d %.4lf\n", student[i].FirstName, student[i].LastName, student[i].Points, rel_br_bod[i]);
	}

	fclose(fp);
}