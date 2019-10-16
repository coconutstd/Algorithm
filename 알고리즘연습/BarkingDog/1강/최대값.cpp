#include <cstdio>

int main() {
	int arr[9];
	for (int i = 0; i < 9; i++) {
		scanf_s_s("%d", &arr[i]);
	}
	int max = 0, loc;
	for (int i = 0; i < 9; i++) {
		if (arr[i] > max) {
			max = arr[i]; loc = i;
		}
	}
	printf("%d\n%d", max, loc + 1);
}