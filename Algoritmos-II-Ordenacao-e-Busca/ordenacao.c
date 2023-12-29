#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenacao.h"

//Retorna o nome do usuario
void getNome(char nome[]){
	strncpy(nome, "Guilherme Eduardo Gonçalves da Silva", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME-1] = '\0';//adicionada terminação manual para caso de overflow
}

//Retornar o número do GRR
unsigned int getGRR(){
	return 20231950;
}

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
void preencheVetorAleatorio (int vet[], int maxPos, int maxVal) {
	int i;
	for (i = 0; i < maxPos; i++)
		*(vet + i) = rand() %maxVal;
}


void copiarVetor(int vet[], int aux[], int tamVets){
	int i;
	for(i = 0; i < tamVets; i++)
		*(vet + i) = *(aux + i);
	return;
}

void imprimeVetor (int vet[], int tam) {
	int i;
	if (tam <= 10) {
		for (i = 0; i < tam; i++)
			printf ("%d ", *(vet + i));
		printf ("\n");
	}
	else {
		for (i = 0; i < 5; i++)
			printf ("%d ", *(vet + i));
		printf ("... ");
		for (i = tam - 5; i < tam; i++)
			printf ("%d ", vet[i]);
		printf ("\n");		
	}
}

//troca elementos de um vetor
void troca (int vetor[], int a, int b) {
	int aux;
	aux = vetor[a];
	vetor[a] = vetor[b];
	vetor[b] = aux;
}

//Algoritmo de busca ingenua. Retorna a posicao do vetor quando encontra o valor determinado, caso contrario, retorna -1.
int buscaSequencialAux (int vetor[], int inicio, int fim, int valor, long *numComparacoes) {
	if (inicio > fim)
		return -1;
	(*numComparacoes)++;
	if (valor == vetor[fim]) 
		return fim;
	return buscaSequencialAux (vetor,inicio, fim -1, valor, numComparacoes);
}

//Função principal do buscaSequencial (Wrapper)
int buscaSequencial(int vetor[], int tam, int valor, long* numComparacoes){
	if (tam <= 0)
		return -1;
	int inicio, fim, indice;
	*numComparacoes = inicio = 0;
	fim = tam - 1;
	indice = buscaSequencialAux (vetor, inicio, fim, valor, numComparacoes);
	if (indice == -1)
		printf ("\nNumero %d nao encontrado!\n", valor);
	return indice;
}

//Busca Binaria. Função auxiliar que retorna a posicao do vetor quando encontra o valor (de forma logaritmica), caso não, retorna -1.
int buscaBinariaAux (int vetor[], int inicio, int fim, int valor, long *numComparacoes) {
	if (inicio > fim)
		return -1;
	int m;
	m = (inicio + fim) / 2;
	(*numComparacoes)++;
	if (valor == vetor[m])
		return m;
	if (valor > vetor[m])
		return buscaBinariaAux(vetor, m + 1, fim, valor, numComparacoes);
	return buscaBinariaAux(vetor, inicio, m - 1, valor, numComparacoes);
}

//Algortimo Recursiva do Busca Binaria (Funcao Wrapper).
int buscaBinaria (int vetor[], int tam, int valor, long *numComparacoes){
	if (tam <= 0)
		return -1;
	int inicio, fim, indice;
	*numComparacoes = inicio = 0;
	fim = tam - 1;
	indice = buscaBinariaAux (vetor, inicio, fim, valor, numComparacoes);
	if (indice == -1)
		printf ("\nNumero %d nao encontrado!\n", valor);
	return indice;
}

//Funcao responsavel por retornar o indice do vetor onde valor determinado (x) deveria estar;
int buscar ( int x, int vet[], int inicio, int fim, long *numComparacoes) {
	if (inicio > fim)
		return - 1;
	(*numComparacoes)++;
	if (vet[fim] <= x)
		return fim;
	return buscar ( x, vet, inicio, fim - 1, numComparacoes);

}

//Funcao responsavel por retornar o menor valor de um vetor de fim - inicio + 1 posicoes.
int minimoVetor (int vetor[], int inicio, int  fim, long *numComparacoes) {
	if (inicio >= fim)
		return inicio; 
	int m;
	m = minimoVetor (vetor, inicio, fim - 1, numComparacoes);
	(*numComparacoes)++;
	if (vetor[m] > vetor[fim])
		m = fim;	
	return m;
}
//Funcao auxiliar utilizada em conjunto com o insertion Sort. Determina onde um valor deveria estar e realiza trocas.
long inserir(int v[], int a, int b, long *numComparacoes) {
    	int p = buscar(v[b], v, a, b - 1, numComparacoes);
    	int i = b;
    	while (i > p + 1) {
        	troca(v, i, i - 1);
        	i--;
    	}
    	return *numComparacoes;
}

//Funcao auxiliar usada para ordenar o vetor conforme o algoritmo do insertion Sort.
long insertionSortAux(int v[], int a, int b, long *numComparacoes) {
    	if (a > b)
        	return -1;
    	insertionSortAux(v, a, b - 1, numComparacoes);
    	inserir(v, a, b, numComparacoes);
    	return *numComparacoes;
}

//Algoritmo do insertion Sort (Wrapper).
long insertionSort (int v[], int tam) {
    	if (tam <= 0)    
        	return -1;
    	int inicio, fim;
    	long numComparacoes;
    	inicio = numComparacoes = 0;
    	fim = tam - 1;
    	insertionSortAux (v, inicio, fim, &numComparacoes);
    	return numComparacoes;
    
}

//Funcao auxiliar responsavel por ordenar o vetor conforme o algoritmo do Selection Sort.
long selectionSortAux (int vetor[], int inicio, int fim, long *numComparacoes) {
	if (inicio >= fim)
		return -1 ;
	int m;
	m = minimoVetor (vetor, inicio, fim, numComparacoes);
	troca (vetor, inicio, m);
	selectionSortAux (vetor, inicio + 1, fim, numComparacoes);
	return *numComparacoes;
}

//Algoritmo do Selection Sort (Wrapper).
long selectionSort (int vetor[], int tam) {
	if (tam <= 0)
		return -1;
	int inicio, fim;
	long numComparacoes;
	inicio = numComparacoes = 0;
	fim = tam - 1;
	selectionSortAux (vetor, inicio, fim, &numComparacoes);
	return numComparacoes;
}

//Funcao responsavel por ordenar o vetor utilizando um vetor secundario. Reparte o vetor principal ao meio e ordena nesse subvetor criado.
int merge (int vetor[], int inicio, int m, int fim, long *numComparacoes) {
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

//Funcao auxiliar que realize as particoes dos subvetores para que seja possivel agrupa-los de forma ordenada.
int mergeSortAux (int vetor[], int inicio, int fim, long *numComparacoes) {
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
long mergeSort(int vetor[], int tam){
	if (tam <= 0)
		return -1;
	int inicio, fim;
	long numComparacoes;
	inicio = 0;
	numComparacoes = 0;
	fim = tam - 1;	
	mergeSortAux(vetor, inicio, fim, &numComparacoes);
	return numComparacoes;
}

//Funcao responsavel por retornar o valor do pivo para a funcao quicksortAux. O pivo é o último elemento
int particionarPadrao (int vetor[], int inicioVet, int fimVet, long *numComparacoes) {
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
int particionar(int vetor[], int inicioVet, int fimVet, long *numComparacoes) {
    int n = fimVet - inicioVet + 1;
    int tercoN = n / 3;

    //calcula o índice aleatório i dentro da faixa definida pelas condições n/3 ≤ i ≤ 2n/3
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
void quickSortAux (int vetor[], int inicio, int fim, long *numComparacoes) {
	if (inicio >= fim)
		return;
	int posPivo;
	posPivo= particionar (vetor, inicio, fim, numComparacoes);
	quickSortAux (vetor, inicio, posPivo - 1, numComparacoes);
	quickSortAux (vetor, posPivo + 1, fim, numComparacoes);
}

//Algoritmo do Quick Sort (Funcao Wrapper)
long quickSort(int vetor[], int tam){
	if (tam <= 0)
		return -1;
	int inicio, fim;
	long numComparacoes;
	inicio = numComparacoes = 0;
	fim = tam - 1;
	quickSortAux (vetor, inicio, fim, &numComparacoes);
	return numComparacoes;
}

