#include <cstdio>
int arr[2001];
int dp[2001][2001];
int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i <= n; i++) { dp[i][i] = 1; }
	for (int i = 1; i <= n - 1; i++) {
		if (arr[i] == arr[i + 1]) { dp[i][i + 1] = 1; }
		else { dp[i][i + 1] = 0; }
	}


	for (int i = 2; i <= n - 1; i++) {
		for (int j = 1; j <= n - i; j++) {
			if (arr[j] == arr[j + i] && dp[j + 1][j + i -1] == 1) {
				dp[j][j + i] = 1;
			}
		}
	}

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", dp[s][e]);
	}
	

}