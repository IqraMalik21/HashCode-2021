#include "binary_tree.h"

/*Function to destroy BST*/
void destroy(tree_t* node) {
    if (node != NULL) { 
        destroy(node->left); 
        destroy(node->right); 
		free(node);
    } 
} 

/*Function to do inorder traversal of BST*/
void inorder(tree_t* node) {
    if (node != NULL) { 
        inorder(node->left); 
        //printf("%s\n", node->word); 
        inorder(node->right); 
    } 
}

/*Function to do inorder traversal of BST*/
void print_inorder(tree_t* node) {
    if (node != NULL) { 
        print_inorder(node->left); 
        printf("%s -> %d ocurrences\n", node->word, node ->repetition); 
        print_inorder(node->right); 
    } 
} 

/*Insert a new word in a binary tree (No Repetition)*/
tree_t* insert_word_in_tree(char *word, tree_t *tree, int *n_words){
	//printf("%s\n", word);
	if (tree == NULL) { //Node is empty
		tree_t *new_node = (tree_t*)malloc(sizeof(tree_t));
		strcpy(new_node->word, word);
		new_node->repetition = 1;
		new_node->left = NULL;
		new_node->right = NULL;
		(*n_words) += 1;
		return new_node;
	}
	
	int cmp = strcasecmp(word, tree->word);

	if (cmp < 0) {
		tree->left = insert_word_in_tree(word, tree->left, n_words);
	}

	if (cmp > 0){
		tree->right = insert_word_in_tree(word, tree->right, n_words);
	}

	//If the word was repeated (cmp == 0), do not store it in the tree (Sum the occurrences)
	if (cmp == 0) {
		tree->repetition += 1;
	}

	return tree;
}

/*Search a word in a binary tree*/
int search_word_in_tree(char *word, tree_t *tree){
	//printf("%s\n", word);
	while (tree != NULL) {
		if (strcasecmp(word, tree->word) < 0) {
			tree = tree->left;
		} else if (strcasecmp(word, tree->word) > 0) {
			tree = tree->right;
		} else {
			//return 1; //returns 1 if the word is in the tree
			return tree->repetition; //returns the repetition of a word
		}
	}
	return 0; //returns 0 if the word is not in the tree
}