#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
int w, h;
int a[51][51];
int d[51][51];
int dx[8] = { 0,0,1,-1,-1,1,1,-1 };
int dy[8] = { 1,-1,-1,1,-1,1,0,0 };

void bfs(int x, int y, int cnt) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	d[x][y] = cnt;
	while (!q.empty()) {
		x = q.front().first; y = q.front().second;
		q.pop();
		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k]; int ny = y + dy[k];
			if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
				if (a[nx][ny] == 1 && d[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					d[nx][ny] = cnt;
				}
			}
		}
	}
}

int main() {
	while (1) {
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) {
			break;
		}

		memset(a, 0, sizeof(a));
		memset(d, 0, sizeof(d));

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (a[i][j] == 1 && d[i][j] == 0) {
					bfs(i, j, ++cnt);
				}
			}
		}

		printf("%d\n", cnt);

	}

	return 0;
}