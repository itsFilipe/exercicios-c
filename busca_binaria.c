#include <stdio.h>

// Função de busca binária
int buscaBinaria(int vetor[], int tamanho, int chave);

int main() {
	int numeros[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
	int tamanho = sizeof(numeros) / sizeof(numeros[0]); //encontrar tamanho array
	int chave;
	
	printf("Digite o numero que deseja buscar: ");
	scanf("%d", &chave);
	
	int resultado = buscaBinaria(numeros, tamanho, chave);
	
	if (resultado != -1) {
		printf("Numero %d encontrado na posicao %d \n", chave, resultado);
	} else {
		printf("Numero %d nao encontrado no vetor. \n", chave);
	}
	
	return 0;
}

int buscaBinaria(int vetor[], int tamanho, int chave) {
	int inicio = 0;
	int fim = tamanho - 1;
	
	while (inicio <= fim) {
		int meio = (inicio + fim) / 2;
		
		if (vetor[meio] == chave) {
			return meio; // elemento encontrado
		}
		else if (vetor[meio] < chave) {
			inicio = meio + 1;
		}
		else {
			fim = meio - 1;
		}
	}
	return -1; // elemento não encontrado	
}