#include <cstdio>
int arr[201];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		arr[a + 100]++;
	}
	scanf("%d", &n);
	printf("%d\n", arr[n + 100]);
}