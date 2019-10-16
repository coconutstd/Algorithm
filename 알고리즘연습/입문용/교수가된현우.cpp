#include <cstdio>

int main() {

	int t;
	scanf_s_s("%d", &t);
	while (t--) {
		int n,ans = 0;
		scanf_s_s("%d", &n);
		for (int i = 5; i <= n; i *= 5) {
			ans += n / i;
		}
		printf("%d\n", ans);
	}
}