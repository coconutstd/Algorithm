/*
 �ּ� ���
 ����ġ ���� �׷����� �־����� ��,
 ���� 1 ���� n���� ���� �ּ� ����� ���Ͻÿ�
 ������ķ� ��Ÿ�� �� dfs�� ��� ��� ���ϸ� �ּ� ����� cost�� �����Ѵ�.
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