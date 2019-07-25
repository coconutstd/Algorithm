#include <cstdio>

int main() {
	int arr[7];
	for (int i = 0; i < 7; i++) {
		scanf("%d", &arr[i]);
	}
	int sum = 0, min = 100; 
	for (int i = 0; i < 7; i++) {
		if (arr[i] % 2 == 1) {
			if (arr[i] < min) min = arr[i];
			sum += arr[i];
		}
	}
	if (sum == 0) {
		printf("-1\n");
	}else
	printf("%d\n%d", sum, min);
}