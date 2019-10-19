#include <cstdio>
#include <iostream>
#include <memory.h>
using namespace std;

int map[101][101];
int ch[101][101];
const int dx[3] = { 0,0,-1 };
const int dy[3] = {+1,-1,0 };
int ans;

void dfs(int x, int y) {
	int i;
	if (x == 0) {
		ans = y;
		return;
	}
	else {
		ch[x][y] = 1;
		for (i = 0; i < 3; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx <= 99 && ny >= 0 && ny <= 99) {
				if (map[nx][ny] == 1 && ch[nx][ny] == 0) {
					dfs(nx, ny);
					break;
				}
			}
		}
	}


}

int main() {
	for (int test_case = 1; test_case <= 10; test_case++) {
		int t,x,y;
		cin >> t;

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> map[i][j];
				if (map[i][j] == 2) {
					x = i;
					y = j;
				}
			}
		}

		dfs(x, y);
		cout << "#" << t << " " << ans << "\n";
		memset(ch, 0, sizeof(ch));
	}
}