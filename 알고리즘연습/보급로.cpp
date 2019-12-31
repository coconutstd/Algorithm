#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int map[101][101];
int min_val = 2100000000;
int n;
int route;
int max_route;
int dx[4] = { 0,0,-1,+1 };
int dy[4] = { -1,+1,0,0 };
void dfs(int cost, int x, int y, int route) {
	if (route > max_route) return;
	if (x == n - 1 && y == n - 1) {
		if (min_val > cost) {
			min_val = cost;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			dfs(cost + map[nx][ny], nx, ny, route + 1);
		}

	}

}


int main() {
	int test_case;
	scanf("%d", &test_case);
	for (int t = 1; t <= test_case; t++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%1d", &map[i][j]);
			}
		}
		max_route = 2 * n - 2;
		dfs(0, 0, 0, 0);
		printf("#%d %d\n", t, min_val);
	}

}