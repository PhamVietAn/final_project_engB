#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "function.h"

int choice;

void customerManagementMenu(){
	system("cls");
		printf("    ***Library Management System Using C***\n\n");
		printf("		CUSTOMER MANAGEMENT\n");
		printf("	===============================\n");
		printf("	[1] Show All Customer\n");
    	printf("	[2] Add A Book\n");
    	printf("	[3] Edit A Book\n");
    	printf("	[4] Delete A Book\n");
    	printf("	[5] Search A Book\n");
    	printf("	[6] Sort Books By Price\n");
    	printf("	[0] Exit\n");
		printf("	===============================\n");
    	printf("	Enter your choice: ");
    	scanf("%d", &choice);
    	getchar();
}



