#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pizzas {
	int id;
	int n_ingredients;
	char **ingredients;
	double score; /*Pizza Score based on different attributes*/
} pizza_t;

void mergesort_strings(char **v, int ini, int fim);
void mergesort_pizzas(pizza_t *v, int ini, int fim);