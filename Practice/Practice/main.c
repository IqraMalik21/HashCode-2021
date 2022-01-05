#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

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
			printf("%d ", libraries[i].books_ids[j].id);
		}
		printf("\n");
	}
}

/*Our solution to solve the problem*/
void our_solution(int B, int L, int D, int *scores, library_t *libraries){
	int i, j;

	//Without a Strategy:
	/*Dataset A ... Score:  17
	Dataset B ... Score:  4126100
	Dataset C ... Score:  626399
	Dataset D ... Score:  4109170
	Dataset E ... Score:  472234
	Dataset F ... Score:  916843
	Total Score: 10.248.763*/

	//Creating a score for the Books
	for (i=0; i<L; i++){
		int n_books = libraries[i].N;
		for (j=0; j<n_books; j++){
			int book_id = libraries[i].books_ids[j].id;
			libraries[i].books_ids[j].score = scores[book_id];
		}
		mergesort_books(libraries[i].books_ids, 0, n_books-1);
	}


	//Creating a score for the Libraries
	for (i=0; i<L; i++){
		int sum_scores = 0;
		int n_books = libraries[i].N;
		for (j=0; j<n_books; j++){
			sum_scores += libraries[i].books_ids[j].score;
		}

		//libraries[i].score = sum_scores; //Isadora
		/*Dataset A ... Score:  17
		Dataset B ... Score:  98700
		Dataset C ... Score:  5985
		Dataset D ... Score:  910
		Dataset E ... Score:  75618
		Dataset F ... Score:  396784
		Total Score: 9.081.582*/


		//libraries[i].score = sum_scores/libraries[i].T; //Iqra
		/*Dataset A ... Score:  17
		Dataset B ... Score:  99900
		Dataset C ... Score:  5985
		Dataset D ... Score:  910
		Dataset E ... Score:  96062
		Dataset F ... Score:  391801
		Total Score: 9676257*/


		libraries[i].score = libraries[i].N/libraries[i].T; //Sherlon (Previous Contest)
		/*Dataset A ... Score:  17
		Dataset B ... Score:  99900
		Dataset C ... Score:  5985
		Dataset D ... Score:  910
		Dataset E ... Score:  97448
		Dataset F ... Score:  391801
		Total Score: 10272318*/

		
		//libraries[i].score = libraries[i].M;
		//libraries[i].score = libraries[i].T;
	}

	//Sort by "Strategy"
	mergesort_libraries(libraries, 0, L-1);


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

		libraries[i].books_ids = (book_t*)malloc(libraries[i].N*sizeof(book_t));;
		for (j=0; j<libraries[i].N; j++){
			libraries[i].books_ids[j].id = j;
			scanf("%lf", &libraries[i].books_ids[j].score);
			//printf("%d ", libraries[i].books_ids[j].id);
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