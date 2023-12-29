#ifndef ORDENACAO_H_
#define ORDENACAO_H_

#define MAX_CHAR 50

// a função getNome deve colocar o seu nome no vetor
// seu nome pode ter no máximo MAX_CHAR_NOME - 1 caracteres
void getNome(char nome[]);

// a função getNomeAlgoritmoExtra deve colocar o nome do algoritmo
// extra implementado no trabalho
void getNomeAlgoritmoExtra(char nomeAlg[]);

// a função a seguir deve retornar o seu número de GRR
unsigned int getGRR();

// Cada uma das funções deve ordenar o vetor passado como parâmetro

// O retorno das funções de ordenação é o número de comparações
// entre elementos do vetor

unsigned long mergeSort(int vetor[], int tam);

unsigned long quickSort(int vetor[], int tam);

unsigned long heapSort(int vetor[], int tam);

void countingSort(unsigned int vetor[], int tam,
                  int maxVal);  // maxVal é o k do algoritmo

// Na função algoritmoExtra implemente o algoritmo extra solicitado.
// Se o seu algoritmo escolhido não faz comparações, retorne -1.
unsigned long shellSort(int vetor[], int tam);


/****************Funcoes Auxiliares*******************************/

//Preenche um vetor Aleatorio para o algoritmo Counting Sort
void preencheVetAleatCS (unsigned int vetor[], int maxPos, int maxVal);

//Preenche um vetor com valores aleatorios seguindo um numero max de posicoes do vetor
void preencheVetorAleatorio (int vetor[], int maxPos, int maxVal);

//Preenche o vetor de forma ordenada se 0 ate o valor maxPos
void preencheVetorOrdenado (int vetor[], int maxPos);

//Preenche o vetor de forma desordenada de maxPos ate 0
void preencheVetorDesordenado (int vetor[], int maxPos);

void imprimeVetor (int vetor[], int tam);

void imprimeVetorCS (unsigned int vetor[], int tam);

#endif  // ORDENACAO_H_
