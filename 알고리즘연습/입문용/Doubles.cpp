#include <cstdio>

bool num[101];

int main() {
	int a,size=0,ans=0;
	while (scanf_s_s("%d", &a)) {
		if (a == 0) {
			ans = 0;
			for (int i = 1; i < 101; i++) {
				if (num[i] == 1 && num[i * 2] == 1) ans++;
			}
			printf("%d\n", ans);
			for (int i = 1; i < 101; i++) {
				num[i] = 0;
			}
			continue;
		}
		else if (a == -1) { break; }
		num[a] = 1;
	}
}
