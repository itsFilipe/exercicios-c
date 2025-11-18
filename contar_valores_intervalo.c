#include <stdio.h>

int main() {
	
	int n, contIn = 0, contOut = 0;
	scanf("%d", &n);

	int valor_atual;

	for (int i = 0; i < n; i++) {
		scanf("%d", &valor_atual);

		if (valor_atual >= 10 && valor_atual <= 20)
			contIn++;
		else
			contOut++;
	}

	printf("%d in\n", contIn);
	printf("%d out\n", contOut);

	return 0;
}