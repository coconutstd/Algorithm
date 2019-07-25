#include <cstdio>

int a, b, c, d;
int p[3];

int main() {
	scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &p[0], &p[1], &p[2]);
	int cnt = 0, mod1=0,mod2=0;
	for (int i = 0; i < 3; i++) {
		cnt = 0;
		mod1 = p[i] % (a + b);
		mod2 = p[i] % (c + d);
		if (mod1 != 0 && mod1 <= a) {
			cnt++;
		}
		if (mod2 != 0 && mod2 <= c) {
			cnt++;
		}
		printf("%d\n", cnt);
	}
}