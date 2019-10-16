#include <cstdio>
int arr[201];
int main() {
	int n;
	scanf_s_s("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf_s_s("%d", &a);
		arr[a + 100]++;
	}
	scanf_s_s("%d", &n);
	printf("%d\n", arr[n + 100]);
}