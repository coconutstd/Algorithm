#include <cstdio>

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int mul = a * b;
	for (int i = 0; i < 5; i++) {
		int c;
		scanf("%d", &c);
		printf("%d ", c - mul);
	}
}