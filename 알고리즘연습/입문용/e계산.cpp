#include <cstdio>
double fact[10];
double e[10];
int main() {
	fact[0] = 1;
	e[0] = 1;
	for (int i = 1; i < 10; i++) {
		fact[i] = i * fact[i - 1];
	}
	printf("n e\n");
	printf("- -----------\n");
	for (int i = 0; i < 10; i++) {
		if (i == 0) {
			printf("%d %d\n", i, int(e[i]));
		}
		else if (i == 1) {
			printf("%d %d\n", i, int(e[i]));
		}
		else if (i == 2) {
			printf("%d %.1f\n", i, e[i]);
		}
		else {
			printf("%d %.9f\n", i, e[i]);
		}
		e[i + 1] = e[i] + (1 / fact[i+1]);
	}
}