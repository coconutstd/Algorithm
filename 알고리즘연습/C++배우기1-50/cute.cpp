#include <cstdio>
int arr[2];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		arr[a]++;
	}
	if (arr[0] > arr[1]) {
		printf("Junhee is not cute!\n");
	}
	else {
		printf("Junhee is cute!\n");
	}
}