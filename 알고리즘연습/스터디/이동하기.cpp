#include <cstdio>
#include <algorithm>
using namespace std;
int row, col;
int arr[1001][1001];
int dp[1001][1001];
int main() {
	scanf_s_s("%d %d", &row, &col);
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			scanf_s_s("%d", &arr[i][j]);
		}
	}
	dp[1][1] = arr[1][1];
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			int cur = arr[i][j];
			dp[i][j] = max(cur+dp[i-1][j-1],max(cur + dp[i - 1][j], cur + dp[i][j-1]));
		}
	}
	printf("%d\n", dp[row][col]);

}
