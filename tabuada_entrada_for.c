#define _CRT_SECURE_NO_WARNINGS //para visual studio
#include <stdio.h>
#include <math.h>

int main() {
	
	int n;

	scanf("%d", &n);

	for (int i = 2; i <= n; i++) {
		if (i % 2 == 0) {
			printf("%d^2 = %d\n", i, i * i);
		}
	}

	return 0;
}