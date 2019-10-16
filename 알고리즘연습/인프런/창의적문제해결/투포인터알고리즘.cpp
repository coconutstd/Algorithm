#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
/*
10
68 24 65 59 37 27 85 71 62 38
15
15 31 71 48 23 77 83 16 64 46 29 67 17 98 62
*/


int main() {
	int n, m, p1 = 0, p2 = 0, p3 = 0;
	scanf_s_s("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		scanf_s_s("%d", &a[i]);
	}
	sort(a.begin(), a.end());
	scanf_s_s("%d", &m);
	vector<int> b(m), c(n + m);
	for (int i = 0; i < m; i++) {
		scanf_s_s("%d", &b[i]);
	}
	sort(b.begin(), b.end());


	while (p1 != n && p2 != m) {
		if (a[p1] == b[p2]) {
			c[p3++] = a[p1++];
			p2++;
		}
		else if (a[p1] < b[p2]) p1++;
		else p2++;
	}

	for (int i = 0; i < p3; i++) {
		printf("%d ", c[i]);
	}

}