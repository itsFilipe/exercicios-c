#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
	int n;
	scanf("%d", &n);
	
	// Alocação dinâmica
	int* numeros = (int*)malloc(n * sizeof(int));
	if (numeros == NULL) {
		// Tratamento de erro se a alocação falhar
		printf("Erro de alocacao de memoria!\n");
		return 1;
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &numeros[i]);
	}
	
	for (int i = 0; i < n; i++) {
		if (numeros[i] > 0) { //positivo
			if (numeros[i] % 2 == 0)
				printf("EVEN POSITIVE\n");
			else
				printf("ODD POSITIVE\n");
		}
		else if (numeros[i] < 0) { //negativo
			if (numeros[i] % 2 == 0)
				printf("EVEN NEGATIVE\n");
			else
				printf("ODD NEGATIVE\n");
		}
		else {
			printf("NULL\n");
		}
	}
	
	free(numeros); //???
	
	return 0;
}