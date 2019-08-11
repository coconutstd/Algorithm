#include <cstdio>

int main() {
	int chang = 100, sang =100;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int c, s;
		scanf("%d %d", &c, &s);
		if (c < s) {
			chang -= s;
		}
		else if (s < c) {
			sang -= c;
		}
	}
	printf("%d\n%d\n", chang, sang);
}