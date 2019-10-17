/*
 방향 배열을 두고, 2차원 배열 qu[][] 을 정의 한것이 포인트
*/
#include <cstdio>
#include <cstring>
const int d[8][2] = {
	{-1,0},
	{-1,1},
	{0,1},
	{1,1},
	{1,0},
	{1,-1},
	{0,-1},
	{-1,-1}
};

int map[9][9];
int n, m;

int main() {
	int t;
	scanf("%d", &t);
	for (int test_case = 1; test_case <= t; test_case++) {

		scanf("%d %d", &n, &m);
		if (n == 0) { printf("#%d %d %d\n", test_case, 0, 0); continue; }
		if (m == 0) { printf("#%d %d %d\n", test_case, 2, 2); continue; }
		int x = n / 2;
		map[x + 1][x + 1] = map[x][x] = 2;
		map[x + 1][x] = map[x][x + 1] = 1;
		int qu[9][2];
		for (int i = 0, a, b, c; i < m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			map[a][b] = c;
			for (int j = 0, flag, sz; j < 8; j++) {
				sz = flag = 0;
				int nx = a + d[j][0];
				int ny = b + d[j][1];
				while (1 <= nx && nx <= n && 1 <= ny && ny <= n) {
					if (map[nx][ny] == 0) break;
					if (map[nx][ny] == c) {
						flag = 1;
						break;
					}
					else {
						qu[sz][0] = nx;
						qu[sz++][1] = ny;
						nx += d[j][0];
						ny += d[j][1];
					}
				}
				if (flag) {
					for (int k = 0; k < sz; k++) {
						map[qu[k][0]][qu[k][1]] = c;
					}
				}
			}
		}

		int black = 0, white = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				black += (map[i][j] == 1) ? 1 : 0;
				white += (map[i][j] == 2) ? 1 : 0;
			}
		}
		printf("#%d %d %d\n", test_case, black, white);

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				map[i][j] = 0;
			}
		}
	}
}