#include <cstdio>
int arr[5];

int main() {
	int n,a,b;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		if (a == 0 || b == 0) { arr[4]++; }
		else if (a > 0 && b > 0) { arr[0]++; }
		else if (a < 0 && b > 0) { arr[1]++; }
		else if (a < 0 && b < 0) { arr[2]++; }
		else { arr[3]++; }
	}
	for (int i = 0; i < 5; i++) {
		if (i == 4) { printf("AXIS: %d\n", arr[4]); break; }
		printf("Q%d: %d\n", i + 1, arr[i]);
	}
}