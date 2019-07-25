#include <cstdio>

void s() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3 - i - 1; j++) {
			printf(" ");
		}
		for (int k = 0; k <= i; k++) {
			printf("*");
		}
		for (int l = 0; l < 3 - i - 1; l++) {
			printf(" ");
		}
		printf("\n");
	}
}

int main() {
	int n;
	scanf("%d", n);
	for (int i = 0; i < n / 3; i++) {
		for(int j = 0; j < )
	}

}

