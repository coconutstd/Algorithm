#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			printf("*");
		}
		for (int k = 0; k < 2 * (n-1-i); k++) {
			printf(" ");
		}
		for (int l = 0; l <= i; l++) {
			printf("*");
		}
		printf("\n");
	}
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-1-i; j++) {
			printf("*");
		}
		for (int k = 1; k <= 2 * (i+1); k++) {
			printf(" ");
		}
		for (int l = 0; l < n-1-i; l++) {
			printf("*");
		}
		printf("\n");
	}

}