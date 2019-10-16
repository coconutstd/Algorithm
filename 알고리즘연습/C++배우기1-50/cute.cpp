#include <cstdio>
int arr[2];
int main() {
	int n;
	scanf_s_s("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf_s_s("%d", &a);
		arr[a]++;
	}
	if (arr[0] > arr[1]) {
		printf("Junhee is not cute!\n");
	}
	else {
		printf("Junhee is cute!\n");
	}
}