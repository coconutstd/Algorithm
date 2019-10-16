#include <cstdio>

int main() {
	int a, b, c;
	scanf_s_s("%d %d %d", &a, &b, &c);
	printf("%d\n", a * b <= c ? 0 : a *b -c);
}