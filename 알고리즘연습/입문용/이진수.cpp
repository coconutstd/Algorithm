#include <cstdio>

int main() {
	int t;
	scanf_s_s("%d", &t);
	while (t--) {
		int a;
		scanf_s_s("%d", &a);
		int div = 9999, mod = 0, cnt = 0;
		while (1) {	
			div = a / 2;
			mod = a % 2;
			a = div;
			if (mod == 1) {
				printf("%d ", cnt);
			}
			cnt++;
			if (div == 0) break;
		}
		printf("\n");
	}
}