#include <cstdio>

int main() {
	int t;
	scanf_s_s("%d", &t);
	while (t--) {
		int y_sum=0, k_sum=0,y,k;
		for (int i = 0; i < 9; i++) {
			scanf_s_s("%d %d", &y, &k);
			y_sum += y; k_sum += k;
		}
		if (y_sum > k_sum) {
			printf("Yonsei\n");
		}
		else if (y_sum < k_sum) {
			printf("Korea\n");
		}
		else {
			printf("Draw\n");
		}
	}
}