#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define biggest_word 21   //Size of the biggest Ingredient

typedef struct Node {
	char word[biggest_word+1]; 	//Ingredient
	int repetition;				//Number of ocurrences
	struct Node *left;			//Left child
	struct Node *right;			//Right child
} tree_t;

void destroy(tree_t* node);
void inorder(tree_t* node);
void print_inorder(tree_t* node);
tree_t* insert_word_in_tree(char *word, tree_t *tree, int *n_words);
int search_word_in_tree(char *word, tree_t *tree);
