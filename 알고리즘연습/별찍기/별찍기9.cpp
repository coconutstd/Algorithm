#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < i; k++) {
			printf(" ");
		}
		for (int j = 0; j < 2 * (n - i) - 1; j++) {
			printf("*");
		}	
		printf("\n");
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 2 -i; j++) {
			printf(" ");
		}
		for (int k = 0; k < 2 * (i +1) + 1; k++) {
			printf("*");
		}
		printf("\n");
	}
}