// noi import nhung thu vien, khai bao cac struct

struct Date{
	int month, day, year;
};

struct Book{
	char bookId[10];
	char title[30];
	char author[20];
	int quantity;
	float price;
	struct Date publication;
};

struct member{
	char memberId[10];
	char name[20];
	bool status;
	struct Book BorrowedBooks[];
};
