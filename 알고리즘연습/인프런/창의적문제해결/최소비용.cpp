/*
 최소 비용
 가중치 방향 그래프가 주어졌을 때,
 정점 1 에서 n까지 가는 최소 비용을 구하시오
 인접행렬로 나타낸 후 dfs로 모든 경로 구하며 최소 비용을 cost에 저장한다.
*/

#include <stdio.h>

int map[30][30], ch[30], n,m, cost = 987654321;

void dfs(int v, int sum) {
	if (v == n) {
		if (cost > sum) {
			cost = sum;
		}
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (map[v][i] > 0 && ch[i] == 0) {
				ch[i] = 1;
				dfs(i, sum + map[v][i]);
				ch[i] = 0;
			}
		}
	}
}

int main() {
	scanf_s("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf_s("%d %d %d", &a, &b, &c);
		map[a][b] = c;
	}
	ch[1] = 1;
	dfs(1, 0);
	printf("%d\n", cost);
}