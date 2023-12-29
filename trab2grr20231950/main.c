#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

#define N 5

int main() {

	//Declarando variaveis
	char nome[MAX_CHAR];
   	unsigned long numComp;
    	char nomeAlg[MAX_CHAR];
	
	//Tamanho dos vetores para os algoritmos
	int *vetor;
	unsigned int *vetorCounting;
	int tamVetor[N] = {1000000,2500000,5000000,7500000,10000000};

	// Para medir o temp
	clock_t start, end; 
	double total;
	srand(time(NULL));
	
	//Minhas informacoes
	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n\n", getGRR());
    
	//Implementacao dos algoritmos de ordenacao
	
	//Quick Sort
	for (int i = 0; i < N ; i++) {
		vetor = (int*)malloc (tamVetor[i] * sizeof(int));
            	if (vetor == NULL) {
                	printf("Falha fatal. Impossível alocar memória.\n");
                	return 1;
            	}
            	preencheVetorAleatorio (vetor,tamVetor[i], tamVetor[i]);
		printf ("Vetor desordenado: ");
		imprimeVetor (vetor, tamVetor[i]);
           	numComp = total = 0;
            	start = clock(); 
            	numComp = quickSort (vetor, tamVetor[i]);
            	end = clock();
		printf ("Vetor ordenado: ");
		imprimeVetor (vetor, tamVetor[i]);
            	total = ((double)(end - start)) / CLOCKS_PER_SEC;
		printf ("Quick Sort c/ %d elementos fez %ld comparacoes em %f segundos\n", tamVetor[i], numComp, total);
            	free(vetor);
            	printf ("\n");
	}

	//Merge Sort
	for (int i = 0; i < N; i++) {
		vetor = (int*)malloc (tamVetor[i] * sizeof(int));
            	if (vetor == NULL) {
                	printf("Falha fatal. Impossível alocar memória.\n");
                	return 1;
            	}
            	preencheVetorAleatorio (vetor,tamVetor[i], tamVetor[i]);
		printf ("Vetor desordenado: ");
		imprimeVetor (vetor, tamVetor[i]);
            	numComp = total = 0;
            	start = clock();
            	numComp = mergeSort (vetor, tamVetor[i]);
            	end = clock();
		printf ("Vetor ordenado: ");
		imprimeVetor (vetor, tamVetor[i]);
            	total = ((double)(end - start)) / CLOCKS_PER_SEC;
		printf ("Merge Sort c/ %d elementos fez %ld comparacoes em %f segundos\n", tamVetor[i], numComp, total);
            	free(vetor);
            	printf ("\n");
	}

	//heapsort
	for (int i = 0; i < N; i++) {
		vetor = (int*)malloc (tamVetor[i] * sizeof(int));
            	if (vetor == NULL) {
                	printf("Falha fatal. Impossível alocar memória.\n");
                	return 1;
            	}
            	preencheVetorAleatorio (vetor,tamVetor[i], tamVetor[i]);
		printf ("Vetor desordenado: ");
		imprimeVetor (vetor, tamVetor[i]);
            	numComp = total = 0;
            	start = clock();
            	numComp = heapSort (vetor, tamVetor[i]);
            	end = clock();
		printf ("Vetor ordenado: ");
		imprimeVetor (vetor, tamVetor[i]);
            	total = ((double)(end - start)) / CLOCKS_PER_SEC;
		printf ("HeapSort c/ %d elementos fez %ld comparacoes em %f segundos\n", tamVetor[i], numComp, total);
            	free(vetor);
            	printf ("\n");
	}

	//Counting Sort
	for (int i = 0; i < N; i++) {
		vetorCounting = (unsigned int*)malloc (tamVetor[i] * sizeof(unsigned int));
		if (vetorCounting == NULL) {
			printf("Falha fatal. Impossível alocar memória.\n");
			return 1;
		}
            	preencheVetAleatCS(vetorCounting,tamVetor[i], tamVetor[i]);
		printf ("Vetor desordenado: ");
		imprimeVetorCS (vetorCounting, tamVetor[i]);
		numComp = total = 0;
		start = clock();
		countingSort (vetorCounting, tamVetor[i], tamVetor[i]);
		end = clock();
		printf ("Vetor ordenado: ");
		imprimeVetorCS (vetorCounting, tamVetor[i]);
		total = ((double)(end - start)) / CLOCKS_PER_SEC;
		printf ("Counting Sort c/ ordenou %d elementos  em %f segundos\n", tamVetor[i], total);
		free(vetorCounting);
		printf ("\n");
	}
	//Shell Sort
	for (int i = 0; i < N; i++) {
		vetor = (int*)malloc (tamVetor[i] * sizeof(int));
		if (vetor == NULL) {
			printf("Falha fatal. Impossível alocar memória.\n");
			return 1;
		}
		getNomeAlgoritmoExtra(nomeAlg);
		printf("Executando %s\n", nomeAlg);
            	preencheVetorAleatorio (vetor,tamVetor[i], tamVetor[i]);
		printf ("Vetor desordenado: ");
		imprimeVetor (vetor, tamVetor[i]);
		numComp = total = 0;
		start = clock();
		numComp = shellSort (vetor, tamVetor[i]);
		end = clock();
		printf ("Vetor ordenado: ");
		imprimeVetor (vetor, tamVetor[i]);
		total = ((double)(end - start)) / CLOCKS_PER_SEC;
		printf ("shell sort c/ %d elementos fez %ld comparacoes em %f segundos\n", tamVetor[i], numComp, total);
		free(vetor);
		printf ("\n");
	}


    return 0;

}
