#include <iostream>
#include <memory.h>
using namespace std;

int cnt;
bool check[51][51];
int map[51][51];
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

int T, M, N, K;

void dfs(pair<int, int> start) {
	int x = start.first; int y = start.second;
	check[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i]; int ny = y + dy[i];
		if (0 > nx || nx > N-1 || 0 > ny || ny > M-1) continue;
		if (!check[nx][ny] && map[nx][ny] == 1) {
			dfs(make_pair(nx, ny));
		}
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		memset(map, 0, sizeof(map));
		memset(check, 0, sizeof(check));
		scanf("%d %d %d", &M, &N, &K);
		for (int i = 0; i < K; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			map[y][x] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}

		printf("\n");
		

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!check[i][j] && map[i][j] == 1) {
					dfs(make_pair(i, j));
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
		cnt = 0;
	}
}