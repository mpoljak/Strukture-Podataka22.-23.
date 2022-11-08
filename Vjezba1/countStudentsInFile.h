#ifndef countStudents_h
#define countStudents_h

int countStudentsInFile() {
	char buffer[MAX_FILE_NAME];
	int count = 0;
	FILE* fp;
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

#endif 