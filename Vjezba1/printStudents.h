#ifndef printStudents_h
#define countStudents_h

void cyan() {
	printf("\033[0;36m");
}

void white() {
	printf("\033[0;37m");
}

int printStudents(stud* students, int count)
{
	double rel_br_bod[MAX_FILE_NAME];
	double max_br_bod = 85;
	FILE* fp;
	fp = fopen("listofstudents.txt", "r");

	if (fp == NULL) {
		printf("File didn't open!\n");
		return FILE_DIDNT_OPEN_ERROR;
	}

	for (int i = 0; i < count; i++) {
		rel_br_bod[i] = ((double)students[i].Points / (double)max_br_bod) * 100;
	}
        cyan();
	printf("First name\tLast name\tPoints\t\tRelative points\n");

	for (int i = 0; i < count; i++) {
	white();
	printf("%-12s\t%-12s\t%-10d\t%-10.2lf\n", students[i].FirstName, students[i].LastName, students[i].Points, rel_br_bod[i]);
	}

	free(students);
	fclose(fp);
	return 0;
}
#endif
