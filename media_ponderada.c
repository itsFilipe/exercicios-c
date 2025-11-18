#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	
	int n;
	float a, b, c;
	float media;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%f %f %f", &a, &b, &c);
		media = ( a * 2 + b * 3 + c * 5 ) / 10;
		printf("%.1f\n", media);
	}

	return 0;
}