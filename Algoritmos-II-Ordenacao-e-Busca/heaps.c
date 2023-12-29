#include <stdio.h>
#include <stdlib.h>

#define N 10

int indicePai (int i) {
	return i >> 1;
}

int indiceFilhoEsquerdo (int i) {
	return (i << 1) + 1;
}

int indiceFilhoDireito (int i) {
	return (i << 1) + 2;
}

void imprimeVetor (int v[], int n) {
	if (!v)
		return;
	int i;
	for (i = 0; i < n; i++)
		printf (" %d ", *(v + i));
	printf ("\n");
}

void trocar (int v[], int a, int b) {
	if (!v)
		return;
	int aux;
	aux = v[a];
	v[a] = v[b];
	v[b] = aux;
}

void maxHeapify (int h[], int i, int n) {
	if (!h)
		return;
	int l,r, maior;
	l = indiceFilhoEsquerdo (i);
	r = indiceFilhoDireito (i);
	//printf ("L: %d\nD: %d\n", l,r);
	if (l < n  && h[l] > h[i]) 
		maior = l;
	else
		maior = i;

	if (r < n  && h[r] > h[maior])
		maior = r;
	if (maior != i) {
		trocar (h, i, maior);
		maxHeapify (h, maior, n);
	}
	return;
}

int main () {
	int vet [10] = {16,4,3,14,7,9,10,2,8,1};
	printf ("Antes: ");
	imprimeVetor (vet, N);
	maxHeapify (vet, 1, N);
	printf ("Depois: ");
	imprimeVetor (vet, N);
	return 0;
	
}
