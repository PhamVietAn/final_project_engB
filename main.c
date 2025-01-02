#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "function.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]){
	int choice; 
	loadBooks();
	do{
		system("cls");
		printf("    ***Library Management System Using C***\n\n");
		printf("		BOOK MANAGEMENT\n");
		printf("	===============================\n");
		printf("	[1] Book Management.\n");
    	printf("	[2] Customer Management\n");
    	printf("	[0] Exit\n");
		printf("	===============================\n");
    	printf("	Enter your choice: ");
    	scanf("%d", &choice);
    	getchar();
    	
    	switch(choice){
    		case 1:
    			bookManagementMenu();
    			break;
    			
    		case 2:
    			
    			break;
    			
    		case 0:
    			printf("	Exiting the program...\n");
    			break;
    			
    		default:
                printf("	Invalid choice. Try again.\n");
		}
	}while(choice!=0);
	
	return 0;
}
