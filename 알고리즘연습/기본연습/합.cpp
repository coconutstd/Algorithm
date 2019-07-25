#include <cstdio>

int T;
int N;
int a[100000];

int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[j]);
		}
		int max = -1001;
		int sum = a[0];
		int fcnt = 0, rcnt = 0;
		
		while (1) {
			if (sum <= 0) sum -= a[fcnt++];
			else if (rcnt == N) break;
			else {
				sum += a[fcnt++];
				if (sum > max) max = sum;
			}
		}
		printf("%d\n", max);
	}
}
