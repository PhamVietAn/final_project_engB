// Noi di trien khai cac ham
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "function.h"

int choice;

void bookManagementMenu(){
	do{
		system("cls");
		printf("    ***Library Management System Using C***\n\n");
		printf("		BOOK MANAGEMENT\n");
		printf("	===============================\n");
		printf("	[1] Show All Books\n");
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
    
	    switch(choice){
			case 0:
				saveBooks();
				break;
				
			case 1:	
				system("cls");			
				showBooks();
				break;
				
			case 2:
				menuAddBooks();
				break;
				
			case 3: 
				menuEditBook();
				break;
				
			case 4:
				menuDeleteBook();
				break; 
				
			case 5:
				menuSearchBook();
				break;
				
			case 6:
				menuSortBooksByPrice();
				break;
				
			default:
	            printf("Invalid choice. Try again.\n");
		}
	}while(choice!=0);
}

int bookCount = 0;
struct Book books[100];

void loadBooks(){
    FILE *file = fopen("books.bin", "rb");
    if(file == NULL){
        printf("No previous data found. Starting fresh.\n");
        return;
    }

    fread(&bookCount, sizeof(int), 1, file);
    fread(books, sizeof(struct Book), bookCount, file);

    fclose(file);
}

void saveBooks(){
    FILE *file = fopen("books.bin", "wb");
    if(file == NULL){
        printf("Error saving data!\n");
        getchar(); 
        return;
    }

    fwrite(&bookCount, sizeof(int), 1, file);
    fwrite(books, sizeof(struct Book), bookCount, file);

    fclose(file);
}

void showBooks(){
    printf("	   ***All Books***   \n");
    printf("	=====================\n");
    if(bookCount==0){
    	printf("	No books in the library\n");
	}
    for(int i = 0; i < bookCount; i++){           
        printf("	| ID: %-7s | Title: %-8s | Author: %-8s | Quantity: %-3d | Price: %-8.1f | Publication: %02d-%02d-%04d |\n",
    		books[i].bookId, books[i].title, books[i].author, books[i].quantity, books[i].price,
       		books[i].publication.day, books[i].publication.month, books[i].publication.year);

    }
    printf("	=====================\n");
    printf("	Number of Books: %d\n", bookCount);
    printf("	Press Enter to return to menu.\n");
    getchar();	
}

void menuAddBooks(){
	do{
		system("cls");
	    printf("	   ***Add Books***   \n");
	    printf("	=====================\n");
	    printf("	[1] Add book.\n");
		printf("	[0] Exit.\n");
		printf("	=====================\n");
		printf("	Enter your choice: ");
		scanf("%d", &choice);
	    getchar();
    	
    	switch(choice){
    		case 1:
    			addBooks();
    			break;
    		
    		case 0:
    			break;
    			
    		default:
    			printf("Invalid choice. Try again.\n");
    			break;
    			
		}
	}while(choice!=0);
} 

void addBooks(){
	system("cls");
    printf("	    ***Add Books***   \n");
    printf("	=======================\n");
    if(bookCount >= 100){
        printf("	Library is full. Cannot add more books.\n");
        getchar();
        return;
    }

    struct Book *newBook = &books[bookCount];
    
    
	int isDuplicate;
    do{
        isDuplicate = 0;
        printf("	Enter book ID (7 characters): ");
        fgets(newBook->bookId, 10, stdin);
        newBook->bookId[strcspn(newBook->bookId, "\n")] = 0;
        
        if(strlen(newBook->bookId) != 7){
            printf("	Book ID must be exactly 7 characters.\n");
            continue;
        }

        for(int i = 0; i < bookCount; i++){
            if(strcmp(books[i].bookId, newBook->bookId) == 0){
                printf("	Book ID already exists. Please enter a unique ID.\n");
                isDuplicate = 1;
                break;
            }
        }
    }while(isDuplicate);

	do{
        isDuplicate = 0;
        printf("	Enter title (Max 8 characters): ");
        fgets(newBook->title, 30, stdin);
        newBook->title[strcspn(newBook->title, "\n")] = 0;
        
        if(strlen(newBook->title) > 8 || strlen(newBook->title) < 1){
            printf("	Title must be between 1 and 8 characters.\n");
            continue;
        }

        for(int i = 0; i < bookCount; i++){
            if(strcmp(books[i].title, newBook->title) == 0){
                printf("	Title already exists. Please enter a unique title.\n");
                isDuplicate = 1;
                break;
            }
        }
    }while(isDuplicate);
	
	while(strlen(newBook->author)>8 || strlen(newBook->author)<1){
    printf("	Enter author (Max 8 character): ");
    fgets(newBook->author, 20, stdin);
    newBook->author[strcspn(newBook->author, "\n")] = 0;
	}
	
	do{
        printf("	Enter quantity (Max 999): ");
        scanf("%d", &newBook->quantity);
        while(getchar() != '\n');
    }while(newBook->quantity < 1 || newBook->quantity > 999);

	
	do{
        printf("	Enter price (Max 999999): ");
        scanf("%f", &newBook->price);
        while(getchar() != '\n');
    }while(newBook->price < 1 || newBook->price > 999999);
	
    printf("	Enter publication date (dd mm yyyy): ");
    scanf("%d %d %d", &newBook->publication.day, &newBook->publication.month, &newBook->publication.year);
    while(getchar() != '\n');

    bookCount++;
    saveBooks();

    printf("	=======================\n");
    printf("	Book added successfully!\n");
    printf("	Press Enter to return to menu.\n");
    getchar();
}

void menuEditBook(){
	do{
		system("cls");
	    printf("	   ***Edit Books***   \n");
	    printf("	======================\n");
	    printf("	[1] Edit book.\n");
		printf("	[0] Exit.\n");
		printf("	======================\n");
		printf("	Enter your choice: ");
		scanf("%d", &choice);
	    getchar();
    	
    	switch(choice){
    		case 1:
    			editBook();
    			break;
    		
    		case 0:
    			break;
    			
    		default:
    			printf("Invalid choice. Try again.\n");
    			break;
    			
		}
	}while(choice!=0);
}

void editBook(){
    char id[10];
    system("cls");
    printf("		   ***Edit Books***   \n");
    printf("	==============================\n");
    printf("    Enter book ID to edit: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = 0;

    for(int i = 0; i < bookCount; i++){
        if(strcmp(books[i].bookId, id) == 0){
            printf("	Editing book: %s\n", books[i].title);
            printf("	Author: %s\n", books[i].author);
            printf("	Quantity: %d\n", books[i].quantity);
            printf("	Price: %.1f\n", books[i].price);
            printf("	Publication: %02d-%02d-%04d\n", books[i].publication.day, books[i].publication.month, books[i].publication.year);

            char temp[30];
            int isDuplicate;

            do{
                isDuplicate = 0;
                printf("\n	Enter new title (Max 8 characters): ");
                fgets(temp, sizeof(temp), stdin);
                temp[strcspn(temp, "\n")] = 0;

                if(strlen(temp) > 8 || strlen(temp) < 1){
                    printf("	Title must be between 1 and 8 characters.\n");
                    continue;
                }

                for(int j = 0; j < bookCount; j++){
                    if(j != i && strcmp(books[j].title, temp) == 0){
                        printf("	Title already exists. Please enter a unique title.\n");
                        isDuplicate = 1;
                        break;
                    }
                }
            } while(isDuplicate);

            strcpy(books[i].title, temp);

            printf("	Enter new author (Max 8 characters): ");
            fgets(temp, sizeof(temp), stdin);
            temp[strcspn(temp, "\n")] = 0;
            if(strlen(temp) > 0){
                strcpy(books[i].author, temp);
            }

            printf("	Enter new quantity: ");
            int newQuantity;
            scanf("%d", &newQuantity);
            books[i].quantity = newQuantity;

            printf("	Enter new price: ");
            float newPrice;
            scanf("%f", &newPrice);
            books[i].price = newPrice;

            printf("	Enter new publication date (dd mm yyyy): ");
            int day, month, year;
            scanf("%d %d %d", &day, &month, &year);
            books[i].publication.day = day;
            books[i].publication.month = month;
            books[i].publication.year = year;
            getchar();

            saveBooks();

            printf("	==============================\n");
            printf("	Book updated successfully!\n");
            printf("	Press Enter to return to menu.\n");
            getchar();
            return;
        }
    }
    printf("	Book not found!\n");
    printf("	Press Enter to return to menu.\n");
    getchar();
}

void menuDeleteBook(){
	do{
		system("cls");
	    printf("	   ***Delete Books***   \n");
	    printf("	========================\n");
	    printf("	[1] Delete book.\n");
		printf("	[0] Exit.\n");
		printf("	========================\n");
		printf("	Enter your choice: ");
		scanf("%d", &choice);
	    getchar();
    	
    	switch(choice){
    		case 1:
    			deleteBook();
    			break;
    		
    		case 0:
    			break;
    			
    		default:
    			printf("Invalid choice. Try again.\n");
    			break;
    			
		}
	}while(choice!=0);
}

void deleteBook(){
	char id[10];
	system("cls");
    printf("	       ***Delete Books***   \n");
    printf("	================================\n");
    printf("	Enter book ID to delete: ");
    fgets(id, 10, stdin);
    id[strcspn(id, "\n")] = 0;
	
	int flag;
    for(int i = 0; i < bookCount; i++){
        if(strcmp(books[i].bookId, id) == 0){
        	printf("\n	       ***Delete Books***   \n");
    		printf("	================================\n");
    		printf("	Are you sure you want to delete?\n");
    		printf("	[1] Yes\n");
    		printf("	[0] No\n");
    		printf("	choice: ");
    		scanf("%d", &flag);
    		getchar();
    		
    		if(flag==1){
	    		for(int j = i; j < bookCount - 1; j++){
	                books[j] = books[j + 1];
	            }
	            bookCount--;
	            printf("	Book deleted successfully!\n");
	            printf("	================================\n");     
	            printf("	Press Enter to return to menu.\n");
	    		getchar();
	            saveBooks();
            	return;
        	}else if(flag==0){
        		
	            printf("	================================\n");     
	            printf("	Press Enter to return to menu.\n");
	    		getchar();
	            saveBooks();
	            return;
			}else if(flag!=0 || flag!=1){
				printf("	lua chon ko hop le\n");
				printf("	================================\n");     
	            printf("	Press Enter to return to menu.\n");
	    		getchar();
	            saveBooks();
				return;
			}
        }
    }
    printf("	Book not found!\n");
    printf("	================================\n");    
    printf("	Press Enter to return to menu.\n");
    getchar();
}

void menuSearchBook(){
	do{
		system("cls");
	    printf("	   ***Search Books***   \n");
	    printf("	========================\n");
	    printf("	[1] Search book.\n");
		printf("	[0] Exit.\n");
		printf("	========================\n");
		printf("	Enter your choice: ");
		scanf("%d", &choice);
	    getchar();
    	
    	switch(choice){
    		case 1:
    			searchBook();
    			break;
    		
    		case 0:
    			break;
    			
    		default:
    			printf("Invalid choice. Try again.\n");
    			break;
    			
		}
	}while(choice!=0);
}

void searchBook(){
	system("cls");
    char keyword[30];
    printf("\n	Enter keyword to search: ");
    fgets(keyword, 30, stdin);
    keyword[strcspn(keyword, "\n")] = 0;

    printf("	   ***Search Results***   \n");
    printf("	==========================\n");
    for(int i = 0; i < bookCount; i++){
        if(strstr(books[i].title, keyword) != NULL){
            printf("	| ID: %-7s | Title: %-8s | Author: %-8s | Quantity: %-2d | Price: %-8.1f | Publication: %02d-%02d-%04d |\n",
                   books[i].bookId, books[i].title, books[i].author, books[i].quantity, books[i].price,
                   books[i].publication.day, books[i].publication.month, books[i].publication.year);
        }else{
        	printf("No Books Found"); 
		} 
    }
    printf("	==========================\n");
    printf("	Press Enter to return to menu.\n");
    getchar();
}

void menuSortBooksByPrice(){
	do{
		system("cls");
	    printf("	   ***Sort Books By Price***   \n");
	    printf("	===============================\n");
	    printf("	[1] Sort book Incremental.\n");
	    printf("	[2] Sort book Descending.\n");
		printf("	[0] Exit.\n");
		printf("	===============================\n");
		printf("	Enter your choice: ");
		scanf("%d", &choice);
	    getchar();
    	
    	switch(choice){
    		case 1:
    			sortBooksIncremental();
    			break;
    			
    		case 2:
				sortBooksDescending(); 
				break; 
    		
    		case 0:
    			break;
    			
    		default:
    			printf("Invalid choice. Try again.\n");
    			break;
    			
		}
	}while(choice!=0);
}

void sortBooksIncremental(){
	for(int i = 0; i < bookCount - 1; i++) {
        for(int j = 0; j < bookCount - i - 1; j++){
            if(books[j].price > books[j + 1].price){
                struct Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
    system("cls");
	printf("	   ***Sort Books By Price***   \n");
    printf("	===============================\n");
    printf("	Books sorted successfully!\n");
    printf("	===============================\n\n");
    showBooks(); 
    saveBooks();
}

void sortBooksDescending(){
	for(int i = 0; i < bookCount - 1; i++){
    	for(int j = 0; j < bookCount - i - 1; j++){
	        if(books[j].price < books[j + 1].price){
	            struct Book temp = books[j];
	            books[j] = books[j + 1];
	            books[j + 1] = temp;
	        }
    	}
	}
    system("cls");
	printf("	   ***Sort Books By Price***   \n");
    printf("	===============================\n");
    printf("	Books sorted successfully!\n");
    printf("	===============================\n\n");
    showBooks(); 
    saveBooks();
}


