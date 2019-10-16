#include <cstdio>
#include <queue>

using namespace std;

int r, c;
char map[251][251];
bool check[251][251];
const int dx[] = { 1,-1,0,0 };
const int dy[] = { 0,0,1,-1 };
struct info {
	info() {
		sheep = 0, wolf = 0;
	}
	int sheep, wolf;
};

info bfs(pair<int, int> start) {
	info a;
	queue<pair<int, int>> q;
	q.push(make_pair(start.first, start.second));
	if (map[start.first][start.second] == 'o') {
		a.sheep++;
	}
	if (map[start.first][start.second] == 'v') {
		a.wolf++;
	}
	check[start.first][start.second] = true;
	while (!q.empty()) {
		int row = q.front().first; int col = q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int n_r = row + dx[i]; int n_c = col + dy[i];
			if (1 <= n_r && n_r <= r && 1 <= n_c && n_c <= c && !check[n_r][n_c]) {
				if (map[n_r][n_c] != '#') {
					if (map[n_r][n_c] == 'o') {
						a.sheep++;
					}
					if (map[n_r][n_c] == 'v') {
						a.wolf++;
					}
					q.push(make_pair(n_r, n_c));
					check[n_r][n_c] = true;
				}
			}
		}
	}
	return a;
}

int main() {
	scanf_s_s("%d %d", &r, &c);
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			char c; scanf_s_s("%c", &c);
			if (c == '\n') {j--;continue;}
			map[i][j] = c;
		}
	}

	int w_cnt = 0, s_cnt = 0;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (map[i][j] != '#' && !check[i][j]) {
				info a;
				a = bfs(make_pair(i, j));
				if (a.sheep > a.wolf) {
					s_cnt += a.sheep;
				}
				else if (a.sheep = a.wolf) {
					w_cnt += a.wolf;
				}
				else {
					w_cnt += a.wolf;
				}
			}
		}
	}

	printf("%d %d\n", s_cnt, w_cnt);


}