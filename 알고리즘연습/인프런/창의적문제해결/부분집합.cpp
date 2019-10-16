#include <stdio.h>

int n;
int ch[11];
void dfs(int v) {
	if (v == n + 1) {
		for (int i = 1; i <= n; i++) {
			if (ch[i] == 1)printf("%d ", i);
		}
		puts("");
	}
	else {
		ch[v] = 1;
		dfs(v + 1);
		ch[v] = 0;
		dfs(v + 1);
	}
}

int main() {
	scanf_s("%d", &n);
	dfs(1);
	return 0;
}