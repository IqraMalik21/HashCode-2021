#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trie.h"
#include "sort.h"
#include "binary_tree.h"

//Shows the Matrix Data
void print_data(pizza_t *pizzas, int M){
	int i, j;
	for (i=0; i<M; i++){
		printf("(Score: %.2f) ", pizzas[i].score);
		printf("%d ", pizzas[i].n_ingredients);
		for(j=0; j<pizzas[i].n_ingredients; j++){
			printf("%s ", pizzas[i].ingredients[j]);
		}
		printf("\n");
	}
}

//Creates a Score to each pizza (Priority List)
void calculate_score(pizza_t *pizzas, int M, tree_t *tree){
	int i, j;
	for (i=0; i<M; i++){
		double repetition = 0.0;
		for(j=0; j<pizzas[i].n_ingredients; j++){
			repetition += search_word_in_tree(pizzas[i].ingredients[j], tree);
		}
		pizzas[i].score = pizzas[i].n_ingredients/repetition;
	}
}

/*First Solution: Deliver all pizzas by the input order
  Second Solution: Sorts the data by number of ingredients
  Third Solution: Creates a score based in the ingredients repetition and sort by this score*/
void naive_solution(pizza_t *pizzas, int M, int *t, tree_t *tree){
	int L = 0; //Number of deliveries
	int D = t[0] + t[1] + t[2]; //Max number of deliveries
	int teams = 3; //Types of teams (2, 3, 4 people)
	int i, j, k;

	//Iqra Solution: Maximize number o teams
	//if (t[0] > t[1] && t[0] > t[2]) //Choose t[0]
	//if (t[1] > t[2] && t[1] > t[3]) //Choose t[1]
	//if (t[2] > t[0] && t[2] > t[1]) //Choose t[2]

	//Another Solution: Maximize number of people
	// int allPeopleTeams2Person = t[0] * 2; //a
	// int allPeopleTeams3Person = t[0] * 3; //b
	// int allPeopleTeams4Person = t[0] * 4; //c
	//if (a > b && a > c) //Choose a
	//if (b > a && b > c) //Choose b
	//if (c > a && c > b) //Choose c
	
	//Sort the pizzas by number of ingredients
	print_data(pizzas, M);
	calculate_score(pizzas, M, tree);
	mergesort_pizzas(pizzas, 0, M-1);
    printf("\n"); print_data(pizzas, M);

	//Allocates output data
	int **output = (int**)malloc(D*sizeof(int*));
	for (i=0; i<D; i++){
		output[i] = (int*)malloc(5*sizeof(int));
		for (j=0; j<5; j++){
			output[i][j] = -1;
		}
	}

	//Print
	/*printf("\nInitialization:\n");
	for (i=0; i<D; i++){
		for (j=0; j<5; j++){
			printf("%d ", output[i][j]);
		}
		printf("\n");
	}*/

	//Pizza Delivery
	int pizza_index = 0;
	int delivery_index = 0;
	for (i=0; i<teams; i++){ //Iterates the Teams
		//int people = 2 + i;  //Total people in the current team (Crescent Order: 2 -> 3 -> 4)
		//while (t[2-i] > 0){    //Iterates all the teams of the same type
		int people = 4 - i;  //Total people in the current team (Decrescent Order: 4 -> 3 -> 2)
		while (t[2-i] > 0){    //Iterates all the teams of the same type
			output[delivery_index][0] = people;
			int verification = 0;
			for (k=0; k<people; k++){ //Deliver each pizza
				if (pizza_index < M){
					output[delivery_index][k+1] = pizzas[pizza_index].id;
					pizza_index++;
					verification++;
				}
			}
			//t[i]--;
			t[2-i]--;
			if (verification == people) delivery_index++;
			if (pizza_index >= M) break;
		}
		if (pizza_index >= M) break;
	}

	L = delivery_index; //Number of Deliveries

	//Print
	/*printf("\nAfter Delivery:\n");
	for (i=0; i<D; i++){
		for (j=0; j<5; j++){
			printf("%d ", output[i][j]);
		}
		printf("\n");
	}*/

	//Print
	/*printf("\nOutput:\n");*/
	printf("%d\n", L);
	for (i=0; i<L; i++){
		for (j=0; j<5; j++){
			if (output[i][j] != -1)
				printf("%d ", output[i][j]);
		}
		if (i != L-1) printf("\n");
	}

	//Deallocates output data
	for (i=0; i<D; i++) free(output[i]);
	free(output);
}

int main(void) {
	int M;	//Number of Pizzas available
	int t[3]; //Number of 2-person teams, 3-person teams, 4-person teams
	
	//Gets input data
	scanf("%d %d %d %d", &M, &t[0], &t[1], &t[2]);
	
	//Allocates Data Structures
	pizza_t *pizzas = (pizza_t*)malloc(M*sizeof(pizza_t)); //Stores all pizzas

	//Initialize tree (Root)
	tree_t *tree = NULL;
	int n_words = 0; //Number of words/ingredients (No repetition)

	//Loads the input file
	int i, j;
	for (i=0; i<M; i++){
		//Stores the ID
		pizzas[i].id = i;

		//Stores the Number of Ingredients
		int I;
		scanf("%d ", &I);
		pizzas[i].n_ingredients = I;

		//Stores the Ingredients
		pizzas[i].ingredients = (char**)malloc(I*sizeof(char**));

		for (j=0; j<I; j++){
			char *ingredient = (char*)malloc(21*sizeof(char));
			scanf("%s", ingredient);
			pizzas[i].ingredients[j] = ingredient;

			/*Insert all the ingredients in the tree with no repetition*/
			tree = insert_word_in_tree(ingredient, tree, &n_words);
		}
	}

	//Prints the Matrix Data
	/*printf("Input Data:\n");
	print_data(pizzas, M);*/

	//Prints the Tree Data
	/*printf("\nBinary Tree of Ingredients:\n");
	printf("There are %d words in the Binary Tree\n", n_words);
	print_inorder(tree); //Print the tree in order*/

	//Solution
	naive_solution(pizzas, M, t, tree); //A naive approach

	//Deallocates Memory
	for (i=0; i<M; i++){
		for(j=0; j<pizzas[i].n_ingredients; j++){
			free(pizzas[i].ingredients[j]);
		}
		free(pizzas[i].ingredients);
	}
	free(pizzas);
	destroy(tree);

	return 0;
}


