#include <iostream>
#include <queue>
using namespace std;
int n,cnt;
int x, y;
int a[26][26];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int d[26][26];

void bfs(int x, int y, int cnt) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	d[x][y] = cnt;
	while (!q.empty()) {
		x = q.front().first; y = q.front()
	}
}

int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	return 0;
}