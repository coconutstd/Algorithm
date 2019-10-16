/*
 합이같은부분집합

{2, 4, 5, 10, 12, 13} 집합을 두 부분집합으로 나눴을 때 각 부분합이 같은 경우가 있으면 YES 출력

*/

#include <stdio.h>

using namespace std;

int n,a[11],total;

bool flag = false;

void dfs(int v, int sum) {
	if (flag) return;
	if(v == n + 1) {
		if (sum == total - sum) {
			flag = true;
		}
	}
	else {
		dfs(v + 1, sum + a[v]);
		dfs(v + 1, sum);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		total += a[i];
	}
	dfs(1, 0);
	if (flag) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
}