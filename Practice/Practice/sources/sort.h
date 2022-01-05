#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
	int id;			//Book ID
	double score;   //Property to sort the Books
} book_t;

typedef struct Library {
	int id; //Library ID
	int N;  //Number of Books in the Library
	int T;  //Number of days to finish the Library Signup
	int M;  //Number of Books that can be shipped
	book_t *books_ids; //Ids of books in the Library
	double score;	//Property to sort the Libraries
} library_t;

void mergesort_libraries(library_t *v, int ini, int fim);
void mergesort_books(book_t *v, int ini, int fim);