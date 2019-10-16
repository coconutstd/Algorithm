#include <stdio.h>
using namespace std;

int a[101], b[101], c[101];

int main() {
	int m, n;
	int pt1 = 0, pt2 = 0, pt3 = 0;
	scanf_s("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf_s("%d", &a[i]);
	}
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &b[i]);
	}

	while (pt1 < m && pt2 < n) {
		if (a[pt1] < b[pt2]) {
			c[pt3++] = a[pt1++];
		}
		else {
			c[pt3++] = b[pt2++];
		}
	}

	while (pt1 < m) c[pt3++] = a[pt1++];
	while (pt2 < n) c[pt3++] = b[pt2++];

	for (int i = 0; i < pt3; i++) {
		printf("%d ", c[i]);
	}


}