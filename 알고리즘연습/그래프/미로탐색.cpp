#include <iostream>
#include <queue>
using namespace std;

int N,M;
int cnt = 1;
int a[101][101];
int d[101][101];
bool check[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	check[x][y] = true;
	d[x][y] = cnt;
	while (!q.empty()) {
		x = q.front().first; y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k]; int ny = y + dy[k];
			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (a[nx][ny] == 1 && check[nx][ny] == false) {
					q.push(make_pair(nx,ny));
					check[nx][ny] = true;
					d[nx][ny] = d[x][y]+1;
				}
			}
		}
	}
}

int main() {

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	bfs(0, 0);

	printf("%d\n", d[N - 1][M - 1]);


 	return 0;
}