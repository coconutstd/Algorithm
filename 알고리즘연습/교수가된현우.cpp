#include <cstdio>

int main() {

	int t;
	scanf("%d", &t);
	while (t--) {
		int n,ans = 0;
		scanf("%d", &n);
		for (int i = 5; i <= n; i *= 5) {
			ans += n / i;
		}
		printf("%d\n", ans);
	}
}