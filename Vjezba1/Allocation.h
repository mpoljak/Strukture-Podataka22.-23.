#ifndef studentStruct_h
#define studentStruct_h

#include "studentStruct.h"

stud* Allocation(int count, stud* students)
{
	students = (stud*)malloc(sizeof(stud) * count);

	if (students == NULL)
	{
		printf("Memory allocation error!\n");
		return ERROR;
	}

	if (students->FirstName == NULL || students->LastName == NULL || students->Points == NULL)
	{
		printf("Memory allocation error! \n");
	}

	return students;
}
#endif 