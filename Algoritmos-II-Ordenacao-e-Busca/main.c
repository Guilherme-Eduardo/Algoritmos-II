#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

int main() {
	
	//Declarando variaveis
	char nome[MAX_CHAR_NOME];
   	long numComp;
	int idxBusca;
	
	//Tamanho dos vetores para os algoritmos
	int tamVetorQM[] = {1000,5000,10000};
    int tamVetorSI[] = {50000,100000,130000};
	int *vetor;

	// Para medir o temp
	clock_t start, end; 
	double total;
	
	//Minhas informacoes
	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n\n", getGRR());
    
	//Implementacao dos algoritmos de ordenacao
	
	//Quick Sort
	for (int j = 0; j < 3; j++) {
		vetor = malloc (tamVetorQM[j] * sizeof(int));
            	if (vetor == NULL) {
                	printf("Falha fatal. Impossível alocar memória.\n");
                	return 1;
            	}
            	preencheVetorDesordenado (vetor,tamVetorQM[j]);
		printf ("Vetor desordenado: ");
		imprimeVetor (vetor, tamVetorQM[j]);
           	numComp = total = 0;
            	start = clock(); 
            	numComp = quickSort (vetor, tamVetorQM[j]);
            	end = clock();
		printf ("Vetor ordenado: ");
		imprimeVetor (vetor, tamVetorQM[j]);
            	total = ((double)(end - start)) / CLOCKS_PER_SEC;
		printf ("Quick Sort c/ %d elementos fez %ld comparacoes em %f segundos\n", tamVetorQM[j], numComp, total);
            	free(vetor);
            	printf ("\n");
	}

	// 
	for (int j = 0; j < 3; j++) {
        	vetor = malloc (tamVetorQM[j] * sizeof(int));
            	if (vetor == NULL) {
                	printf("Falha fatal. Impossível alocar memória.\n");
                	return 1;
            	}
		preencheVetorDesordenado (vetor,tamVetorQM[j]);
		printf ("Vetor desordenado: ");
		imprimeVetor (vetor, tamVetorQM[j]);
            	numComp = total = 0;
            	start = clock();
            	numComp = mergeSort (vetor, tamVetorQM[j]);
            	end = clock();
		printf ("Vetor ordenado: ");
		imprimeVetor (vetor, tamVetorQM[j]);
            	total = ((double)(end - start)) / CLOCKS_PER_SEC;
		printf ("Merge Sort c/ %d elementos fez %ld comparacoes em %f segundos\n", tamVetorQM[j], numComp, total);
            	free(vetor);
            	printf ("\n");
	}

	//Insertion Sort
	for (int j = 0; j < 3; j++) {
        	vetor = malloc (tamVetorSI[j] * sizeof(int));
            	if (vetor == NULL) {
                	printf("Falha fatal. Impossível alocar memória.\n");
                	return 1;
            	}
            	preencheVetorDesordenado (vetor,tamVetorSI[j]);
		printf ("Vetor desordenado: ");
		imprimeVetor (vetor, tamVetorSI[j]);
            	numComp = total = 0;
            	start = clock();
            	numComp = insertionSort (vetor, tamVetorSI[j]);
            	end = clock();
		printf ("Vetor ordenado: ");
		imprimeVetor (vetor, tamVetorSI[j]);
            	total = ((double)(end - start)) / CLOCKS_PER_SEC;
		printf ("Insertion Sort c/ %d elementos fez %ld comparacoes em %f segundos\n", tamVetorSI[j], numComp, total);
            	free(vetor);
            	printf ("\n");
 	}

	//Selection Sort
	for (int j = 0; j < 3; j++) {
        	vetor = malloc (tamVetorSI[j] * sizeof(int));
            	if (vetor == NULL) {
                	printf("Falha fatal. Impossível alocar memória.\n");
                	return 1;
            	}
            	preencheVetorDesordenado (vetor,tamVetorSI[j]);
		printf ("Vetor desordenado: ");
		imprimeVetor (vetor, tamVetorSI[j]);
            	numComp = total = 0;
            	start = clock();
            	numComp = selectionSort (vetor, tamVetorSI[j]);
            	end = clock();
		printf ("Vetor ordenado: ");
		imprimeVetor (vetor, tamVetorSI[j]);
            	total = ((double)(end - start)) / CLOCKS_PER_SEC;
		printf ("Selection Sort c/ %d elementos fez %ld comparacoes em %f segundos\n", tamVetorSI[j], numComp, total);
            	free(vetor);
            	printf ("\n");
	}

	//Implementacao dos algoritmos de busca
	idxBusca = buscaSequencial(vetor, tamVetorSI[2], 150000, &numComp);
	printf("Busca Sequencial\nIndice: %d\nComparacoes: %ld\n", idxBusca, numComp);
	idxBusca = buscaBinaria(vetor, tamVetorSI[2], 150000, &numComp);
	printf("Busca Binaria\nIndice: %d\nComparacoes: %ld\n", idxBusca, numComp);

    return 0;
}

