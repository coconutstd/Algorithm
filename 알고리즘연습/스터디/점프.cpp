#include <cstdio>
int n;
int map[101][101];
long long dp[101][101];

long long dfs(int row, int col) {
	if (dp[row][col]) { return dp[row][col]; }
	if (row == n - 1 && col == n - 1) { return 1; }
	if (map[row][col] == 0) { return 0; }
	if (row >= n || col >= n) { return 0; }
	long long ret = 0;
	ret += dfs(row + map[row][col], col);
	ret += dfs(row, col + map[row][col]);
	dp[row][col] = ret;
	return ret;
}

int main() {
	scanf_s_s("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s_s("%d", &map[i][j]);
		}
	}

	printf("%ld\n", dfs(0, 0));
}