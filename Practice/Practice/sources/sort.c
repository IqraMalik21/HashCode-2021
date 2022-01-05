#include "sort.h"

void mergesort_libraries(library_t *v, int ini, int fim){
	//Caso base:
	if (fim <= ini) return;
	
	//Divisão
	int meio = (int)((ini+fim)/2.0);
	mergesort_libraries(v, ini, meio);   //Primeira metade (esquerda)
	mergesort_libraries(v, meio+1, fim); //Segunda metade  (direita)
	
	//Conquista (Intercalação/Merge)
    int size = 1 + (fim-ini);
	library_t *aux = (library_t*)malloc(size * sizeof(library_t));
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

void mergesort_books(book_t *v, int ini, int fim){
	//Caso base:
	if (fim <= ini) return;
	
	//Divisão
	int meio = (int)((ini+fim)/2.0);
	mergesort_books(v, ini, meio);   //Primeira metade (esquerda)
	mergesort_books(v, meio+1, fim); //Segunda metade  (direita)
	
	//Conquista (Intercalação/Merge)
    int size = 1 + (fim-ini);
	book_t *aux = (book_t*)malloc(size * sizeof(book_t));
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