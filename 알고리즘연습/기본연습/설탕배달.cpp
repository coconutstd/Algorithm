#include <iostream>
#include <algorithm>
using namespace std;
int N;
int d[1001][1001];

int main() {
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			d[i][j] = (3 * i) + (5 * j);
		}
	}

	scanf("%d", &N);
	int ans = 200000;
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			if (d[i][j] == N) {
				ans = min(ans, i + j);
			}
		}
	}

	if (ans == 200000) {
		printf("-1\n");
	}
	else {
		printf("%d\n", ans);
	}
}
