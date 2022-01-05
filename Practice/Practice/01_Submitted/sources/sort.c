#include "sort.h"

void mergesort_pizzas(pizza_t *v, int ini, int fim){
	//Caso base:
	if (fim <= ini) return;
	
	//Divisão
	int meio = (int)((ini+fim)/2.0);
	mergesort_pizzas(v, ini, meio);   //Primeira metade (esquerda)
	mergesort_pizzas(v, meio+1, fim); //Segunda metade  (direita)
	
	//Conquista (Intercalação/Merge)
    int size = 1 + (fim-ini);
	pizza_t *aux = (pizza_t*)malloc(size * sizeof(pizza_t));
	int i = ini;     //Indice da primeira lista ordenada (ini -> c)
	int j = meio+1;  //Indice da segunda lista ordenada (c+1 -> fim)
	int k = 0;       //Indice do vetor auxiliar (k -> (fim-ini))
	//Compara e intercala os elementos do menor para o maior
	while (i <= meio && j <= fim) {
		double a = v[i].score;
		double b = v[j].score;

		if (a > b) {
			aux[k] = v[i];
			i++;
		} else {
			aux[k] = v[j];
			j++;
		}
		k++;
	}
	
	while (i <= meio) {
		aux[k] = v[i];
        i++; k++;
	}
	
	// Se existirem ainda elementos na lista 2, copia todos para o vetor auxiliar
	while (j <= fim) {
		aux[k] = v[j];
        j++; k++;
	}
	
	// Copia os valores de aux para o vetor original
	for (i=ini, k=0; i<= fim; i++, k++){
		v[i] = aux[k];
	}
	
    //Desaloca memoria auxiliar
	free(aux);
}

void mergesort_strings(char **v, int ini, int fim){
	//Caso base:
	if (fim <= ini) return;
	
	//Divisão
	int meio = (int)((ini+fim)/2.0);
	mergesort_strings(v, ini, meio);   //Primeira metade (esquerda)
	mergesort_strings(v, meio+1, fim); //Segunda metade  (direita)
	
	//Conquista (Intercalação/Merge)
    int size = 1 + (fim-ini);
	char **aux = (char**)malloc(size * sizeof(char*));
	int i = ini;     //Indice da primeira lista ordenada (ini -> c)
	int j = meio+1;  //Indice da segunda lista ordenada (c+1 -> fim)
	int k = 0;       //Indice do vetor auxiliar (k -> (fim-ini))
	//Compara e intercala os elementos do menor para o maior
	while (i <= meio && j <= fim) {
		if (strcmp(v[i], v[j]) <= 0) {
			aux[k] = v[i];
			i++;
		} else {
			aux[k] = v[j];
			j++;
		}
		k++;
	}
	
	while (i <= meio) {
		aux[k] = v[i];
        i++; k++;
	}
	
	// Se existirem ainda elementos na lista 2, copia todos para o vetor auxiliar
	while (j <= fim) {
		aux[k] = v[j];
        j++; k++;
	}
	
	// Copia os valores de aux para o vetor original
	for (i=ini, k=0; i<= fim; i++, k++){
		v[i] = aux[k];
	}
	
    //Desaloca memoria auxiliar
	free(aux);
}