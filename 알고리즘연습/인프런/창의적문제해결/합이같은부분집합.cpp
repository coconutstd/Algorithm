#include <stdio.h>
#include <vector>
using namespace std;
/*
6
2 4 5 10 12 13
*/

int n;

bool dfs(int v, vector<int>& a, vector<int>& ch) {
	if (v == n + 1) {
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < n; i++) {
			if (ch[i] == 1) {
				sum1 += a[i];
			}
			else {
				sum2 += a[i];
			}
		}
		if (sum1 == sum2) {
			printf("YES\n");
			return true;
		}
	}
	else {
		bool success;
		ch[v] = 1;
		success = dfs(v + 1,a,ch);
		if (success) { return true; }
		ch[v] = 0;
		success = dfs(v + 1, a, ch);
		if (success) { return true; }
	}
	return false;
}

int main() {
	scanf_s("%d", &n);
	vector<int> a(n);
	vector<int> ch(n+1, 0);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
	}
	dfs(0, a, ch);
}