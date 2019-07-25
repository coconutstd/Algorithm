#include <cstdio>

int arr[2][7];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int s, r;
		scanf("%d %d", &s, &r); 
		arr[s][r]++;
	}

	int ans = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= 6; j++) {
			if (arr[i][j] != 0) {
				if (arr[i][j] % k != 0) ans += arr[i][j] / k + 1;
				else ans += arr[i][j] / k;
			}
		}
	}
	printf("%d\n", ans);
}