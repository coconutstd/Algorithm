#include <cstdio>

int main() {
	int a, b;
	scanf_s_s("%d %d", &a, &b);
	int mul = a * b;
	for (int i = 0; i < 5; i++) {
		int c;
		scanf_s_s("%d", &c);
		printf("%d ", c - mul);
	}
}