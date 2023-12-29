#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ordenacao.h"

void getNome(char nome[]) {
	// substitua por seu nome
	strncpy(nome, "Guilherme Eduardo Goncalves da Silva", MAX_CHAR);
	// adicionada terminação manual para caso de overflow
	nome[MAX_CHAR - 1] = '\0';
}

void getNomeAlgoritmoExtra(char nomeAlg[]) {
	// substitua pelo nome do algoritmo que você escolheu
	strncpy(nomeAlg, "Shell Sort", MAX_CHAR);
	nomeAlg[MAX_CHAR - 1] = '\0';
}

// a função a seguir deve retornar o seu número de GRR
unsigned int getGRR() { return 20231950; }


/********************- Funcoes Auxiliares - **********************************/

//Preenche o vetor de forma ordenada de 0 ate o valor maxPos
void preencheVetorOrdenado (int vetor[], int maxPos) {
	int i;
	for (i = 0; i < maxPos; i++)
		*(vetor + i) = i;
}

//Preenche o vetor de forma desordenada de maxPos até 0
void preencheVetorDesordenado (int vetor[], int maxPos) {
	int i, n;
	n = maxPos;
	for (i = 0; i < n; i++) {
		vetor[i] = maxPos;
		maxPos--;
	}
}

//Preenche um vetor com valores aleatorios seguindo um numero max de posicoes do vetor
void preencheVetorAleatorio (int vetor[], int maxPos, int maxVal) {
	int i;
	for (i = 0; i < maxPos; i++)
		*(vetor + i) = rand() % maxVal;
}

//Preenche um vetor com valores aleatorios para o Counting Sort(unsigned int).
void preencheVetAleatCS (unsigned int vetor[], int maxPos, int maxVal) {
	int i;
	for (i = 0; i < maxPos; i++)
		*(vetor + i) = rand() % maxVal;
}


void copiarVetor(int vetor[], int aux[], int tamVets){
	int i;
	for(i = 0; i < tamVets; i++)
		*(vetor + i) = *(aux + i);
	return;
}

void imprimeVetor (int vetor[], int tam) {
	int i;
	if (tam <= 10) {
		for (i = 0; i < tam; i++)
			printf ("%d ", *(vetor + i));
		printf ("\n");
	}
	else {
		for (i = 0; i < 5; i++)
			printf ("%d ", *(vetor + i));
		printf ("... ");
		for (i = tam - 5; i < tam; i++)
			printf ("%d ", vetor[i]);
		printf ("\n");		
	}
}

void imprimeVetorCS (unsigned int vetor[], int tam) {
	int i;
	if (tam <= 10) {
		for (i = 0; i < tam; i++)
			printf ("%d ", *(vetor + i));
		printf ("\n");
	}
	else {
		for (i = 0; i < 5; i++)
			printf ("%d ", *(vetor + i));
		printf ("... ");
		for (i = tam - 5; i < tam; i++)
			printf ("%d ", vetor[i]);
		printf ("\n");		
	}

}

//Funcao responsavel pela troca de elementos de um vetor
void troca (int vetor[], int a, int b) {
	int aux;
	aux = vetor[a];
	vetor[a] = vetor[b];
	vetor[b] = aux;
}

/*********************** - implementacao do MergeSort******************/

//Funcao responsavel por ordenar o vetor utilizando um vetor secundario. 
//Reparte o vetor principal ao meio e ordena nesse subvetor criado.
int merge (int vetor[], int inicio, int m, int fim, unsigned long *numComparacoes) {
	if (inicio >= fim)
		return - 1;
	int k, i, j, aux, tam;
	tam = fim - inicio + 1;
	int *vetorU = malloc (tam * sizeof (int));
	if (!vetorU) {
		printf ("Falha ao alocar memoria\n");
		return -1;
	}
	aux = k = 0;
	i = inicio;
	j = m +1;

	while (k <= fim - inicio) {
		if (j > fim || (i <= m && vetor[i] <= vetor[j])) {
			aux = i;
			i++;
		}
		else {
			aux = j;
			j++;
		}
		(*numComparacoes)++;
		vetorU[k] = vetor[aux];
		k++;
	}
	copiarVetor (vetor + inicio, vetorU, fim - inicio + 1);
	free (vetorU);	
	return 1;
}

//Funcao auxiliar que realize as particoes dos subvetores 
//para que seja possivel agrupa-los de forma ordenada.
int mergeSortAux (int vetor[], int inicio, int fim, unsigned long *numComparacoes) {
	if (inicio >= fim)
		return -1;
	int m;
	m = (inicio + fim) / 2;
	mergeSortAux (vetor, inicio, m, numComparacoes);
	mergeSortAux (vetor, m + 1, fim, numComparacoes);
	merge (vetor, inicio, m, fim, numComparacoes);
	return 1;
}

//Algoritmo do merge Sort (Wrapper).
unsigned long mergeSort(int vetor[], int tam){
	if (tam <= 0)
		return -1;
	int inicio, fim;
	unsigned long numComparacoes;
	inicio = 0;
	numComparacoes = 0;
	fim = tam - 1;	
	mergeSortAux(vetor, inicio, fim, &numComparacoes);
	return numComparacoes;
}


/******************** - Implementação QuickSort - ***************************/

//Funcao responsavel por retornar o valor do pivo para a funcao quicksortAux. 
//O pivo é o último elemento
int particionarPadrao (int vetor[], int inicioVet, int fimVet, unsigned long *numComparacoes) {
	int i, pivo, posPivo;
	pivo = vetor[fimVet];
	posPivo = inicioVet;
	for (i = inicioVet; i < fimVet; i++) {
		if (vetor[i] <= pivo) {
			troca (vetor, posPivo, i);
			posPivo++;
		}
		(*numComparacoes)++;
	}
	troca (vetor, posPivo, fimVet);
	return posPivo;
}

//Funcao responsavel por retornar o valor do pivo para a funcao quicksortAux
int particionar(int vetor[], int inicioVet, int fimVet, unsigned long *numComparacoes) {
    int n = fimVet - inicioVet + 1;
    int tercoN = n / 3;

    //calcula o índice aleatório i dentro da faixa definida pelas condições n/3 ≤ i ≤ 2n/3
    //Baseado no livro do Cormem
    int i = inicioVet + tercoN + rand() % (n - 2 * tercoN);

    // Trocar o elemento no índice aleatório com o último elemento do vetor
    troca(vetor, i, fimVet);

    int pivo = vetor[fimVet];
    int posPivo = inicioVet;

    for (i = inicioVet; i <= fimVet - 1; i++) {
        if (vetor[i] <= pivo) {
            troca(vetor, posPivo, i);
            posPivo++;
        }
        (*numComparacoes)++;
    }
    troca(vetor, posPivo, fimVet);
    return posPivo;
}

//Funcao auxiliar do quickSort que realiza a ordenacao do vetor de forma recursiva
unsigned long quickSortAux (int vetor[], int inicio, int fim, unsigned long *numComparacoes) {
	if (inicio >= fim)
		return -1;
	int posPivo;
	posPivo= particionar (vetor, inicio, fim, numComparacoes);
	quickSortAux (vetor, inicio, posPivo - 1, numComparacoes);
	quickSortAux (vetor, posPivo + 1, fim, numComparacoes);
	return *numComparacoes;
}

//Algoritmo do Quick Sort (Funcao Wrapper)
unsigned long quickSort(int vetor[], int tam){
	if (tam <= 0)
		return -1;
	int inicio, fim;
	unsigned long numComparacoes;
	inicio = numComparacoes = 0;
	fim = tam - 1;
	return quickSortAux (vetor, inicio, fim, &numComparacoes);
	//return numComparacoes;
}

/********************* - Implementação do HeapSort - *******************/

//Retorna o indice do pai desse no
int indicePai (int i) {
	return i >> 1;
}

//Retorna o indice do filho esquerdo desse no
int indiceFilhoEsquerdo (int i) {
	return (i << 1) + 1;
}

//Retorna o indice do filho direito desse no
int indiceFilhoDireita (int i) {
	return (i << 1) + 2;
}

//Retorna o vetor modificado conforme propriedades de uma max-heap
void maxHeapify (int h[], int i, int n, unsigned long *numComparacoes) {
	if (!h)
		return ;
	int l,r, maior;
	l = indiceFilhoEsquerdo (i);
	r = indiceFilhoDireita (i);

	(*numComparacoes)++;

	if (l < n  && h[l] > h[i]) 
		maior = l;
	
	else
		maior = i;

	(*numComparacoes)++;
	if (r < n  && h[r] > h[maior])
		maior = r;
	
	if (maior != i) {
		troca (h, i, maior);
		maxHeapify (h, maior, n, numComparacoes);
	}
}

//Retorna o vetor modificado conforme propriedades de uma max-heap
void construirMaxHeap (int vetor[], int tam, unsigned long *numComparacoes) {
	int i;
	for (i = tam / 2; i >= 0; i--) {
		maxHeapify (vetor, i, tam, numComparacoes);
	}
}

//Funcao auxiliar do Heap Sort que realiza a ordenacao do vetor
unsigned long heapSortAux (int vetor[], int tam, unsigned long *numComparacoes) {
	int i;
	*numComparacoes = 0;
	construirMaxHeap (vetor, tam, numComparacoes);
	for (i = tam - 1; i > 0; i--) {
		troca (vetor, 0, i);
		tam--;
		maxHeapify (vetor, 0, tam, numComparacoes);
	}
	return *numComparacoes;
}

//Algoritmo do Heap Sort (Funcao Wrapper)
unsigned long heapSort (int vetor[], int tam) {
	if (tam <= 0)
		return -1;
	unsigned long numComparacoes = 0;
	return heapSortAux (vetor, tam, &numComparacoes);	
}

/***************** - Implementacao do CountingSort - ****************/

//Funcao auxiliar do Counting Sort que realiza a ordenacao do vetor
unsigned int *countingSortAux (unsigned int v[], int n, int k, unsigned long *numAtribuicoes) {
	if (n <= 0)
		return NULL;
	int i, j;

	unsigned int *r, *c;
	r = malloc (n * sizeof (int));
	c = malloc ((k + 1) * sizeof (int));
	if (!r || !c)
		return NULL;

	//Inicializa o vetor
	for (i = 0; i < k; i++)
		c[i] = 0;

	//Conta quantas vezes cada elemento aparece
	for (j = 0; j < n; j++)
		c[v[j]] = c[v[j]] + 1;

	//Soma cumulativa
	for (i = 1; i < k; i++)
		c[i] = c[i] + c[i - 1];

	//Usa a soma cumulativa para identificar quantos elementos sao < ou ==
	for (j = n - 1; j >= 0; j--) {
		r [c[v[j]] - 1] = v[j];
		c[v[j]] = c [v[j]] - 1;
	}

	*numAtribuicoes = 2 * n + 2 * k;

	// Copia o vetor ordenado para v
	for (i = 0; i < n; i++)
		v[i] = r[i];

	free (r);
	free (c);
	return v;
}

//Algoritmo do Counting Sort (Funcao Wrapper)
void countingSort(unsigned int vetor[], int tam, int maxVal) {
	if (tam <= 0)
		return;
	unsigned long numAtribuicoes = 0;
	vetor = countingSortAux (vetor, tam, maxVal, &numAtribuicoes);
	return;
}

/********************* Algoritmo Extra (Shell Sort) ************************/

//Algoritmo do Shell Sort
unsigned long shellSort(int vetor[], int tam) {
	if (tam <= 0)
		return 0;

	int i, j, h, aux;
	unsigned long numComparacoes = 0;

	//Formula para determinar o calculo da distancia h
	//E a quantidade de varreduras k
	//conforme Donald Knuth
	float k = log(tam + 1) / log(3);
	k = floor(k + 0.5);
	h = (pow(3, k) - 1) / 2;

	while (h > 0) {
		for (i = 0; i < tam - h; i++) {
			numComparacoes++;
			if (vetor[i] > vetor[i + h]) {
				aux = vetor[i + h];
				vetor[i + h] = vetor[i];
				vetor[i] = aux;

				j = i - h;
				while (j >= 0) {
					numComparacoes++;
					if (aux < vetor[j]) {
						vetor[j + h] = vetor[j];
						vetor[j] = aux;
					} else
						break;

					j = j - h;
				}
			}
		} h = (h - 1) / 3;
	}

	return numComparacoes;
}
