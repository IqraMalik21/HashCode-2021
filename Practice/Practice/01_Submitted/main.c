#include <stdio.h>
#include <stdlib.h>

typedef struct Book {
	int id;			//Book ID
	double score;   //Property to sort the Books
} book_t;

typedef struct Library {
	int id; //Library ID
	int N;  //Number of Books in the Library
	int T;  //Number of days to finish the Library Signup
	int M;  //Number of Books that can be shipped
	int *books_ids; //Ids of books in the Library
	double score;	//Property to sort the Libraries
} library_t;

/* This function will generate the output file format
** Parameters:
**   library_t * libraries 	-> All the Libraries and their data
**   int A; 				-> The number of Libraries to Sign up
**   int D;                 -> Number of Days (Total)
*/
void generates_output_file(int D, int A, library_t *libraries){
	
	//WE NEED TO DIFINE THE VALUES A and K

	int Y; 		//The ID of the library
	int K; 		//Number of books to be scanned from library Y
	int i, j;
	int days_left = D; 
	//available_days //Time after sign up current Library

	//printf("OUTPUT:\n");
	printf("%d\n", A);
	for (i=0; i<A; i++){
		days_left -= libraries[i].T; //Sequential (One after another)
		Y = libraries[i].id;
		K = days_left*libraries[i].M; //Number of books to be scanned
		if (K > libraries[i].N) K = libraries[i].N;
		//printf("A=%d, Y=%d, K=%d, days_left=%d, M=%d\n", A, Y, K, days_left, libraries[i].M);
		printf("%d %d\n", Y, K);
		for (j=0; j<K; j++){
			printf("%d ", libraries[i].books_ids[j]);
		}
		printf("\n");
	}
}

/*Our solution to solve the problem*/
void our_solution(int B, int L, int D, int *scores, library_t *libraries){

	//Sort by "Strategy"

	//Define A value
	int A = 0; //The number of Libraries to Sign up
	int sum; //The sum of the Sign up days
	int l = 0; //Iterates the Libraries (Index)
	for (sum=0; sum<D; sum += libraries[l++].T ){
		if (A < L) A++;
	}

	generates_output_file(D, A, libraries);
}

int main () {
	int B; //Number of different Books
	int L; //Number of Libraries
	int D; //Number of Days
	int i, j;

	scanf("%d %d %d", &B, &L, &D);
	//printf("%d %d %d\n", B, L, D);

	//Read Scores
	int *scores = (int*)malloc(B*sizeof(int));
	for (i=0; i<B; i++){
		scanf("%d", &scores[i]);
	}

	/*for (i=0; i<B; i++){
		printf("%d ", scores[i]);
	}
	printf("\n");*/


	//Read Libraries
	library_t *libraries = (library_t*)malloc(L*sizeof(library_t));
	for (i=0; i<L; i++){
		scanf("%d %d %d", &libraries[i].N, &libraries[i].T, &libraries[i].M);
		//printf("%d %d %d\n", libraries[i].N, libraries[i].T, libraries[i].M);

		libraries[i].id = i;

		libraries[i].books_ids = (int*)malloc(libraries[i].N*sizeof(int));;
		for (j=0; j<libraries[i].N; j++){
			scanf("%d", &libraries[i].books_ids[j]);
			//printf("%d ", libraries[i].books_ids[j]);
		}
		//printf("\n");
	}

	//Solution
	our_solution(B, L, D, scores, libraries);


	//Deallocate Memory
	free(scores);

	for (i=0; i<L; i++){
		free(libraries[i].books_ids);
	}
	free(libraries);
	return 0;
}