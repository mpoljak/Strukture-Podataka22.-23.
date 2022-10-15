#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_DIDNT_OPEN_ERROR (-1)
#define MAX_LINE (1024)
#define MAX_FILE_NAME (256)

typedef struct _studenti {
    char FirstName;
    char LastName;
    int Points;
};

int countStudentsFromFile(char* filename);

int main(void) {
    char filename[MAX_FILE_NAME] = { 0 };
    printf("Insert filename > ");
    scanf(" %s", &filename);

    int studentsNumber = countStudentsFromFile(filename);

    printf("\nBroj studenata u datoteci %s je %d \n", &filename, studentsNumber);
    return 0;

}

int countStudentsFromFile(char* filename) {
    FILE* fp = NULL;
    int count = 0;
    char buffer[MAX_FILE_NAME];

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Dear coustomer,the file %s didn't open! \r\n", filename);
        return FILE_DIDNT_OPEN_ERROR;
    }
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        if (strcmp(buffer, "\n" ) != 0) {
            count++;
        }
    }
    fclose(fp);
    return count;
}